#include "zamowienie.h"
#include "ui_zamowienie.h"

Zamowienie::Zamowienie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Zamowienie)
{
    ui->setupUi(this);
    ui->pushButton_dodajZamowienie->setEnabled(false);
    ui->spinBox_iloscPizzy->setRange(0,99);
    ui->spinBox_iloscPrzystawki->setRange(0,99);
    ui->spinBox_iloscDodatki->setRange(0,99);
    ui->spinBox_iloscNapoje->setRange(0,99);
    ui->radioButton_cala->setChecked(true);
    stolikDwuOsobowy = {":/img/img/2osobowy.png"};
    stolikCzteroOsobowy = {":/img/img/4osobowy.png"};
    stolikSzczescioOsobowy = {":/img/img/6osobowy.png"};
    calaPizza = {":/img/img/pizzaCala.png"};
    polowyPizza = {":/img/img/pizzaPolowy.png"};
    ui->label_pizzaCala->setPixmap(calaPizza.scaled(150,150,Qt::KeepAspectRatio));
    ui->label_pizzaPolowa->setPixmap(polowyPizza.scaled(150,150,Qt::KeepAspectRatio));
    ui->comboBox_rodzajPizzyDrugaPolowa->setEnabled(false);
    ktoreMiejsceNaLiscie = 0;
}

Zamowienie::~Zamowienie()
{
    delete ui;
}

void Zamowienie::aktualizujSumeZamowienia()
{
    ui->label_sumaZamowienia->setText(QString::number(sumaZamowienia) + " zl");
}

void Zamowienie::ktoryStolikWyswietl()
{
    if(iloscMiejscKopia > 5)
    {
        ui->label_wyswietlWybranyStolik->setPixmap(stolikSzczescioOsobowy.scaled(300,300,Qt::KeepAspectRatio));
    } else if (iloscMiejscKopia > 3 )
    {
        ui->label_wyswietlWybranyStolik->setPixmap(stolikCzteroOsobowy.scaled(300,300,Qt::KeepAspectRatio));
    } else
    ui->label_wyswietlWybranyStolik->setPixmap(stolikDwuOsobowy.scaled(300,300,Qt::KeepAspectRatio));
}

void Zamowienie::on_pushButton_cofnij_clicked()
{
    resetujZamowienie();
    wylaczanieKontrolekComboBox();
    close();
}

void Zamowienie::dodajDoRachunkuWybraneNapoje()
{
    QString nazwaProduktu = ui->comboBox_rodzajeNapoje->currentText();
    int iloscSztuk = ui->spinBox_iloscNapoje->value();
    QSqlQuery query;
    query.prepare("SELECT cena FROM napoje WHERE nazwa_napoju = :nazwa;");
    query.bindValue(":nazwa", nazwaProduktu);
    if (query.exec() && query.next()) {
        double cena = query.value(0).toDouble();
        double cenaCalosci = cena * iloscSztuk;
        produkty << nazwaProduktu;
        iloscDanegoProduktu[ktoreMiejsceNaLiscie] = iloscSztuk;
        cenaDanychProduktow[ktoreMiejsceNaLiscie] = cenaCalosci;
        sumaZamowienia += cenaCalosci;
        ktoreMiejsceNaLiscie++;
        ui->listWidget_rachunek->addItem(QString("%1 - ilość: %2, cena: %3 zł").arg(nazwaProduktu).arg(iloscSztuk).arg(cenaCalosci));
        aktualizujSumeZamowienia();
    } else {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
    }
}

void Zamowienie::dodajDoRachunkuWybraneDodatki()
{
    QString nazwaProduktu = ui->comboBox_rodzajeDodatkow->currentText();
    int iloscSztuk = ui->spinBox_iloscDodatki->value();
    QSqlQuery query;
    query.prepare("SELECT cena FROM dodatki WHERE nazwa_dodatku = :nazwa;");
    query.bindValue(":nazwa", nazwaProduktu);
    if (query.exec() && query.next()) {
        double cena = query.value(0).toDouble();
        double cenaCalosci = cena * iloscSztuk;
        produkty << nazwaProduktu;
        iloscDanegoProduktu[ktoreMiejsceNaLiscie] = iloscSztuk;
        cenaDanychProduktow[ktoreMiejsceNaLiscie] = cenaCalosci;
        sumaZamowienia += cenaCalosci;
        ktoreMiejsceNaLiscie++;
        ui->listWidget_rachunek->addItem(QString("%1 - ilość: %2, cena: %3 zł").arg(nazwaProduktu).arg(iloscSztuk).arg(cenaCalosci));
        aktualizujSumeZamowienia();
    } else {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
    }
    query.prepare("SELECT czas_przygotowania FROM dodatki WHERE nazwa_dodatku = :nazwa;");
    query.bindValue(":nazwa", nazwaProduktu);
    if (query.exec() && query.next()) {
        double czas = query.value(0).toDouble();
        czasPrzygotowania[ktoreMiejsceNaLiscie - 1] = czas;
        aktualizujCzasPrzygotowania();
    } else {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
    }
}

void Zamowienie::aktualizujCzasPrzygotowania()
{
    int najwyzszyCzasPrzygotowaniaZamowienia = czasPrzygotowania[0];
    for(int licznik = 1;licznik < MAKS_ROZMIAR_ILOSCI;licznik++)
    {
        if(najwyzszyCzasPrzygotowaniaZamowienia < czasPrzygotowania[licznik])
        najwyzszyCzasPrzygotowaniaZamowienia = czasPrzygotowania[licznik];
    }
    ui->label_czasOczekiwania->setText(QString::number(najwyzszyCzasPrzygotowaniaZamowienia) + " minut");
}

void Zamowienie::ustawPizzeComboBox()
{
    QSqlQuery query(m_kopiaStolika->getDataBase());
    if (query.exec("SELECT nazwa_pizzcy FROM pizze;")) {
        while (query.next()) {
            QString nazwaProduktu = query.value(0).toString();
            ui->comboBox_rodzajPizzyDrugaPolowa->addItem(nazwaProduktu);
            ui->comboBox_rodzajPizzyPolowaLubCala->addItem(nazwaProduktu);
        }
    } else {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
    }
}

void Zamowienie::ustawianieComboBoxDodatkiNapojePrzystawki()
{
    QSqlQuery query(m_kopiaStolika->getDataBase());
    if (query.exec("SELECT nazwa_napoju FROM napoje;")) {
        while (query.next()) {
            QString nazwaProduktu = query.value(0).toString();
            ui->comboBox_rodzajeNapoje->addItem(nazwaProduktu);
        }
    } else {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
    }
    if (query.exec("SELECT nazwa_dodatku FROM dodatki;")) {
        while (query.next()) {
            QString nazwaProduktu = query.value(0).toString();
            ui->comboBox_rodzajeDodatkow->addItem(nazwaProduktu);
        }
    } else {
        qDebug() << "Błąd wykonania zapytania:" << query.lastError().text();
    }
}


void Zamowienie::on_pushButton_sumujZamowienie_clicked()
{
    aktualizujSumeZamowienia();
    aktualizujCzasPrzygotowania();
    ui->pushButton_dodajZamowienie->setEnabled(true);
}


void Zamowienie::on_pushButton_dodajZamowienie_clicked()
{
    ui->pushButton_dodajZamowienie->setEnabled(false);
    int nibySuma = 0;
    int czasOczekiwania = 0;
    ui->label_sumaZamowienia->setText(QString::number(nibySuma) + " zl");
    ui->label_czasOczekiwania->setText(QString::number(czasOczekiwania) + " minut");
    m_kopiaStolika->czyWolny[ktoryStolik] = false;
    close();
}


void Zamowienie::on_pushButton_dodajNapoje_clicked()
{
    dodajDoRachunkuWybraneNapoje();
}


void Zamowienie::on_pushButton_usunProdukt_clicked()
{
    QListWidgetItem *selectedItem = ui->listWidget_rachunek->currentItem();
    if (selectedItem) {
        sumaZamowienia -= cenaDanychProduktow[ui->listWidget_rachunek->currentIndex().row()];
        cenaDanychProduktow[ui->listWidget_rachunek->currentIndex().row()] = 0;
        czasPrzygotowania[ui->listWidget_rachunek->currentIndex().row()] = 0;
        ktoreMiejsceNaLiscie--;
        ui->listWidget_rachunek->takeItem(ui->listWidget_rachunek->row(selectedItem));
        aktualizujSumeZamowienia();
        aktualizujCzasPrzygotowania();
        delete selectedItem;
    } else {
        qDebug() << "Nie wybrano elementu do usunięcia.";
    }

}


void Zamowienie::on_pushButton_dodajDodatki_clicked()
{
    dodajDoRachunkuWybraneDodatki();
}

void Zamowienie::resetujZamowienie()
{
    for (int i = 0; i < MAKS_ROZMIAR_ILOSCI; ++i) {
        iloscDanegoProduktu[i] = 0;
        cenaDanychProduktow[i] = 0.0;
        czasPrzygotowania[i] = 0;
    }
    ui->listWidget_rachunek->clear();
    produkty.clear();
    sumaZamowienia = 0;
    aktualizujCzasPrzygotowania();
    aktualizujSumeZamowienia();
}

void Zamowienie::wylaczanieKontrolekComboBox()
{
    ui->comboBox_rodzajPrzystawki->clear();
    ui->comboBox_rodzajeDodatkow->clear();
    ui->comboBox_rodzajeNapoje->clear();
    ui->comboBox_rodzajPizzyPolowaLubCala->clear();
    ui->comboBox_rodzajPizzyDrugaPolowa->clear();
}


void Zamowienie::on_pushButton_resetujZamowienie_clicked()
{
    resetujZamowienie();
}


void Zamowienie::on_radioButton_polowy_clicked()
{
    ui->comboBox_rodzajPizzyDrugaPolowa->setEnabled(true);
}


void Zamowienie::on_radioButton_cala_clicked()
{
    ui->comboBox_rodzajPizzyDrugaPolowa->setEnabled(false);
}


#include "dodawaniestolika.h"
#include "qsqlquery.h"
#include "ui_dodawaniestolika.h"

DodawanieStolika::DodawanieStolika(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DodawanieStolika)
{
    ui->setupUi(this);

}

DodawanieStolika::~DodawanieStolika()
{
    delete ui;
}

QString DodawanieStolika::getKtoryStolik() const
{

    return m_ktoryStolik;
}

int DodawanieStolika::getIloscMiejsc() const
{
    return liczbaKrzesel.toInt();
}

void DodawanieStolika::zablokujQComboBox()
{
    ui->comboBox_wyborIlosciMiejsc->setEnabled(false);
}

void DodawanieStolika::ustawianieCheckBox()
{
        for(int licznik = 1;licznik <= ILOSC_CHECK_BOXOW;licznik++)
        {
            QString nazwaCheckBoxa = QString("checkBox_miejsce%1").arg(licznik);
            QCheckBox *checkBox = findChild<QCheckBox*>(nazwaCheckBoxa);
            if(!czyDodawanie)
            {
                if(m_kopiaCzyWolny[licznik - 1])
                    checkBox->setEnabled(true);
                else checkBox->setEnabled(false);
            } else
            {
                if(!m_kopiaCzyWolny[licznik - 1])
                    checkBox->setEnabled(true);
                else checkBox->setEnabled(false);
            }
        }
}


void DodawanieStolika::on_buttonBox_potwierdzenieDodania_accepted()
{
    int liczbaZaznaczonych = 0;
    for (int licznik = 1; licznik <= ILOSC_CHECK_BOXOW; ++licznik) {
        QString nazwaCheckBoxa = QString("checkBox_miejsce%1").arg(licznik);
        QCheckBox *checkBox = findChild<QCheckBox*>(nazwaCheckBoxa);
        if (checkBox && checkBox->isChecked()) {
            liczbaZaznaczonych++;
            aktywneCheckBoxy[licznik - 1] = true;
        }
    }
    liczbaKrzesel = ui->comboBox_wyborIlosciMiejsc->currentText();
    if(!ui->comboBox_wyborIlosciMiejsc->isEnabled())
    {
        QSqlQuery query(*m_bazaDanych);
        query.prepare("SELECT ilosc_w_magazynie FROM stolik WHERE stolik_ilosc_miejsc = :nazwa");
        query.bindValue(":nazwa", liczbaKrzesel);
        int liczbaWolnychStolikow = query.value(0).toInt();
        int nowaLiczbaWolnychStolikow = liczbaWolnychStolikow + liczbaZaznaczonych;
        query.clear();
        query.prepare("SELECT ilosc_w_restauracji FROM stolik WHERE stolik_ilosc_miejsc = :nazwa");
        query.bindValue(":nazwa", liczbaKrzesel);
        query.exec();
        query.next();
        int liczbaZajetychStolikow = query.value(0).toInt();
        int nowaLiczbaZajetychStolikow = liczbaZajetychStolikow - liczbaZaznaczonych;
        query.clear();
        query.prepare("UPDATE stolik SET ilosc_w_magazynie = :nowaLiczbaWolnych, ilosc_w_restauracji = :nowaLiczbaZajetych WHERE stolik_ilosc_miejsc = :nazwa");
        query.bindValue(":nowaLiczbaWolnych", nowaLiczbaWolnychStolikow);
        query.bindValue(":nowaLiczbaZajetych", nowaLiczbaZajetychStolikow);
        query.bindValue(":nazwa", liczbaKrzesel);
        query.exec();
        liczbaKrzesel = "0";
    }
    if(getIloscMiejsc() > 0)
    {
        QSqlQuery query(*m_bazaDanych);
        query.prepare("SELECT ilosc_w_magazynie FROM stolik WHERE stolik_ilosc_miejsc = :nazwa");
        query.bindValue(":nazwa", liczbaKrzesel);
        if (query.exec() && query.next()) {
            int liczbaWolnychStolikow = query.value(0).toInt();// wciagam ile jest wolnych
            if (liczbaZaznaczonych <= liczbaWolnychStolikow) {
                int nowaLiczbaWolnychStolikow = liczbaWolnychStolikow - liczbaZaznaczonych;
                query.clear();
                query.prepare("SELECT ilosc_w_restauracji FROM stolik WHERE stolik_ilosc_miejsc = :nazwa");
                query.bindValue(":nazwa", liczbaKrzesel);
                query.exec();
                query.next();
                int liczbaZajetychStolikow = query.value(0).toInt();
                int nowaLiczbaZajetychStolikow = liczbaZajetychStolikow + liczbaZaznaczonych;
                query.clear();
                query.prepare("UPDATE stolik SET ilosc_w_magazynie = :nowaLiczbaWolnych, ilosc_w_restauracji = :nowaLiczbaZajetych WHERE stolik_ilosc_miejsc = :nazwa");
                query.bindValue(":nowaLiczbaWolnych", nowaLiczbaWolnychStolikow);
                query.bindValue(":nowaLiczbaZajetych", nowaLiczbaZajetychStolikow);
                query.bindValue(":nazwa", liczbaKrzesel);
                query.exec();
            } else {
                liczbaKrzesel = 0;
                QMessageBox::warning(this, "Uwaga", "Niestety, nie ma tyle stolikow w magazynie.");
            }
        }
    }
}



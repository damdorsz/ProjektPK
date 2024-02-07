#include "wyborstolika.h"
#include "ui_wyborstolika.h"

wyborStolika::wyborStolika(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wyborStolika)
{
    ui->setupUi(this);
    stolikDwuOsobowy = {":/img/img/2osobowy.png"};
    stolikCzteroOsobowy = {":/img/img/4osobowy.png"};
    stolikSzczescioOsobowy = {":/img/img/6osobowy.png"};
    kwiatek = {":/img/img/kwiat.png"};
    widthLogo = 250;
    heightLogo = 250;
    ustawWstepnie();
    m_zamowienie = new Zamowienie(this);
}

void wyborStolika::ustawWstepnie()
{
    for(int licznik = 1,maksimum = m_kopiaStolika->ILOSC_STOLIKOW;licznik <= maksimum;licznik++)
    {
        QString nazwaPushButton = QString("pushButton_%1").arg(licznik);
        QPushButton *pushButton = findChild<QPushButton*>(nazwaPushButton);
        pushButton->setEnabled(false);
    }
}

wyborStolika::~wyborStolika()
{
    delete ui;
}

void wyborStolika::ladowanieWyboruStolika()
{
    for(int licznik = 1,maksimum = m_kopiaStolika->ILOSC_STOLIKOW;licznik <= maksimum;licznik++)
    {
        QString nazwaLabela = QString("label_stolik%1").arg(licznik);
        QLabel *labelAddImg = findChild<QLabel*>(nazwaLabela);
        QString nazwaLabelaWolny = QString("label_czyWolny%1").arg(licznik);
        QLabel *labelWolny = findChild<QLabel*>(nazwaLabelaWolny);
        QString nazwaPushButton = QString("pushButton_%1").arg(licznik);
        QPushButton *pushButton = findChild<QPushButton*>(nazwaPushButton);
        if(m_kopiaStolika->czyIstnieje[licznik - 1])
        {
            if(m_kopiaStolika->czyWolny[licznik - 1])
            {
                labelWolny->setText("Wolny");
                pushButton->setEnabled(true);
                if(m_kopiaStolika->iloscKrzesel[licznik - 1] == 2)
                {
                    labelAddImg->setPixmap(stolikDwuOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                }
                else if(m_kopiaStolika->iloscKrzesel[licznik - 1] == 4)
                {
                    labelAddImg->setPixmap(stolikCzteroOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                }
                else if(m_kopiaStolika->iloscKrzesel[licznik - 1] == 6)
                {
                    labelAddImg->setPixmap(stolikSzczescioOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                }
                else{
                    labelWolny->setText("Zajety");
                    pushButton->setEnabled(false);
                }
            }
        } else
        {
            labelWolny->setText("brak");
            pushButton->setEnabled(false);
            labelAddImg->setPixmap(kwiatek.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        }

}
}


void wyborStolika::on_pushButton_clicked()
{
    close();
}

void wyborStolika::on_pushButton_1_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[0];
    m_zamowienie->ktoryStolik = 0;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[0] == false)
    {
        ui->label_czyWolny1->setText("Zajety");
        ui->pushButton_1->setEnabled(false);
    }
}


void wyborStolika::on_pushButton_2_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[1];
    m_zamowienie->ktoryStolik = 1;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[1] == false)
    {
        ui->label_czyWolny2->setText("Zajety");
        ui->pushButton_2->setEnabled(false);

    }
}


void wyborStolika::on_pushButton_3_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[2];
    m_zamowienie->ktoryStolik = 2;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[2] == false)
    {
        ui->label_czyWolny3->setText("Zajety");
        ui->pushButton_3->setEnabled(false);

    }
}


void wyborStolika::on_pushButton_4_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[3];
    m_zamowienie->ktoryStolik = 3;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[3] == false)
    {
        ui->label_czyWolny4->setText("Zajety");
        ui->pushButton_4->setEnabled(false);

    }
}


void wyborStolika::on_pushButton_5_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[4];
    m_zamowienie->ktoryStolik = 4;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[4] == false)
    {
        ui->label_czyWolny5->setText("Zajety");
        ui->pushButton_5->setEnabled(false);

    }
}


void wyborStolika::on_pushButton_6_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[5];
    m_zamowienie->ktoryStolik = 5;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[5] == false)
    {
        ui->label_czyWolny6->setText("Zajety");
        ui->pushButton_6->setEnabled(false);

    }
}


void wyborStolika::on_pushButton_7_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[6];
    m_zamowienie->ktoryStolik = 6;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[6] == false)
    {
        ui->label_czyWolny7->setText("Zajety");
        ui->pushButton_7->setEnabled(false);

    }
}


void wyborStolika::on_pushButton_8_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[7];
    m_zamowienie->ktoryStolik = 7;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[7] == false)
    {
        ui->label_czyWolny8->setText("Zajety");
        ui->pushButton_8->setEnabled(false);

    }
}


void wyborStolika::on_pushButton_9_clicked()
{
    m_zamowienie->m_kopiaStolika = m_kopiaStolika;
    m_zamowienie->iloscMiejscKopia = m_kopiaStolika->iloscKrzesel[8];
    m_zamowienie->ktoryStolik = 8;
    m_zamowienie->ktoryStolikWyswietl();
    m_zamowienie->ustawianieComboBoxDodatkiNapojePrzystawki();
    m_zamowienie->ustawPizzeComboBox();
    m_zamowienie->exec();
    if(m_kopiaStolika->czyWolny[8] == false)
    {
        ui->label_czyWolny9->setText("Zajety");
        ui->pushButton_9->setEnabled(false);

    }
}


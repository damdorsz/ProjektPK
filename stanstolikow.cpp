#include "stanstolikow.h"
#include "ui_stanstolikow.h"

StanStolikow::StanStolikow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StanStolikow)
{
    ui->setupUi(this);
    stolikDwuOsobowy = {":/img/img/2osobowy.png"};
    stolikCzteroOsobowy = {":/img/img/4osobowy.png"};
    stolikSzczescioOsobowy = {":/img/img/6osobowy.png"};
    kwiatek = {":/img/img/kwiat.png"};
    widthLogo = 250;
    heightLogo = 250;
    ustawWstepnie();
}

StanStolikow::~StanStolikow()
{
    delete ui;
}

void StanStolikow::on_pushButton_cofnij_clicked()
{
    close();
}

void StanStolikow::ustawWstepnie()
{
    for(int licznik = 1,maksimum = m_kopiaStolika->ILOSC_STOLIKOW;licznik <= maksimum;licznik++)
    {
        QString nazwaCheckBoxa = QString("checkBox_%1").arg(licznik);
        QCheckBox *checkBox = findChild<QCheckBox*>(nazwaCheckBoxa);
        checkBox->setEnabled(false);
    }
}

void StanStolikow::ladowanieWyboruStolika()
{
    for(int licznik = 1,maksimum = m_kopiaStolika->ILOSC_STOLIKOW;licznik <= maksimum;licznik++)
    {
        QString nazwaLabela = QString("label_stolik%1").arg(licznik);
        QLabel *labelAddImg = findChild<QLabel*>(nazwaLabela);
        QString nazwaLabelaWolny = QString("label_czyWolny%1").arg(licznik);
        QLabel *labelWolny = findChild<QLabel*>(nazwaLabelaWolny);
        QString nazwaKwota = QString("label_kwota1_%1").arg(licznik);
        QLabel *labelKwota = findChild<QLabel*>(nazwaKwota);
        QString nazwaCheckBoxa = QString("checkBox_%1").arg(licznik);
        QCheckBox *checkBox = findChild<QCheckBox*>(nazwaCheckBoxa);
        if(m_kopiaStolika->czyIstnieje[licznik - 1])
        {
            if(m_kopiaStolika->czyWolny[licznik - 1])
            {
                labelWolny->setText("Wolny");
                checkBox->setEnabled(false);
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
            }
            else
            {
                int tempKwota = 30;
                labelWolny->setText("Zajety");
                checkBox->setEnabled(true);
                labelKwota->setText(QString::number(tempKwota));
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
            }
        }else
        {
            labelWolny->setText("brak");
            checkBox->setEnabled(false);
            labelAddImg->setPixmap(kwiatek.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        }
    }
}


void StanStolikow::on_pushButton_zwolnij_clicked()
{
    for(int licznik = 1,maksimum = m_kopiaStolika->ILOSC_STOLIKOW;licznik <= maksimum;licznik++)
    {
        QString nazwaLabelaWolny = QString("label_czyWolny%1").arg(licznik);
        QLabel *labelWolny = findChild<QLabel*>(nazwaLabelaWolny);
        QString nazwaKwota = QString("label_kwota1_%1").arg(licznik);
        QLabel *labelKwota = findChild<QLabel*>(nazwaKwota);
        QString nazwaCheckBoxa = QString("checkBox_%1").arg(licznik);
        QCheckBox *checkBox = findChild<QCheckBox*>(nazwaCheckBoxa);
        if (checkBox && checkBox->isChecked()){
            m_kopiaStolika->czyWolny[licznik - 1] = true;
            m_kopiaStolika->m_czasOczekiwania[licznik - 1] = 0;
            m_kopiaStolika->m_kwotaZamowienia[licznik - 1] = 0;
            labelWolny->setText("Wolny");
            checkBox->setEnabled(false);
            labelKwota->setText(QString::number(m_kopiaStolika->m_kwotaZamowienia[licznik - 1]));
        }
    }
}


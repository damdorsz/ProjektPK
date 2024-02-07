#include "stolik.h"
#include "ui_stolik.h"
#include <QMessageBox>


Stolik::Stolik(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Stolik)
{
    ui->setupUi(this);
    stolikDwuOsobowy = {":/img/img/2osobowy.png"};
    stolikCzteroOsobowy = {":/img/img/4osobowy.png"};
    stolikSzczescioOsobowy = {":/img/img/6osobowy.png"};
    kwiat = {":/img/img/kwiat.png"};
    widthLogo = 250;
    heightLogo = 250;
    dodanieDomyslnychObrazkow();
}

void Stolik::setDataBase(QSqlDatabase *db)
{
    m_db = db;
}

QSqlDatabase Stolik::getDataBase()
{
    return *m_db;
}

Stolik::~Stolik()
{
    delete ui;
}

void Stolik::on_pushButton_cofnij_clicked()
{
    close();
}

void Stolik::dodanieDomyslnychObrazkow()
{
    for (int licznik = 1; licznik <= m_nowyStolik->ILOSC_CHECK_BOXOW; ++licznik) {
        QString nazwaLabela = QString("label_miejsce%1").arg(licznik);
        QLabel *labelAddImg = findChild<QLabel*>(nazwaLabela);
        labelAddImg->setPixmap(kwiat.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyIstnieje[licznik - 1] = false;
    }
}

void Stolik::on_pushButton_dodajStolik_clicked()
{
    m_nowyStolik = new DodawanieStolika(this);
    m_nowyStolik->m_bazaDanych = m_db;
    m_nowyStolik->m_kopiaCzyWolny = czyWolny;
    m_nowyStolik->czyDodawanie = true;
    m_nowyStolik->ustawianieCheckBox();
    m_nowyStolik->exec();
    for (int licznik = 1; licznik <= m_nowyStolik->ILOSC_CHECK_BOXOW; ++licznik) {
        QString nazwaLabela = QString("label_miejsce%1").arg(licznik);
        QLabel *labelAddImg = findChild<QLabel*>(nazwaLabela);
        if (m_nowyStolik->aktywneCheckBoxy[licznik - 1] == true) {
            if(m_nowyStolik->getIloscMiejsc() == 2)
            {
                labelAddImg->setPixmap(stolikDwuOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                czyWolny[licznik - 1] = true;
                iloscKrzesel[licznik - 1] = 2;
                czyIstnieje[licznik - 1] = true;
            }
            else if(m_nowyStolik->getIloscMiejsc() == 4)
            {
                labelAddImg->setPixmap(stolikCzteroOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                czyWolny[licznik - 1] = true;
                iloscKrzesel[licznik - 1] = 4;
                czyIstnieje[licznik - 1] = true;
            }
            else if (m_nowyStolik->getIloscMiejsc() == 6)
            {
                labelAddImg->setPixmap(stolikSzczescioOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                czyWolny[licznik - 1] = true;
                iloscKrzesel[licznik - 1] = 6;
                czyIstnieje[licznik - 1] = true;
            }
            m_nowyStolik->aktywneCheckBoxy[licznik - 1] = false;
        }
    }
    delete m_nowyStolik;
}

void Stolik::on_pushButton_usunStolik_clicked()
{
    m_nowyStolik = new DodawanieStolika(this);
    m_nowyStolik->m_bazaDanych = m_db;
    m_nowyStolik->m_kopiaCzyWolny = czyWolny;
    m_nowyStolik->czyDodawanie = false;
    m_nowyStolik->m_kopiailoscKrzesel = iloscKrzesel;
    m_nowyStolik->ustawianieCheckBox();
    m_nowyStolik->zmianaIndexuComboBox();
    m_nowyStolik->exec();
    for(int licznik = 1;licznik <= ILOSC_STOLIKOW;licznik++)
    {
        QString nazwaLabela = QString("label_miejsce%1").arg(licznik);
        QLabel *labelAddImg = findChild<QLabel*>(nazwaLabela);
        if(m_nowyStolik->aktywneCheckBoxy[licznik - 1] == true)
        {
            czyWolny[licznik - 1] = false;
            iloscKrzesel[licznik - 1] = 0;
            czyIstnieje[licznik - 1] = false;
            labelAddImg->setPixmap(kwiat.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        }
    }
    delete m_nowyStolik;
}


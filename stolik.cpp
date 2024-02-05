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
    widthLogo = ui->label_stolik1->width();
    heightLogo = ui->label_stolik1->height();
    ui->label_stolik1->setPixmap(kwiat.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
    ui->label_stolik2->setPixmap(kwiat.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
    ui->label_stolik3->setPixmap(kwiat.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
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



void Stolik::on_pushButton_dodajStolik_clicked()
{
    m_nowyStolik = new DodawanieStolika(this);
    m_nowyStolik->exec();
    QStringList listaStolikow = {"Pierwszy","Drugi","Trzeci"};
    QString dodawanyStolik = m_nowyStolik->getKtoryStolik();
    const int iloscOpcjiKtoryStolik = 3;
    int opcjaDodaniaStolika;
    for(int licznik = 0;licznik < iloscOpcjiKtoryStolik;licznik++)
    {
        if(dodawanyStolik == listaStolikow[licznik])
        {
            opcjaDodaniaStolika = licznik;
            if("2 Miejsca" == m_nowyStolik->getIloscMiejsc())
            {

            }
            else if("4 Miejsca" == m_nowyStolik->getIloscMiejsc())
            {
                opcjaDodaniaStolika += 10;
            }
            else if("6 Miejsc" == m_nowyStolik->getIloscMiejsc())
            {
                opcjaDodaniaStolika += 20;
            }
        }
    }
    switch(opcjaDodaniaStolika)
    {
    case 0:
        ui->label_stolik1->setPixmap(stolikDwuOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[0] = true;
        iloscKrzesel[0] = 2;
        czyIstnieje[0] = true;
        break;
    case 1:
        ui->label_stolik2->setPixmap(stolikDwuOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[1] = true;
        iloscKrzesel[1] = 2;
        czyIstnieje[1] = true;
        break;
    case 2:
        ui->label_stolik3->setPixmap(stolikDwuOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[2] = true;
        iloscKrzesel[2] = 2;
        czyIstnieje[2] = true;
        break;
    case 10:
        ui->label_stolik1->setPixmap(stolikCzteroOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[0] = true;
        iloscKrzesel[0] = 4;
        czyIstnieje[0] = true;
        break;
    case 11:
        ui->label_stolik2->setPixmap(stolikCzteroOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[1] = true;
        iloscKrzesel[1] = 4;
        czyIstnieje[1] = true;
        break;
    case 12:
        ui->label_stolik3->setPixmap(stolikCzteroOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[2] = true;
        iloscKrzesel[2] = 4;
        czyIstnieje[2] = true;
        break;
    case 20:
        ui->label_stolik1->setPixmap(stolikSzczescioOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[0] = true;
        iloscKrzesel[0] = 6;
        czyIstnieje[0] = true;
        break;
    case 21:
        ui->label_stolik2->setPixmap(stolikSzczescioOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[1] = true;
        iloscKrzesel[1] = 6;
        czyIstnieje[1] = true;
        break;
    case 22:
        ui->label_stolik3->setPixmap(stolikSzczescioOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        czyWolny[2] = true;
        iloscKrzesel[2] = 6;
        czyIstnieje[2] = true;
        break;
    default:
        break;
    }
    delete m_nowyStolik;
}




void Stolik::on_pushButton_usunStolik_clicked()
{
    m_nowyStolik = new DodawanieStolika(this);
    m_nowyStolik->zablokujQComboBox();
    m_nowyStolik->exec();
    QStringList listaStolikow = {"Pierwszy","Drugi","Trzeci"};
    QString dodawanyStolik = m_nowyStolik->getKtoryStolik();
    const int iloscOpcjiKtoryStolik = 3;
    for(int licznik = 0;licznik < iloscOpcjiKtoryStolik;licznik++)
    {
        if(dodawanyStolik == listaStolikow[licznik])
        {
            czyWolny[licznik] = false;
            iloscKrzesel[licznik] = 0;
            czyIstnieje[licznik] = false;
            if(dodawanyStolik == listaStolikow[0])
            {
                 ui->label_stolik1->setPixmap(kwiat.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
            } else if(dodawanyStolik == listaStolikow[1])
            {
                 ui->label_stolik2->setPixmap(kwiat.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));

            }else if(dodawanyStolik == listaStolikow[2])
            {
                 ui->label_stolik3->setPixmap(kwiat.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
            }
        }
    }
}


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
    widthLogo = ui->label_stolik1->width();
    heightLogo = ui->label_stolik1->height();
    ui->pushButton_wybierzStolik1->setEnabled(false);
    ui->pushButton_wybierzStolik2->setEnabled(false);
    ui->pushButton_wybierzStolik3->setEnabled(false);
    m_zamowienie = new Zamowienie(this);
}

wyborStolika::~wyborStolika()
{
    delete ui;
}

void wyborStolika::ladowanieWyboruStolika()
{
        if(m_kopiaStolika->czyIstnieje[0])
        {
        if(m_kopiaStolika->czyWolny[0])
        {
            ui->label_czyWolny1->setText("Wolny");
            ui->pushButton_wybierzStolik1->setEnabled(true);
            if(m_kopiaStolika->iloscKrzesel[0] == 2)
            {
                ui->label_stolik1->setPixmap(stolikDwuOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
            }
            else if(m_kopiaStolika->iloscKrzesel[0] == 4)
            {
                ui->label_stolik1->setPixmap(stolikCzteroOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
            }
            else if(m_kopiaStolika->iloscKrzesel[0] == 6)
            {
                ui->label_stolik1->setPixmap(stolikSzczescioOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
            }
            else{
                ui->label_czyWolny1->setText("Zajety");
                ui->pushButton_wybierzStolik1->setEnabled(false);
            }
        }
        } else
            {
                ui->label_czyWolny1->setText("brak");
                ui->pushButton_wybierzStolik1->setEnabled(false);
                ui->label_stolik1->setPixmap(kwiatek.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
            }
        if(m_kopiaStolika->czyIstnieje[1])
            {
                if(m_kopiaStolika->czyWolny[1])
                {
                    ui->label_czyWolny2->setText("Wolny");
                    ui->pushButton_wybierzStolik2->setEnabled(true);
                    if(m_kopiaStolika->iloscKrzesel[1] == 2)
                    {
                        ui->label_stolik1_2->setPixmap(stolikDwuOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                    }
                    else if(m_kopiaStolika->iloscKrzesel[1] == 4)
                    {
                        ui->label_stolik1_2->setPixmap(stolikCzteroOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                    }
                    else if(m_kopiaStolika->iloscKrzesel[1] == 6)
                    {
                        ui->label_stolik1_2->setPixmap(stolikSzczescioOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                    }
                }
                else{
                    ui->label_czyWolny2->setText("Zajety");
                    ui->pushButton_wybierzStolik2->setEnabled(false);
                }
        }else
        {
            ui->label_czyWolny2->setText("brak");
            ui->pushButton_wybierzStolik2->setEnabled(false);
            ui->label_stolik1_2->setPixmap(kwiatek.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        }
        if(m_kopiaStolika->czyIstnieje[2])
        {
            if(m_kopiaStolika->czyWolny[2])
            {
                ui->label_czyWolny3->setText("Wolny");
                ui->pushButton_wybierzStolik3->setEnabled(true);
                if(m_kopiaStolika->iloscKrzesel[2] == 2)
                {
                    ui->label_stolik1_3->setPixmap(stolikDwuOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                }
                else if(m_kopiaStolika->iloscKrzesel[2] == 4)
                {
                    ui->label_stolik1_3->setPixmap(stolikCzteroOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                }
                else if(m_kopiaStolika->iloscKrzesel[2] == 6)
                {
                    ui->label_stolik1_3->setPixmap(stolikSzczescioOsobowy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
                }
            }
            else{
                ui->label_czyWolny3->setText("Zajety");
                ui->pushButton_wybierzStolik3->setEnabled(false);
            }
        }else
        {
            ui->label_czyWolny3->setText("brak");
            ui->pushButton_wybierzStolik3->setEnabled(false);
            ui->label_stolik1_3->setPixmap(kwiatek.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
        }
}

void wyborStolika::on_pushButton_clicked()
{
    close();
}


void wyborStolika::on_pushButton_wybierzStolik1_clicked()
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
        ui->pushButton_wybierzStolik1->setEnabled(false);
        close();
    }
}


void wyborStolika::on_pushButton_wybierzStolik2_clicked()
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
        ui->label_czyWolny1->setText("Zajety");
        ui->pushButton_wybierzStolik1->setEnabled(false);
        close();
    }
}


void wyborStolika::on_pushButton_wybierzStolik3_clicked()
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
        ui->label_czyWolny1->setText("Zajety");
        ui->pushButton_wybierzStolik1->setEnabled(false);
        close();
    }

}


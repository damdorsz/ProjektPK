#include "stanstolikow.h"
#include "ui_stanstolikow.h"

StanStolikow::StanStolikow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StanStolikow)
{
    ui->setupUi(this);
    ui->pushButton_ZwolnijStolik1->setEnabled(false);
    ui->pushButton_zwolnijStolik2->setEnabled(false);
    ui->pushButton_zwolnijStolik3->setEnabled(false);
    stolikDwuOsobowy = {":/img/img/2osobowy.png"};
    stolikCzteroOsobowy = {":/img/img/4osobowy.png"};
    stolikSzczescioOsobowy = {":/img/img/6osobowy.png"};
    kwiatek = {":/img/img/kwiat.png"};
    widthLogo = ui->label_stolik1->width();
    heightLogo = ui->label_stolik1->height();
}

StanStolikow::~StanStolikow()
{
    delete ui;
}

void StanStolikow::on_pushButton_2_clicked()
{
    close();
}

void StanStolikow::ladowanieWyboruStolika()
{
    if(m_kopiaStolika->czyIstnieje[0])
    {
        if(m_kopiaStolika->czyWolny[0])
        {
            ui->label_czyWolny1->setText("Wolny");
            ui->pushButton_ZwolnijStolik1->setEnabled(false);
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
        }
        else
        {
            int tempKwota = 30;
            ui->label_czyWolny1->setText("Zajety");
            ui->pushButton_ZwolnijStolik1->setEnabled(true);
            ui->label_kwota1->setText(QString::number(tempKwota));
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
        }
    }else
    {
        ui->label_czyWolny1->setText("brak");
        ui->pushButton_ZwolnijStolik1->setEnabled(false);
        ui->label_stolik1->setPixmap(kwiatek.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
    }
    if(m_kopiaStolika->czyIstnieje[1])
    {
        if(m_kopiaStolika->czyWolny[1])
        {
            ui->label_czyWolny2->setText("Wolny");
            ui->pushButton_zwolnijStolik2->setEnabled(false);
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
        else
        {
            int tempKwota = 30;
            ui->label_czyWolny2->setText("Zajety");
            ui->pushButton_zwolnijStolik2->setEnabled(true);
            ui->label_kwota1_2->setText(QString::number(tempKwota));
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
    }
    else
    {
        ui->label_czyWolny2->setText("brak");
        ui->pushButton_zwolnijStolik2->setEnabled(false);
        ui->label_stolik1_2->setPixmap(kwiatek.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
    }
    if(m_kopiaStolika->czyIstnieje[2])
    {
        if(m_kopiaStolika->czyWolny[2])
        {
            ui->label_czyWolny3->setText("Wolny");
            ui->pushButton_zwolnijStolik3->setEnabled(false);
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
        else
        {
            int tempKwota = 30;
            ui->label_czyWolny3->setText("Zajety");
            ui->pushButton_zwolnijStolik3->setEnabled(true);
            ui->label_kwota1_3->setText(QString::number(tempKwota));
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
    }else
    {
        ui->label_czyWolny3->setText("brak");
        ui->pushButton_zwolnijStolik3->setEnabled(false);
        ui->label_stolik1_3->setPixmap(kwiatek.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
    }
}

void StanStolikow::on_pushButton_ZwolnijStolik1_clicked()
{
    int stolikNr = 0,reset =0;
    m_kopiaStolika->czyWolny[stolikNr] = true;
    m_kopiaStolika->m_czasOczekiwania[stolikNr] = reset;
    m_kopiaStolika->m_kwotaZamowienia[stolikNr] = reset;
    ui->label_czyWolny1->setText("Wolny");
    ui->pushButton_ZwolnijStolik1->setEnabled(false);
    ui->label_kwota1->setText(QString::number(m_kopiaStolika->m_kwotaZamowienia[stolikNr]));
}


void StanStolikow::on_pushButton_zwolnijStolik2_clicked()
{
    int stolikNr = 1,reset =0;
    m_kopiaStolika->czyWolny[stolikNr] = true;
    m_kopiaStolika->m_czasOczekiwania[stolikNr] = reset;
    m_kopiaStolika->m_kwotaZamowienia[stolikNr] = reset;
    ui->label_czyWolny2->setText("Wolny");
    ui->pushButton_zwolnijStolik2->setEnabled(false);
    ui->label_kwota1_2->setText(QString::number(m_kopiaStolika->m_kwotaZamowienia[stolikNr]));
}


void StanStolikow::on_pushButton_zwolnijStolik3_clicked()
{
    int stolikNr = 2,reset =0;
    m_kopiaStolika->czyWolny[stolikNr] = true;
    m_kopiaStolika->m_czasOczekiwania[stolikNr] = reset;
    m_kopiaStolika->m_kwotaZamowienia[stolikNr] = reset;
    ui->label_czyWolny3->setText("Wolny");
    ui->pushButton_zwolnijStolik3->setEnabled(false);
    ui->label_kwota1_3->setText(QString::number(m_kopiaStolika->m_kwotaZamowienia[stolikNr]));
}


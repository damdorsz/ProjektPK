#include "logowanie.h"
#include "ui_logowanie.h"
#include <QMessageBox>

Logowanie::Logowanie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Logowanie)
{
    ui->setupUi(this);

}

Logowanie::~Logowanie()
{
    delete ui;
}



void Logowanie::on_pushButton_logowanie_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    if(login == "admin" && password == "admin")
    {
        ui->lineEdit_login->clear();
        ui->lineEdit_password->clear();
        close();
    }
    else
    {
        QMessageBox::information(this,"Błąd logowania","Zły Login lub haslo");
    }
}



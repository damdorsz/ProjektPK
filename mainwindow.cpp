#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logoFirmy = {":/img/img/logoFirmy.png"};
    widthLogo = 300;
    heightLogo = 300;
    m_logowanie = new Logowanie(this);
    m_stolik = new Stolik(this);
    m_zamowienie = new Zamowienie(this);
    m_wyborStolika = new wyborStolika(this);
    m_stanStolikow = new StanStolikow(this);
    m_logowanie->exec();
    ui->label_logoFirmy->setPixmap(logoFirmy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_wylogowanie_clicked()
{
    m_logowanie->exec();
}

void MainWindow::on_pushButton_rozbudujRestauracje_clicked()
{
    m_stolik->exec();
}

void MainWindow::on_pushButton_wyborStolika_clicked()
{
    m_wyborStolika->m_kopiaStolika = m_stolik;
    m_wyborStolika->ladowanieWyboruStolika();
    m_wyborStolika->exec();
}


void MainWindow::on_pushButton_stanStolikow_clicked()
{
    m_stanStolikow->m_kopiaStolika = m_stolik;
    m_stanStolikow->ladowanieWyboruStolika();
    m_stanStolikow->exec();
}


#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    logoFirmy = {":/img/img/logoFirmy.png"};
    widthLogo = 300;
    heightLogo = 300;
    m_stolik = new Stolik(this);
    m_zamowienie = new Zamowienie(this);
    m_wyborStolika = new wyborStolika(this);
    m_stanStolikow = new StanStolikow(this);
    ui->label_logoFirmy->setPixmap(logoFirmy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));
}

MainMenu::~MainMenu()
{
    delete m_stolik;
    delete m_zamowienie;
    delete m_wyborStolika;
    delete m_stanStolikow;
    delete ui;
}

Stolik *MainMenu::getStolik()
{
    return m_stolik;
}

void MainMenu::on_pushButton_wylogowanie_clicked()
{
    close();
}

void MainMenu::on_pushButton_rozbudujRestauracje_clicked()
{
    m_stolik->exec();
}

void MainMenu::on_pushButton_wyborStolika_clicked()
{
    m_wyborStolika->m_kopiaStolika = m_stolik;
    m_wyborStolika->ladowanieWyboruStolika();
    m_wyborStolika->exec();
}


void MainMenu::on_pushButton_stanStolikow_clicked()
{
    m_stanStolikow->m_kopiaStolika = m_stolik;
    m_stanStolikow->ladowanieWyboruStolika();
    m_stanStolikow->exec();
}




#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_mainmenu = new MainMenu(this);
    m_mainmenu->setWindowTitle("Table Manager");
    logoFirmy = {":/img/img/logoFirmy.png"};
    widthLogo = 300;
    heightLogo = 300;
    ui->label_logo->setPixmap(logoFirmy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));

    qDebug() << "Driver List: " << QSqlDatabase::drivers();
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL"));
    db->setDatabaseName("projktqtzaliczenie");
    db->setHostName("127.0.0.1");
    db->setPort(3310);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_logowanie_clicked()
{
    ui->lineEdit_login->setText("admin");
    ui->lineEdit_password->setText("admin");
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    db->setPassword(password);
    db->setUserName(login);
    if(db->open())
    {
        ui->lineEdit_login->clear();
        ui->lineEdit_password->clear();
        qDebug() << "Is opened";
        hide();
        m_mainmenu->getStolik()->setDataBase(db);
        m_mainmenu->exec();
        show();
    }
    else
    {
        qDebug() << "ERROR load: " << db->lastError().text();
        QMessageBox::information(this,"Błąd logowania","Zły Login lub haslo");
    }
}


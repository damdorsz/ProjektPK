#ifndef STOLIK_H
#define STOLIK_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QPixmap>
#include "dodawaniestolika.h"
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <mysql.h>

namespace Ui {
class Stolik;
}

class Stolik : public QDialog
{
    Q_OBJECT

public:
    explicit Stolik(QWidget *parent = nullptr);
    ~Stolik();

    QPixmap stolikDwuOsobowy;
    QPixmap stolikCzteroOsobowy;
    QPixmap stolikSzczescioOsobowy;
    QPixmap kwiat;
    int heightLogo;
    int widthLogo;

    static const int ILOSC_STOLIKOW = 9;
    int m_kwotaZamowienia [ILOSC_STOLIKOW] = {};
    int m_czasOczekiwania [ILOSC_STOLIKOW] = {};
    bool czyWolny [ILOSC_STOLIKOW] = {};
    int iloscKrzesel [ILOSC_STOLIKOW] = {};
    bool czyIstnieje [ILOSC_STOLIKOW];

    void setDataBase(QSqlDatabase *db);
    QSqlDatabase getDataBase();

    void dodanieDomyslnychObrazkow();

private slots:
    void on_pushButton_cofnij_clicked();

    void on_pushButton_dodajStolik_clicked();

    void on_pushButton_usunStolik_clicked();

private:
    Ui::Stolik *ui;
    DodawanieStolika *m_nowyStolik;
    QSqlDatabase *m_db;
};

#endif // STOLIK_H

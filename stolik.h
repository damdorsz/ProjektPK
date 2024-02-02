#ifndef STOLIK_H
#define STOLIK_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QPixmap>
#include "dodawaniestolika.h"

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
    static const int iloscStolikow = 3;
    int m_kwotaZamowienia [iloscStolikow] = {0,0,0};
    int m_czasOczekiwania [iloscStolikow] = {0,0,0};
    bool czyWolny [iloscStolikow] = {true,true,true};
    int iloscKrzesel [iloscStolikow] = {0,0,0};
    bool czyIstnieje [iloscStolikow] = {false,false,false};


private slots:
    void on_pushButton_cofnij_clicked();

    void on_pushButton_dodajStolik_clicked();

    void on_pushButton_usunStolik_clicked();

private:
    Ui::Stolik *ui;
    DodawanieStolika *m_nowyStolik;
};

#endif // STOLIK_H

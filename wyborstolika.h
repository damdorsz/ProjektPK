#ifndef WYBORSTOLIKA_H
#define WYBORSTOLIKA_H

#include <QDialog>
#include <QMessageBox>
#include "stolik.h"
#include "zamowienie.h"

namespace Ui {
class wyborStolika;
}

class wyborStolika : public QDialog
{
    Q_OBJECT

public:
    explicit wyborStolika(QWidget *parent = nullptr);
    ~wyborStolika();

    QPixmap stolikDwuOsobowy;
    QPixmap stolikCzteroOsobowy;
    QPixmap stolikSzczescioOsobowy;
    QPixmap kwiatek;
    int heightLogo;
    int widthLogo;

    Stolik *m_kopiaStolika;

    void ladowanieWyboruStolika();
    void ustawWstepnie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::wyborStolika *ui;
    Zamowienie *m_zamowienie;
};

#endif // WYBORSTOLIKA_H

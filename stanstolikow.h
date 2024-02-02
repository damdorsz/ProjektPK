#ifndef STANSTOLIKOW_H
#define STANSTOLIKOW_H

#include <QDialog>
#include "stolik.h"

namespace Ui {
class StanStolikow;
}

class StanStolikow : public QDialog
{
    Q_OBJECT

public:
    explicit StanStolikow(QWidget *parent = nullptr);
    ~StanStolikow();
    Stolik *m_kopiaStolika;
    void ladowanieWyboruStolika();
    QPixmap stolikDwuOsobowy;
    QPixmap stolikCzteroOsobowy;
    QPixmap stolikSzczescioOsobowy;
    QPixmap kwiatek;
    int heightLogo;
    int widthLogo;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_ZwolnijStolik1_clicked();

    void on_pushButton_zwolnijStolik2_clicked();

    void on_pushButton_zwolnijStolik3_clicked();

private:
    Ui::StanStolikow *ui;
};

#endif // STANSTOLIKOW_H

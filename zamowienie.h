#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include <QDialog>
#include "stolik.h"

namespace Ui {
class Zamowienie;
}

class Zamowienie : public QDialog
{
    Q_OBJECT

public:
    explicit Zamowienie(QWidget *parent = nullptr);
    ~Zamowienie();

    void ustawianiePodIloscMiejsc();
    void resetPodIloscMiejsc();
    Stolik *m_kopiaStolika;
    int iloscMiejscKopia;
    int ktoryStolik;

private slots:
    void on_pushButton_cofnij_clicked();

    void on_pushButton_sumujZamowienie_clicked();

    void on_pushButton_dodajZamowienie_clicked();

private:
    Ui::Zamowienie *ui;
};

#endif // ZAMOWIENIE_H

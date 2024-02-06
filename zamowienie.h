#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include <QDialog>
#include "stolik.h"
#include <QMessageBox>

namespace Ui {
class Zamowienie;
}

class Zamowienie : public QDialog
{
    Q_OBJECT

public:
    explicit Zamowienie(QWidget *parent = nullptr);
    ~Zamowienie();

    void ustawianieComboBoxDodatkiNapojePrzystawki();
    void ktoryStolikWyswietl();
    void ustawPizzeComboBox();
    void dodajDoRachunkuWybraneNapoje();
    void aktualizujSumeZamowienia();
    void dodajDoRachunkuWybraneDodatki();
    void aktualizujCzasPrzygotowania();
    void resetujZamowienie();
    void wylaczanieKontrolekComboBox();

    Stolik *m_kopiaStolika;
    int iloscMiejscKopia;
    int ktoryStolik;

    QPixmap stolikDwuOsobowy;
    QPixmap stolikCzteroOsobowy;
    QPixmap stolikSzczescioOsobowy;
    QPixmap calaPizza;
    QPixmap polowyPizza;
    int heightLogo;
    int widthLogo;

    int ktoreMiejsceNaLiscie;

private slots:
    void on_pushButton_cofnij_clicked();

    void on_pushButton_sumujZamowienie_clicked();

    void on_pushButton_dodajZamowienie_clicked();

    void on_pushButton_dodajNapoje_clicked();

    void on_pushButton_usunProdukt_clicked();

    void on_pushButton_dodajDodatki_clicked();

    void on_pushButton_resetujZamowienie_clicked();

    void on_radioButton_polowy_clicked();

    void on_radioButton_cala_clicked();

    void on_pushButton_dodajPizze_clicked();

    void on_pushButton_dodajPrzystawki_clicked();

    void on_pushButton_dodajRabat_clicked();

private:
    Ui::Zamowienie *ui;

    double sumaZamowienia = 0;
    QStringList produkty;
    static const int MAKS_ROZMIAR_ILOSCI = 20;
    int iloscDanegoProduktu [MAKS_ROZMIAR_ILOSCI] ={};
    double cenaDanychProduktow [MAKS_ROZMIAR_ILOSCI] = {};
    int czasPrzygotowania [MAKS_ROZMIAR_ILOSCI] = {} ;
};

#endif // ZAMOWIENIE_H

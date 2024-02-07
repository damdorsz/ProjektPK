#ifndef DODAWANIESTOLIKA_H
#define DODAWANIESTOLIKA_H

#include "qsqldatabase.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DodawanieStolika;
}

class DodawanieStolika : public QDialog
{
    Q_OBJECT

public:
    explicit DodawanieStolika(QWidget *parent = nullptr);
    ~DodawanieStolika();

    QSqlDatabase *m_bazaDanych;
    static const int ILOSC_CHECK_BOXOW = 9;
    bool aktywneCheckBoxy[ILOSC_CHECK_BOXOW];
    bool czyDodawanie;
    bool *m_kopiaCzyWolny;
    int *m_kopiailoscKrzesel;

    int getIloscMiejsc() const;
    void ustawianieCheckBox();
    void zmianaIndexuComboBox();

private slots:

    void on_buttonBox_potwierdzenieDodania_accepted();

private:

    Ui::DodawanieStolika *ui;
    QString liczbaKrzesel;
    QString m_ktoryStolik;
};

#endif // DODAWANIESTOLIKA_H

#ifndef DODAWANIESTOLIKA_H
#define DODAWANIESTOLIKA_H

#include <QDialog>

namespace Ui {
class DodawanieStolika;
}

class DodawanieStolika : public QDialog
{
    Q_OBJECT

public:
    explicit DodawanieStolika(QWidget *parent = nullptr);
    ~DodawanieStolika();

    QString getKtoryStolik() const;
    QString getIloscMiejsc() const;
    void zablokujQComboBox();

private slots:

    void on_buttonBox_potwierdzenieDodania_accepted();

private:
    Ui::DodawanieStolika *ui;
    QString m_ktoryStolik;
};

#endif // DODAWANIESTOLIKA_H

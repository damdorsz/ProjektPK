#include "dodawaniestolika.h"
#include "ui_dodawaniestolika.h"

DodawanieStolika::DodawanieStolika(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DodawanieStolika)
{
    ui->setupUi(this);
}

DodawanieStolika::~DodawanieStolika()
{
    delete ui;
}

QString DodawanieStolika::getKtoryStolik() const
{

    return m_ktoryStolik;
}

QString DodawanieStolika::getIloscMiejsc() const
{
    return ui->comboBox_wyborIlosciMiejsc->currentText();
}

void DodawanieStolika::zablokujQComboBox()
{
    ui->comboBox_wyborIlosciMiejsc->setEnabled(false);
}



void DodawanieStolika::on_buttonBox_potwierdzenieDodania_accepted()
{
    if(ui->checkBox_miejsce1->isChecked())
    {
        m_ktoryStolik = "Pierwszy";
    }

}


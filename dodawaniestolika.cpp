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
    return ui->comboBox->currentText();
}

void DodawanieStolika::zablokujQComboBox()
{
    ui->comboBox->setEnabled(false);
}



void DodawanieStolika::on_buttonBox_potwierdzenieDodania_accepted()
{
    if(ui->radioButton_stolik1->isChecked())
    {
        m_ktoryStolik = "Pierwszy";
    }
    else if(ui->radioButton_stolik2->isChecked())
    {
        m_ktoryStolik = "Drugi";
    }
    else if(ui->radioButton_stolik3->isChecked())
    {
        m_ktoryStolik = "Trzeci";
    }
}


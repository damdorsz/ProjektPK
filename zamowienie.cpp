#include "zamowienie.h"
#include "ui_zamowienie.h"

Zamowienie::Zamowienie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Zamowienie)
{
    ui->setupUi(this);
    ui->pushButton_dodajZamowienie->setEnabled(false);
}

Zamowienie::~Zamowienie()
{
    delete ui;
}

void Zamowienie::on_pushButton_cofnij_clicked()
{
    close();
}

void Zamowienie::resetPodIloscMiejsc()
{

    ui->comboBox_napojMiejsceNr1_6->setEnabled(true);
    ui->comboBox_napojMiejsceNr1_5->setEnabled(true);
    ui->comboBox_pizzaMiejsceNr1_5->setEnabled(true);
    ui->comboBox_pizzaMiejsceNr1_6->setEnabled(true);
    ui->comboBox_przystawkaMiejsceNr1_5->setEnabled(true);
    ui->comboBox_przystawkaMiejsceNr1_6->setEnabled(true);
    ui->comboBox_napojMiejsceNr1_4->setEnabled(true);
    ui->comboBox_napojMiejsceNr1_3->setEnabled(true);
    ui->comboBox_pizzaMiejsceNr1_3->setEnabled(true);
    ui->comboBox_pizzaMiejsceNr1_4->setEnabled(true);
    ui->comboBox_przystawkaMiejsceNr1_3->setEnabled(true);
    ui->comboBox_przystawkaMiejsceNr1_4->setEnabled(true);
}

void Zamowienie::ustawianiePodIloscMiejsc()
{
    if(iloscMiejscKopia < 5)
    {
        ui->comboBox_napojMiejsceNr1_6->setEnabled(false);
        ui->comboBox_napojMiejsceNr1_5->setEnabled(false);
        ui->comboBox_pizzaMiejsceNr1_5->setEnabled(false);
        ui->comboBox_pizzaMiejsceNr1_6->setEnabled(false);
        ui->comboBox_przystawkaMiejsceNr1_5->setEnabled(false);
        ui->comboBox_przystawkaMiejsceNr1_6->setEnabled(false);
    }
    if(iloscMiejscKopia < 3)
    {
        ui->comboBox_napojMiejsceNr1_4->setEnabled(false);
        ui->comboBox_napojMiejsceNr1_3->setEnabled(false);
        ui->comboBox_pizzaMiejsceNr1_3->setEnabled(false);
        ui->comboBox_pizzaMiejsceNr1_4->setEnabled(false);
        ui->comboBox_przystawkaMiejsceNr1_3->setEnabled(false);
        ui->comboBox_przystawkaMiejsceNr1_4->setEnabled(false);
    }
}


void Zamowienie::on_pushButton_sumujZamowienie_clicked()
{
    int nibySuma = 10;
    int czasOczekiwania = 30;
    ui->label_sumaZamowienia->setText(QString::number(nibySuma));
    ui->label_czasOczekiwania->setText(QString::number(czasOczekiwania) + " minut");
    ui->pushButton_dodajZamowienie->setEnabled(true);
}


void Zamowienie::on_pushButton_dodajZamowienie_clicked()
{
    ui->pushButton_dodajZamowienie->setEnabled(false);
    int nibySuma = 0;
    int czasOczekiwania = 0;
    ui->label_sumaZamowienia->setText(QString::number(nibySuma) + " zl");
    ui->label_czasOczekiwania->setText(QString::number(czasOczekiwania) + " minut");
    m_kopiaStolika->czyWolny[ktoryStolik] = false;
    close();
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logowanie.h"
#include "stolik.h"
#include "zamowienie.h"
#include "wyborstolika.h"
#include "stanstolikow.h"
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPixmap logoFirmy;
    int heightLogo;
    int widthLogo;

private slots:
    void on_pushButton_wylogowanie_clicked();

    void on_pushButton_rozbudujRestauracje_clicked();

    void on_pushButton_wyborStolika_clicked();

    void on_pushButton_stanStolikow_clicked();

private:
    Ui::MainWindow *ui;
    Logowanie *m_logowanie;
    Stolik * m_stolik;
    Zamowienie * m_zamowienie;
    wyborStolika *m_wyborStolika;
    StanStolikow *m_stanStolikow;
};
#endif // MAINWINDOW_H

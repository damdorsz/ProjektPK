#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "stolik.h"
#include "zamowienie.h"
#include "wyborstolika.h"
#include "stanstolikow.h"
#include <QPixmap>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    QPixmap logoFirmy;
    int heightLogo;
    int widthLogo;
    Stolik * getStolik();


private slots:
    void on_pushButton_wylogowanie_clicked();

    void on_pushButton_rozbudujRestauracje_clicked();

    void on_pushButton_wyborStolika_clicked();

    void on_pushButton_stanStolikow_clicked();

private:
    Stolik * m_stolik;
    Zamowienie * m_zamowienie;
    wyborStolika *m_wyborStolika;
    StanStolikow *m_stanStolikow;
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H

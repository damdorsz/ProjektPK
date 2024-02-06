#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "mainmenu.h"

#include <QDebug>
#include <QStringList>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <mysql.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    void readRecordsToListWidget();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPixmap logoFirmy;
    int heightLogo;
    int widthLogo;
private slots:
    void on_pushButton_logowanie_clicked();


private:
    Ui::MainWindow *ui;
    MainMenu *m_mainmenu;
    QSqlDatabase *db;

};
#endif // MAINWINDOW_H

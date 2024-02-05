#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_mainmenu = new MainMenu(this);
    m_mainmenu->setWindowTitle("Table Manager");
    logoFirmy = {":/img/img/logoFirmy.png"};
    widthLogo = 300;
    heightLogo = 300;
    ui->label_logo->setPixmap(logoFirmy.scaled(widthLogo,heightLogo,Qt::KeepAspectRatio));

    qDebug() << "Driver List: " << QSqlDatabase::drivers();
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL"));
    db->setDatabaseName("pk_proj");
    db->setHostName("127.0.0.1");
    db->setPort(3310);
}

// void MainWindow::readRecordsToListWidget(){
//     QSqlQuery query(*db) ; // tworzę obiekt zapytania i podpinam go pod otwartą bazę danych
//     ui->records->clear(); // usuwam wszystkie elementy kontrolki
//     if(query.exec("SELECT id, title, author FROM books")){ // wysyłam zapytanie do bazy danych
//         while(query.next()){ // jeżeli są jakieś wyniki to
//             // wstawiam rekord do kontrolki QListWidget
//             ui->records->addItem(new QListWidgetItem(query.value(0).toString() + " \apos" + query.value(1).toString() + "\apos " + query.value(2).toString(), ui->records));
//         }
//     }else{
//         qDebug() << query.lastError().text(); // wyświetlam w konsoli Qt Creatora informację błędu, gdy zapytanie zakończy się niepowodzeniem
//     }
// }

// void MainWindow::on_btAdd_clicked() // dodawanie elementu do bazy danych
// {
//     // sprawdzanie, czy kontrolki edAuthor i edTitle nie zawierają niedozwolonych znaków
//     if(ui->edAuthor->text().indexOf("\apos") != -1){
//         ui->edAuthor->setText( ui->edAuthor->text().replace("\apos", "") );
//         QMessageBox::information(this, "Ostrzeżenie", "Pole autora książki zawierało niedozwolony znak \apos, który został usunięty");
//     }
//     if(ui->edTitle->text().indexOf("\apos") != -1){
//         ui->edTitle->setText( ui->edTitle->text().replace("\apos", "") );
//         QMessageBox::information(this, "Ostrzeżenie", "Pole tytułu książki zawierało niedozwolony znak \apos, który został usunięty");
//     }

//     if(ui->edAuthor->text().size() && ui->edTitle->text().size()){ // jeżeli pola tekstowe nie są puste to
//         QSqlQuery query(*db); // tworzę obiekt zapytania
//         // przygotowuję zapytanie SQL, sprawdzające, czy w bazie danych jest już książka o podanym tytule i autorze
//         query.prepare("SELECT title, author FROM books WHERE title = :title AND author = :author LIMIT 1;");
//         // podpinam pod nie dane
//         query.bindValue(":title", QVariant::fromValue(ui->edTitle->text())); // tekst z kontrolki edTitle zostanie oddzielnie wysłany a następnie wstawiony do zapytania za :title
//         query.bindValue(":author", QVariant::fromValue(ui->edAuthor->text())); // to samo co powyżej

//         if(
//             query.exec() && (!query.next() // jak zapytanie zakończyło się powodzeniem i zwróciło element lub użytkownik postanowił dodać zduplikowany rekord to
//                              ||
//                              QMessageBox::warning( // jeżeli
//                                  this,
//                                  "Ostrzeżenie",
//                                  "Autor i tytuł już istnieje na liście, czy chcesz"
//                                  " mimo to dodać tę pozycję ponownie?",
//                                  QMessageBox::Yes | QMessageBox::No
//                                  ) == QMessageBox::Yes)){
//             // przygotowuję nowe zapytanie
//             query.prepare("INSERT INTO books (title, author) VALUES (:title, :author);");
//             // binduję wartości
//             query.bindValue(":title", QVariant::fromValue(ui->edTitle->text()));
//             query.bindValue(":author", QVariant::fromValue(ui->edAuthor->text()));
//             // wykonuję zapytanie
//             if(query.exec()){
//                 readRecordsToListWidget(); // i jeżeli zakończy się ono powodzeniem to odświerzam listę rekordów
//             }
//         }
//     }
// }

// void MainWindow::on_records_doubleClicked(const QModelIndex &index) // zdarzenie kliknięcia dwukrotnego w oknie kontrolki
// {
//     QString recordData = index.data().toString();
//     QStringList record = recordData.split(" \apos");
//     QStringList record2 = record[1].split("\apos ");
//     record.removeAt(1);
//     record += record2;
//     if(record.size() == 3){
//         ui->edTitle->setText(record[1]); // wczytuję rekord do kontrolki tytułu
//         ui->edAuthor->setText(record[2]); // wczytuję rekord do kontrolki autora
//     }
// }

// void MainWindow::on_btRemove_clicked() // zdarzenie kliknięcia przycisku usunięcia zaznaczonego elementu
// {
//     if(ui->records->currentItem()){
//         QString recordData = ui->records->currentItem()->data(Qt::DisplayRole).toString();
//         QStringList record = recordData.split(" \apos");

//         bool ok = false;
//         int index = record[0].toInt(&ok);

//         if(ok){
//             QSqlQuery query(*db);

//             query.prepare("DELETE FROM books WHERE id = :id;"); // zapytanie usuwające wybrany rekord

//             query.bindValue(":id", index);

//             if(query.exec()){
//                 readRecordsToListWidget();
//             }else{
//                 qDebug() << query.lastError();
//             }
//         }
//     }
// }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_logowanie_clicked()
{
    ui->lineEdit_login->setText("pracownik2");
    ui->lineEdit_password->setText("alamakota");
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    db->setPassword(password);
    db->setUserName(login);
    if(db->open())
    {
        ui->lineEdit_login->clear();
        ui->lineEdit_password->clear();
        qDebug() << "Is opened";
        hide();
        m_mainmenu->getStolik()->setDataBase(db);
        m_mainmenu->exec();
        show();
    }
    else
    {
        qDebug() << "ERROR load: " << db->lastError().text();
        QMessageBox::information(this,"Błąd logowania","Zły Login lub haslo");
    }
}


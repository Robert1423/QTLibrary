#include <fstream>
#include "library.h"
#include "ui_library.h"
#include "database.h"
#include "bookbase.h"
#include "readerbase.h"

bool isreader=false;
Database database;
BookBase books;
ReaderBase readers;

QItemSelectionModel *select;

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    this->setWindowTitle("Biblioteka");
    this->setFixedSize(QSize(880,600));
    Load(database,this);
    if (database.BooksSize() == 0 && database.ReadersSize() == 0)
        ui->statusbar->showMessage("Pusta baza/Brak bazy", 5000);
    books = database.Books();
    readers = database.Readers();
    on_ShowBooks_released();
}

Library::~Library()
{
    database.Set(books,readers);
    Save(database,this);
    delete ui;
}
void Library::on_AddReader_released()
{
    addReader = new DialogAddReader;
    addReader->show();
}


void Library::on_AddBook_released()
{
    addBook = new DialogAddBook;
    addBook->show();
}


void Library::on_Rent_released()
{
    rent = new DialogRent;
    rent->show();
}


void Library::on_Unrent_released()
{
    finish = new DialogFinishRent;
    finish->show();
}


void Library::on_ShowBooks_released()
{
    //QMessageBox::information(this,"Size",QString::number(books.Size()));
    isreader = false; //ustawienie sterowania obslugi reader/books
    tableViewModel = new QStandardItemModel(ui->data); //tworzenie sterowania tabelą
    ui->data->setModel(tableViewModel); //przypisanie sterowania to TableView
    tableViewModel->setColumnCount(4); //utworzenie liczby kolumn
    tableViewModel->setHorizontalHeaderLabels({"ID","Autor","Tytuł","Ilość"}); //utowrzenie etykiet kolumn
    ui->data->setEditTriggers(QAbstractItemView::NoEditTriggers);//wyłączenie edycji z pozycji tabeli
    ui->data->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->data->setSelectionMode(QAbstractItemView::SingleSelection); // ustawiam możliwość zaznaczania pojedynczego rekordu
    if (books.Size()>0)
        books.ShowBase(tableViewModel);
    else
        //QMessageBox::information(this,"Błąd!", "Baza jest pusta!");
        ui->statusbar->showMessage("Pusta baza", 5000);
    ui->data->resizeColumnsToContents();
}


void Library::on_ShowReaders_released()
{
    isreader = true; //ustawienie sterowania obslugi reader/books
    tableViewModel = new QStandardItemModel(ui->data); //tworzenie sterowania tabelą
    ui->data->setModel(tableViewModel); //przypisanie sterowania to TableView
    tableViewModel->setColumnCount(2); //utworzenie liczby kolumn
    tableViewModel->setHorizontalHeaderLabels({"ID","Imię Nazwisko"}); //utowrzenie etykiet kolumn
    ui->data->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->data->setSelectionMode(QAbstractItemView::SingleSelection); // ustawiam możliwość zaznaczania pojedynczego rekordu
    if (readers.Size()>0)
        readers.ShowBase(tableViewModel);
    else
        ui->statusbar->showMessage("Pusta baza", 5000);
    ui->data->resizeColumnsToContents();
}


void Library::on_Show_released()
{
    if (isreader)
    {
        select = ui->data->selectionModel();
        showReader = new DialogShowReader();
        showReader->show();
    }
    else
    {
        select = ui->data->selectionModel();
        showBook = new DialogShowBook();
        showBook->show();
    }
}


void Library::on_Edit_released()
{
    if (isreader)
    {
        select = ui->data->selectionModel();
        editReader = new DialogEditReader();
        editReader->show();
    }
    else
    {
        select = ui->data->selectionModel();
        editBook = new DialogEditBook();
        editBook->show();
    }
}


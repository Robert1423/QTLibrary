#include "library.h"
#include "ui_library.h"
#include "book.h"
#include "reader.h"

bool isreader=false;

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    this->setWindowTitle("Biblioteka");
    this->setFixedSize(QSize(880,600));
    on_ShowBooks_released();
}

Library::~Library()
{
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
    isreader = false; //ustawienie sterowania obslugi reader/books
    tableViewModel = new QStandardItemModel(ui->data); //tworzenie sterowania tabelą
    ui->data->setModel(tableViewModel); //przypisanie sterowania to TableView
    tableViewModel->setColumnCount(4); //utworzenie liczby kolumn
    tableViewModel->setHorizontalHeaderLabels({"ID","Autor","Tytuł","Ilość"}); //utowrzenie etykiet kolumn
    ui->data->setEditTriggers(QAbstractItemView::NoEditTriggers);//wyłączenie edycji z pozycji tabeli
//    Book example("test","tytul",5,1);
//    example.Display(tableViewModel);
    ui->data->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->data->setSelectionMode(QAbstractItemView::SingleSelection); // ustawiam możliwość zaznaczania pojedynczego rekordu

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
}


void Library::on_Show_released()
{
    if (isreader)
    {
        showReader = new DialogShowReader();
        showReader->show();
    }
    else
    {
        showBook = new DialogShowBook();
        showBook->show();
    }
}


void Library::on_Edit_released()
{
    if (isreader)
    {
        editReader = new DialogEditReader();
        editReader->show();
    }
    else
    {
        editBook = new DialogEditBook();
        editBook->show();
    }
}


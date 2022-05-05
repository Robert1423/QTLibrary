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

QStandardItemModel *tableViewModel;
QItemSelectionModel *select;
QTableView * dataTable;

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(900,600));
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    Load(database,this);
//    books = database.books;
//    readers = database.readers;
    dataTable = ui->data;
    QImage logo;
    logo.load(":/img/Logo.png");
    ui->Logo->setPixmap(QPixmap::fromImage(logo));
    on_ShowBooks_released();
}

Library::~Library()
{
//    database.Set(books,readers);
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
    isreader = false; //ustawienie sterowania obslugi reader/books
    tableViewModel = new QStandardItemModel(ui->data); //tworzenie sterowania tabelą
    ui->data->setModel(tableViewModel); //przypisanie sterowania to TableView
    tableViewModel->setColumnCount(4); //utworzenie liczby kolumn
    tableViewModel->setHorizontalHeaderLabels({"ID","Autor","Tytuł","Ilość"}); //utowrzenie etykiet kolumn
    ui->data->setEditTriggers(QAbstractItemView::NoEditTriggers);//wyłączenie edycji z pozycji tabeli
    ui->data->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->data->setSelectionMode(QAbstractItemView::SingleSelection); // ustawiam możliwość zaznaczania pojedynczego rekordu
    if (database.books.Size()>0)
        database.books.ShowBase(tableViewModel);
    ui->data->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->data->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->data->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->data->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    ui->comboBox->clear();
    ui->comboBox->setPlaceholderText("<sortuj>");
    ui->comboBox->addItem("ID");
    ui->comboBox->addItem("Autor");
    ui->comboBox->addItem("Tytuł");
    ui->comboBox->addItem("Ilość");
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
    if (database.readers.Size()>0)
        database.readers.ShowBase(tableViewModel);
    ui->data->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    ui->data->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->comboBox->clear();
    ui->comboBox->setPlaceholderText("<sortuj>");
    ui->comboBox->addItem("ID");
    ui->comboBox->addItem("Imię Nazwisko");
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

void Library::on_Sort_released()
{
    int i = ui->comboBox->currentIndex();
    tableViewModel->sort(i);
}


void Library::on_Close_released()
{
    this->close();
}


void Library::on_RemoveBook_released()
{
    if (isreader)
    {
        select = ui->data->selectionModel();
        database.readers.RemoveReader(select->currentIndex().row());
        tableViewModel->removeRow(select->currentIndex().row());
    }
    else
    {
        select = ui->data->selectionModel();
        database.books.RemoveBook(select->currentIndex().row());
        tableViewModel->removeRow(select->currentIndex().row());
    }
}


void Library::on_FindBook_released()
{
    vector<int> found;
    QString search = ui->Title->text();
    if (isreader)
    {
        found = database.readers.SearchAll(search);
        tableViewModel->clear();
        for (int i : found)
            database.readers[i].Display(tableViewModel);
        ui->data->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
        ui->data->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    }
    else
    {
        found = books.SearchAll(search);
        tableViewModel->clear();
        for (int i : found)
            database.books[i].Display(tableViewModel);
        ui->data->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
        ui->data->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
        ui->data->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
        ui->data->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    }
}


#include "dialogshowreader.h"
#include "ui_dialogshowreader.h"

DialogShowReader::DialogShowReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowReader)
{
    ui->setupUi(this);
    this->setWindowTitle("Czytelnik");
    rentsTable = new QStandardItemModel(ui->tableView); //tworzenie sterowania tabelą
    ui->tableView->setModel(rentsTable); //przypisanie sterowania to TableView
    rentsTable->setColumnCount(4); //utworzenie liczby kolumn
    rentsTable->setHorizontalHeaderLabels({"Autor","Tytuł","Wypożyczono", "Zwrot"}); //utowrzenie etykiet kolumn
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//wyłączenie edycji z pozycji tabeli
//    Book example("test","tytul",5,1);
//    example.Display(tableViewModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // ustawiam możliwość zaznaczania pojedynczego rekordu
}

DialogShowReader::~DialogShowReader()
{
    delete ui;
}

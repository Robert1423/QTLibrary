#include "dialogshowreader.h"
#include "ui_dialogshowreader.h"
#include "database.h"

extern ReaderBase readers;
extern QItemSelectionModel * select;

DialogShowReader::DialogShowReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowReader)
{
    ui->setupUi(this);
    this->setWindowTitle("Czytelnik");
    rentsTable = new QStandardItemModel(ui->Rents); //tworzenie sterowania tabelą
    ui->Rents->setModel(rentsTable); //przypisanie sterowania to Rents
    rentsTable->setColumnCount(4); //utworzenie liczby kolumn
    rentsTable->setHorizontalHeaderLabels({"Autor","Tytuł","Data wyp.", "Data zwr."}); //utowrzenie etykiet kolumn
    ui->Rents->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->Rents->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    ui->Rents->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);
    ui->Rents->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    ui->Rents->setEditTriggers(QAbstractItemView::NoEditTriggers);//wyłączenie edycji z pozycji tabeli
    ui->Rents->setSelectionBehavior(QAbstractItemView::SelectRows); // ustawiam zaznaczanie całych wierszy
    ui->Rents->setSelectionMode(QAbstractItemView::SingleSelection); // ustawiam możliwość zaznaczania pojedynczego rekordu
    readers[select->currentIndex().row()].Calculate();
    readers[select->currentIndex().row()].Show(ui->ID,ui->Name,ui->Due,rentsTable);
}

DialogShowReader::~DialogShowReader()
{
    delete ui;
}

void DialogShowReader::on_pay_released()
{
    readers[select->currentIndex().row()].Pay(ui->payment->value());
    QMessageBox::information(this,"Wpłata","Łącznie wpłacono: " + QString::number(readers[select->currentIndex().row()].GetPaid())+
                             "\nSuma należności: "+QString::number(readers[select->currentIndex().row()].GetDue()));
    ui->Due->clear();
    ui->Due->setText(QString::number(readers[select->currentIndex().row()].GetDue()));
}


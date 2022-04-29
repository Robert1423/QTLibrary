#include "dialogeditbook.h"
#include "ui_dialogeditbook.h"
#include "bookbase.h"
#include <QHeaderView>

extern BookBase books;
extern QItemSelectionModel * select;
extern QStandardItemModel *tableViewModel;
extern QTableView * dataTable;

DialogEditBook::DialogEditBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditBook)
{
    ui->setupUi(this);
    this->setWindowTitle("Edytuj...");
    ui->ID->setText(books[select->currentIndex().row()].Id());
}

DialogEditBook::~DialogEditBook()
{
    delete ui;
}

void DialogEditBook::on_buttonBox_accepted()
{
    QString test = ui->Author->text();
    if (QString::compare(test,""))
        books[select->currentIndex().row()].EditAuthor(test);
    test = ui->Title->text();
    if (QString::compare(test,""))
        books[select->currentIndex().row()].EditTitle(test);
    int q = ui->Quantity->value();
    if (q>0)
        books[select->currentIndex().row()].EditQuantity(q);
    tableViewModel->clear();
    books.ShowBase(tableViewModel);
    dataTable->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    dataTable->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    dataTable->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
}


#include "dialogeditbook.h"
#include "ui_dialogeditbook.h"
#include "bookbase.h"
#include <QHeaderView>
#include <QFile>
#include <QFileDialog>

extern bool isreader;
extern BookBase books;
extern QItemSelectionModel * select;
extern QStandardItemModel *tableViewModel;
extern QTableView * dataTable;

DialogEditBook::DialogEditBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditBook)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    if (select->hasSelection())
        ui->ID->setText(books[select->currentIndex().row()].Id());
}

DialogEditBook::~DialogEditBook()
{
    delete ui;
}

void DialogEditBook::on_buttonBox_accepted()
{
    if (select->hasSelection())
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
        if (!isreader)
        {
            tableViewModel->clear();
            books.ShowBase(tableViewModel);
            dataTable->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
            dataTable->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
            dataTable->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
            dataTable->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
        }
    }
}


void DialogEditBook::on_pushButton_released()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Wybierz"),"",tr("Images(*.png *.jpg *.jpeg *.nmp *.gif"));

    if (QString::compare(filename,QString())!=0)
    {
        if (select->hasSelection())
        {
            books[select->currentIndex().row()].EditFront(filename);
        }
        ui->Front->setText(filename);
    }
}


#include "dialogrent.h"
#include "ui_dialogrent.h"
#include "database.h"
#include <QHeaderView>

extern bool isreader;
extern Database database;
extern BookBase books;
extern ReaderBase readers;
extern QStandardItemModel *tableViewModel;
extern QTableView * dataTable;

DialogRent::DialogRent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRent)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setModal(true);
}

DialogRent::~DialogRent()
{
    delete ui;
}

void DialogRent::on_buttonBox_accepted()
{
    QString title = ui->Title->text();
    QString reader = ui->Reader->text();
    int b = database.books.Search(title);
    int r = database.readers.Search(reader);
    if ( b >=0 && r >=0)
    {
        if (database.readers[r].CanRent())
        {
            if (database.books[b].IsAvalaible())
            {
                database.books[b].Rent();
                Rent newRent(database.books[b]);
                database.readers[r].AddRent(newRent);
            }
            else
                QMessageBox::information(this,"Błąd!","Brak pozycji na stanie!");
        }
        else
            QMessageBox::information(this,"Błąd!", "Zbyt wysoka kara!");
    }
    else
        QMessageBox::information(this,"Błąd!", "Nie znaleziono podanych danych!");
    if (!isreader)
    {
        tableViewModel->clear();
        tableViewModel->setHorizontalHeaderLabels({"ID","Autor","Tytuł","Ilość"});
        database.books.ShowBase(tableViewModel);
        dataTable->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
        dataTable->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
        dataTable->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
        dataTable->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
    }
}


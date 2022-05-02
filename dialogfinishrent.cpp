#include "dialogfinishrent.h"
#include "ui_dialogfinishrent.h"
#include "database.h"
#include <QHeaderView>

extern BookBase books;
extern ReaderBase readers;
extern QStandardItemModel *tableViewModel;
extern QTableView * dataTable;

DialogFinishRent::DialogFinishRent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFinishRent)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

DialogFinishRent::~DialogFinishRent()
{
    delete ui;
}

void DialogFinishRent::on_buttonBox_accepted()
{
    QString title = ui->Title->text();
    QString reader = ui->Reader->text();
    int b = books.Search(title);
    int r = readers.Search(reader);
    if (b>=0 && r>=0)
    {
        int t = readers[r].SearchRents(title);
        if (t>=0)
        {
            if (readers[r].FromRents(t).CheckBook()==books[b])
            {
                readers[r].Calculate();
                readers[r].FinishRent(t);
                books[b].FinishRent();
                if (readers[r].GetDue()>0)
                    QMessageBox::information(this, "Kara...","Należy opłacić karę!");
            }
            else
                QMessageBox::information(this,"Błąd", "Brak książki w bazie!");
        }
        else
            QMessageBox::information(this,"Błąd", "Brak książki w wypożyczonych!");
    }
    else
        QMessageBox::information(this,"Błąd", "Nie znaleziono!\nBłędne dane!");
    tableViewModel->clear();
    books.ShowBase(tableViewModel);
    dataTable->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
    dataTable->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    dataTable->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    dataTable->horizontalHeader()->setSectionResizeMode(3,QHeaderView::ResizeToContents);
}


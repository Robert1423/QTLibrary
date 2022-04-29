#include "dialogaddbook.h"
#include "ui_dialogaddbook.h"
#include "database.h"
#include "bookbase.h"

extern Database database;
extern BookBase books;
extern QStandardItemModel *tableViewModel;

DialogAddBook::DialogAddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddBook)
{
    ui->setupUi(this);
    this->setWindowTitle("Dodaj książkę...");
}

DialogAddBook::~DialogAddBook()
{
    delete ui;
}

void DialogAddBook::on_buttonBox_accepted()
{

    QString qAuthor = ui->Author->text();
    QString qTitle = ui->Title->text();
    int qQuantity = ui->Number->value();
    if (qQuantity<1)
        QMessageBox::information(this,"Błąd","Błędne dane!\nNie można dodać pozycji");
    else
    {
        Book temp(qAuthor,qTitle,qQuantity,books.Size()+1);
        books.AddBook(temp);
    }
    books[books.Size()-1].Display(tableViewModel);
}


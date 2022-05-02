#include "dialogaddbook.h"
#include "ui_dialogaddbook.h"
#include "database.h"
#include "bookbase.h"
#include <QFile>
#include <QFileDialog>

extern bool isreader;
extern Database database;
extern BookBase books;
extern QStandardItemModel *tableViewModel;
QImage front;
QString filename;

DialogAddBook::DialogAddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddBook)
{
    srand(time(NULL));
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
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
    if (qQuantity<0)
        QMessageBox::information(this,"Błąd","Błędne dane!\nNie można dodać pozycji");
    else
    {
        if (QString::compare(filename,QString())==0)
            front.load(":/img/Front"+QString::number(rand()%4));
        Book temp(qAuthor,qTitle,qQuantity,books.Size()+1,front);
        books.AddBook(temp);
    }
    if (!isreader)
    books[books.Size()-1].Display(tableViewModel);
}


void DialogAddBook::on_Add_released()
{
    filename = QFileDialog::getOpenFileName(this, tr("Wybierz"),"",tr("Images(*.png *.jpg *.jpeg *.nmp *.gif"));

    if (QString::compare(filename,QString())!=0)
    {
        front.load(filename);
        ui->Front->setText(filename);
    }
}


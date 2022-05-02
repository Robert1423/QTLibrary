#include "dialogshowbook.h"
#include "ui_dialogshowbook.h"
#include "bookbase.h"

extern BookBase books;
extern QItemSelectionModel * select;

DialogShowBook::DialogShowBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowBook)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    if (select->hasSelection())
        books[select->currentIndex().row()].Show(ui->ID, ui->Author, ui->Title, ui->Quantity, ui->front);
}

DialogShowBook::~DialogShowBook()
{
    delete ui;
}

#include "dialogshowbook.h"
#include "ui_dialogshowbook.h"

DialogShowBook::DialogShowBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowBook)
{
    ui->setupUi(this);
    this->setWindowTitle("Książka");
}

DialogShowBook::~DialogShowBook()
{
    delete ui;
}

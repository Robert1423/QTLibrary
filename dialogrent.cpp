#include "dialogrent.h"
#include "ui_dialogrent.h"

DialogRent::DialogRent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRent)
{
    ui->setupUi(this);
    this->setWindowTitle("Wypożycz");
}

DialogRent::~DialogRent()
{
    delete ui;
}

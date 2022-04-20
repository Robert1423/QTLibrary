#include "dialogfinishrent.h"
#include "ui_dialogfinishrent.h"

DialogFinishRent::DialogFinishRent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFinishRent)
{
    ui->setupUi(this);
    this->setWindowTitle("Zwróć");
}

DialogFinishRent::~DialogFinishRent()
{
    delete ui;
}

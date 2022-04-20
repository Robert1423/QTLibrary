#include "dialogaddbook.h"
#include "ui_dialogaddbook.h"

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

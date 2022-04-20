#include "dialogeditbook.h"
#include "ui_dialogeditbook.h"

DialogEditBook::DialogEditBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditBook)
{
    ui->setupUi(this);
    this->setWindowTitle("Edytuj...");
}

DialogEditBook::~DialogEditBook()
{
    delete ui;
}

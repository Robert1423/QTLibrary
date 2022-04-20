#include "dialogaddreader.h"
#include "ui_dialogaddreader.h"

DialogAddReader::DialogAddReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddReader)
{
    ui->setupUi(this);
    this->setWindowTitle("Dodaj czytelnika...");
}

DialogAddReader::~DialogAddReader()
{
    delete ui;
}

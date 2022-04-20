#include "dialogshowreader.h"
#include "ui_dialogshowreader.h"

DialogShowReader::DialogShowReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowReader)
{
    ui->setupUi(this);
    this->setWindowTitle("Czytelnik");
}

DialogShowReader::~DialogShowReader()
{
    delete ui;
}

#include "dialogeditreader.h"
#include "ui_dialogeditreader.h"

DialogEditReader::DialogEditReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditReader)
{
    ui->setupUi(this);
    this->setWindowTitle("Edytuj...");
}

DialogEditReader::~DialogEditReader()
{
    delete ui;
}

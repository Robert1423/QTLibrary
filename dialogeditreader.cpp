#include "dialogeditreader.h"
#include "ui_dialogeditreader.h"
#include "database.h"

extern ReaderBase readers;
extern QItemSelectionModel * select;
DialogEditReader::DialogEditReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditReader)
{
    ui->setupUi(this);
    this->setWindowTitle("Edytuj...");
    ui->ID->setText(readers[select->currentIndex().row()].Id());
}

DialogEditReader::~DialogEditReader()
{
    delete ui;
}

void DialogEditReader::on_buttonBox_accepted()
{
    QString test = ui->Name->text();
    if (QString::compare(test,""))
        readers[select->currentIndex().row()].EditName(test);
    else
        QMessageBox::information(this,"Błąd!","Błędne dane!");
}


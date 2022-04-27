#include "dialogaddreader.h"
#include "ui_dialogaddreader.h"
#include "database.h"

extern ReaderBase readers;

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

void DialogAddReader::on_buttonBox_accepted()
{
    QString qName = ui->Name->text();
    if (!QString::compare(qName,""))
        QMessageBox::information(this,"Błąd!","Błędne dane");
    else
    {
        Reader temp(qName,readers.Size()+1);
        readers.AddReader(temp);
    }
}


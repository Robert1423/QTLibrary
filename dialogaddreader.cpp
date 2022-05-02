#include "dialogaddreader.h"
#include "ui_dialogaddreader.h"
#include "database.h"

extern bool isreader;
extern Database database;
extern ReaderBase readers;
extern QStandardItemModel *tableViewModel;

DialogAddReader::DialogAddReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddReader)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
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
        Reader temp(qName,database.Readers().Size()+1);
        readers.AddReader(temp);
    }
    if (isreader)
        readers[readers.Size()-1].Display(tableViewModel);
}


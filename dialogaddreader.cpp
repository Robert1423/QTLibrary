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
    this->setModal(true);
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
        Reader temp(qName,database.ReadersSize()+1);
        database.AddReader(temp);
    }
    if (isreader)
        database.Readers()[database.ReadersSize()-1].Display(tableViewModel);
}


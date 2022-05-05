#include "dialogeditreader.h"
#include "ui_dialogeditreader.h"
#include "database.h"
#include <QHeaderView>

extern bool isreader;
extern Database database;
//extern ReaderBase readers;
extern QItemSelectionModel * select;
extern QStandardItemModel *tableViewModel;
extern QTableView * dataTable;

DialogEditReader::DialogEditReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditReader)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setModal(true);
    if (select->hasSelection())
        ui->ID->setText(database.readers[select->currentIndex().row()].Id());
}

DialogEditReader::~DialogEditReader()
{
    delete ui;
}

void DialogEditReader::on_buttonBox_accepted()
{
    if (select->hasSelection())
    {
        QString test = ui->Name->text();
        if (QString::compare(test,""))
            database.readers[select->currentIndex().row()].EditName(test);
        else
            QMessageBox::information(this,"Błąd!","Błędne dane!");
        tableViewModel->clear();
        tableViewModel->setHorizontalHeaderLabels({"ID","Imię Nazwisko"});
        database.readers.ShowBase(tableViewModel);
        dataTable->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
        dataTable->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
    }
}


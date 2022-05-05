#include "dialogshowbook.h"
#include "ui_dialogshowbook.h"
#include "database.h"

extern Database database;
extern BookBase books;
extern QItemSelectionModel * select;

DialogShowBook::DialogShowBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowBook)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setModal(true);
    if (select->hasSelection())
        database.Books()[select->currentIndex().row()].Show(ui->ID, ui->Author, ui->Title, ui->Quantity, ui->front);
}

DialogShowBook::~DialogShowBook()
{
    delete ui;
}

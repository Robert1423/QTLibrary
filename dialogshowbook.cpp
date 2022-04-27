#include "dialogshowbook.h"
#include "ui_dialogshowbook.h"
#include "bookbase.h"

extern BookBase books;
extern QItemSelectionModel * select;

DialogShowBook::DialogShowBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShowBook)
{
    ui->setupUi(this);
    this->setWindowTitle("Książka");
    QString filename[4];
    for (int i = 0; i < 4; i++)
        filename[i] = ":/img/img/Front" + QString::number(i+1);
    srand(time(NULL));
    QImage front;
    front.load(filename[rand() % 4]);
    front = front.scaledToWidth(ui->front->width(),Qt::SmoothTransformation);
    ui->front->setPixmap(QPixmap::fromImage(front));
    books[select->currentIndex().row()].Show(ui->ID, ui->Author, ui->Title, ui->Quantity);
}

DialogShowBook::~DialogShowBook()
{
    delete ui;
}

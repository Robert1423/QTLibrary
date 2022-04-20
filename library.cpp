#include "library.h"
#include "ui_library.h"

bool isreader=false;

Library::Library(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);
    this->setWindowTitle("Biblioteka");
    this->setFixedSize(QSize(740,600));
}

Library::~Library()
{
    delete ui;
}
void Library::on_AddReader_released()
{
    addReader = new DialogAddReader;
    addReader->show();
}


void Library::on_AddBook_released()
{
    addBook = new DialogAddBook;
    addBook->show();
}


void Library::on_Rent_released()
{
    rent = new DialogRent;
    rent->show();
}


void Library::on_Unrent_released()
{
    finish = new DialogFinishRent;
    finish->show();
}


void Library::on_ShowBooks_released()
{
    isreader = false;
}


void Library::on_ShowReaders_released()
{
    isreader = true;
}


void Library::on_Show_released()
{
    if (isreader)
    {
        showReader = new DialogShowReader();
        showReader->show();
    }
    else
    {
        showBook = new DialogShowBook();
        showBook->show();
    }
}


void Library::on_Edit_released()
{
    if (isreader)
    {
        editReader = new DialogEditReader();
        editReader->show();
    }
    else
    {
        editBook = new DialogEditBook();
        editBook->show();
    }
}


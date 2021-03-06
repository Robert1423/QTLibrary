#include "rent.h"

Rent::Rent()
{

}

Rent::Rent(Book book)
{
    rented=book;
    std::time(&rentDate);
    time=14;
    due = 0;
}

void Rent::Show(QStandardItemModel *table)
{
    time_t current;
    std::time(&current);
    time_t diffrence = (current-rentDate)/86400;
    int index = table->rowCount();
    table->setRowCount(index+1);
    QStandardItem *itemBookAuthor = new QStandardItem(rented.Author());
    table->setItem(index,0,itemBookAuthor);
    QStandardItem *itemBookTitle = new QStandardItem(rented.Title());
    table->setItem(index,1,itemBookTitle);
    tm * dateRent = localtime(&rentDate);
    QString dateR = QString::number(dateRent->tm_mday)+"/"+QString::number(dateRent->tm_mon+1)+"/"+
            QString::number(dateRent->tm_year+1900); //łąńcuch string daty wypożyczenia
    QStandardItem *itemRentDate = new QStandardItem(dateR);
    itemRentDate->setTextAlignment(Qt::AlignCenter);
    table->setItem(index,2,itemRentDate);
    time_t exp=rentDate+(time*86400);
    tm * dateExp = localtime(&exp);
    QString dateE = QString::number(dateExp->tm_mday)+"/"+QString::number(dateExp->tm_mon+1)+"/"+
            QString::number(dateExp->tm_year+1900); //łąńcuch string daty wypożyczenia
    QStandardItem *itemDate = new QStandardItem(dateE);
    if (diffrence<=14)
       itemDate->setBackground(Qt::darkGreen);
    else
        itemDate->setBackground(Qt::red);
    itemDate->setForeground(Qt::white);
    itemDate->setTextAlignment(Qt::AlignCenter);
    table->setItem(index,3,itemDate);

}

double Rent::CalculateDue()
{
    time_t current;
    std::time(&current);
    time_t diffrence = (current-rentDate)/86400;
    if (diffrence>time)
        due=(diffrence-time)*duemultiply;
    return due;
}

QDataStream &operator<<(QDataStream & out, const Rent &b)
{
    out << b.rented << b.rentDate << b.due << b.time;
    return out;
}
QDataStream &operator>>(QDataStream & in, Rent &b)
{
    in >> b.rented >> b.rentDate >> b.due >> b.time;
    return in;
}

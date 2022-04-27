#ifndef RENT_H
#define RENT_H

#include <library.h>
#include <book.h>

class Rent
{
protected:
    Book rented;
    time_t rentDate;
    int time; //na ile dni wypożyczyć, dla uproszczenia 14
    double due;
public:
    Rent();
    Rent(Book book);
    void Show(QStandardItemModel *table);
    double CalculateDue();
    QString Title() {return rented.Title();}
    friend QDataStream &operator<<(QDataStream & out, const Rent &b);
    friend QDataStream &operator>>(QDataStream & in, Rent &b);
};

#endif // RENT_H

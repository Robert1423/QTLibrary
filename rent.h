#ifndef RENT_H
#define RENT_H

#include <library.h>
#include <book.h>

class Rent
{
protected:
    friend class boost::serialization::access;
    Book rented;
    time_t rentDate;
    int time; //na ile dni wypożyczyć, dla uproszczenia 14
    double due;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & rented & rentDate & time;
    }
public:
    Rent();
    Rent(Book book);
    void Show(QStandardItemModel *table);
    double CalculateDue();
    string Title() {return rented.Title();}
};

#endif // RENT_H

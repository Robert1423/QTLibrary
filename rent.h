#ifndef RENT_H
#define RENT_H

#include <library.h>
#include <book.h>

class Rent
{
protected:
    Book rented;
    time_t rentDate;
    int time; //na ile dni wypożyczyć
public:
    Rent();
    Rent(Book book, int t);
    void Show(DialogShowReader * dialog);
};

#endif // RENT_H

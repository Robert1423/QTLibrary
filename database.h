#ifndef DATABASE_H
#define DATABASE_H

#include "readerbase.h"
#include "bookbase.h"

class Database
{
private:
    friend class boost::serialization::access;
    BookBase books;
    ReaderBase readers;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & books & readers;
    }
public:
    Database();
    Database(BookBase & b, ReaderBase & r) :books(b),readers(r){}
};

#endif // DATABASE_H

#ifndef DATABASE_H
#define DATABASE_H

#include "readerbase.h"
#include "bookbase.h"

class Database
{
private:
    BookBase books;
    ReaderBase readers;
public:
    Database();
};

#endif // DATABASE_H

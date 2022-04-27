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
    Database(BookBase & b, ReaderBase & r) :books(b),readers(r){}
    void Set(BookBase & b, ReaderBase & r);
    BookBase Books() {return books;}
    ReaderBase Readers() {return readers;}
    int BooksSize() {return books.Size();}
    int ReadersSize() {return readers.Size();}
    friend QDataStream &operator<<(QDataStream & out, const Database &b);
    friend QDataStream &operator>>(QDataStream & in, Database &b);
    friend void Save(Database &c, Library *Ui);
    friend void Load(Database &c, Library *Ui);
};
#endif // DATABASE_H

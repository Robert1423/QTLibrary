#ifndef BOOKBASE_H
#define BOOKBASE_H

#include "book.h"
#include "library.h"

class BookBase
{
protected:
    QVector<Book> books;
public:
    BookBase();
    void ShowBase(QStandardItemModel * table);
    void AddBook(Book & b);
    void RemoveBook(int i);
    vector<int> SearchAll(string &t);
    int Search(string &t);
    int Size() {return books.size();}
    Book& operator[](int i) {return books[i];}
    friend QDataStream &operator<<(QDataStream & out, const BookBase &b);
    friend QDataStream &operator>>(QDataStream & in, BookBase &b);
};

#endif // BOOKBASE_H

#ifndef BOOKBASE_H
#define BOOKBASE_H

#include "book.h"
#include "library.h"

class BookBase
{
protected:
    friend class boost::serialization::access;
    std::vector<Book> books;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & books;
    }
public:
    BookBase();
    void ShowBase(QStandardItemModel * table);
    void AddBook(Book b);
    void RemoveBook(int i);
    int Search(string t, int i);
};

#endif // BOOKBASE_H

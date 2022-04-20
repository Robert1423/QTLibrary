#ifndef BOOKBASE_H
#define BOOKBASE_H

#include "book.h"
#include "library.h"

class BookBase
{
protected:
    std::vector<Book> books;
public:
    BookBase();
    void ShowBase(Library * Ui);
    void AddBook(Book b);
    void RemoveBook(int i);
};

#endif // BOOKBASE_H

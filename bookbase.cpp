#include "bookbase.h"

BookBase::BookBase()
{

}

void BookBase::ShowBase(QStandardItemModel * table)
{
    for (Book b : books)
        b.Display(table);
}
void BookBase::AddBook(Book b)
{
    books.push_back(b);
}
void BookBase::RemoveBook(int i)
{
    books.erase(books.begin()+i);
}

int BookBase::Search(string t, int i)
{
    for (i; i<(int)books.size(); i++)
    {
        if (t==books[i].Title())
            return i;
        if (t==books[i].Author())
            return i;
        if (t==books[i].Id())
            return i;
    }
    return -1;
}

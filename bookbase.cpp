#include "bookbase.h"
#include <QVector>

BookBase::BookBase()
{}

void BookBase::ShowBase(QStandardItemModel * table)
{
        foreach (Book b, books)
            b.Display(table);
}
void BookBase::AddBook(Book & b)
{
    books.append(b);
}
void BookBase::RemoveBook(int i)
{
    books.remove(i);
}

vector<int> BookBase::SearchAll(QString &t)
{
    vector<int> res;
    for (int i=0; i<(int)books.size(); i++)
    {
        if (books[i].Title().contains(t,Qt::CaseInsensitive))
        {
            res.push_back(i);
            continue;
        }
        if (books[i].Author().contains(t,Qt::CaseInsensitive))
        {
            res.push_back(i);
            continue;
        }
        if (books[i].Id().contains(t,Qt::CaseInsensitive))
        {
            res.push_back(i);
            continue;
        }
    }
    return res;
}

int BookBase::Search(QString &t)
{
    for (int i=0; i<(int)books.size(); i++)
    {
        if (books[i].Title().compare(t,Qt::CaseInsensitive) == 0)
            return i;
        if (books[i].Author().compare(t,Qt::CaseInsensitive) == 0)
            return i;
        if (books[i].Id().compare(t,Qt::CaseInsensitive) == 0)
            return i;
    }
    return -1; //jeżeli nie znaleziono
}

QDataStream& operator<<(QDataStream & out, const BookBase &b)
{
    out << b.books;
    return out;
}

QDataStream& operator>>(QDataStream & in, BookBase &b)
{
    in >> b.books;
    return in;
}

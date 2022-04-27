#include "bookbase.h"
#include <QVector>

BookBase::BookBase()
{
//    Book test("test","test",10,1);
//    books.push_back(test);
}

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

vector<int> BookBase::SearchAll(string &t)
{
    vector<int> res;
    transform(t.begin(),t.end(),t.begin(),[](unsigned char c){ return toupper(c); });
    for (int i=0; i<(int)books.size(); i++)
    {
        string test = books[i].Title().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (test.find(t) != string::npos)
            res.push_back(i);
        test = books[i].Author().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (test.find(t) != string::npos)
            res.push_back(i);
        test = books[i].Id().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (test.find(t) != string::npos)
            res.push_back(i);
    }
    return res;
}

int BookBase::Search(string &t)
{
    transform(t.begin(),t.end(),t.begin(),[](unsigned char c){ return toupper(c); });
    for (int i=0; i<(int)books.size(); i++)
    {
        string test = books[i].Title().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (t == test)
            return i;
        test = books[i].Author().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (t == test)
            return i;
        test = books[i].Id().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (t == test)
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

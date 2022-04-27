#ifndef BOOK_H
#define BOOK_H

#include "library.h"

class Book
{
protected:
    QString author;
    QString title;
    int quantity;
    QString id;
public:
    Book() : author(""),title(""),quantity(0),id(""){}
    Book(QString a, QString t, int q,int i) : author(a), title(t), quantity(q) { SetId(i); }
    void SetId(int index);
    bool IsAvalaible();
    void Rent() { quantity--; }
    void FinishRent() { quantity++; }
    void Show(QLineEdit * i, QLineEdit *a, QLineEdit *t, QLineEdit *q);
    void Display(QStandardItemModel *table);
    void EditAuthor(QString a) { author=a; }
    void EditTitle(QString t) { title=t; }
    void EditQuantity(int q) { quantity=q; }
    QString Author() {return author;}
    QString Title() {return title;}
    int Quantity() {return quantity;}
    QString Id() {return id;}
    friend QDataStream &operator<<(QDataStream & out, const Book &b);
    friend QDataStream &operator>>(QDataStream & in, Book &b);
};

#endif // BOOK_H

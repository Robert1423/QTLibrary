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
    QImage front;
public:
    Book() : author(""),title(""),quantity(0),id(""){}
    Book(QString a, QString t, int q,int i, QImage f) : author(a), title(t), quantity(q), front(f) { SetId(i); }
    void SetId(int index);
    bool IsAvalaible();
    void Rent() { quantity--; }
    void FinishRent() { quantity++; }
    void Show(QLineEdit * i, QLineEdit *a, QLineEdit *t, QLineEdit *q, QLabel *l);
    void Display(QStandardItemModel *table);
    void EditAuthor(QString a) { author=a; }
    void EditTitle(QString t) { title=t; }
    void EditQuantity(int q) { quantity=q; }
    void EditFront(QString file) {front.load(file);}
    QString Author() {return author;}
    QString Title() {return title;}
    int Quantity() {return quantity;}
    QString Id() {return id;}
    bool operator==(Book & comp);
    friend QDataStream &operator<<(QDataStream & out, const Book &b);
    friend QDataStream &operator>>(QDataStream & in, Book &b);
};

#endif // BOOK_H

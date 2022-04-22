#ifndef BOOK_H
#define BOOK_H

#include "library.h"

class Book
{
protected:
    friend class boost::serialization::access;
    std::string author;
    std::string title;
    int quantity;
    std::string id;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & author & title & quantity;
    }
public:
    Book() : author(""),title(""),quantity(0),id(""){}
    Book(std::string a, std::string t, int q,int i) : author(a), title(t), quantity(q) { SetId(i); }
    void SetId(int index);
    bool IsAvalaible();
    void Rent() { quantity--; }
    void FinishRent() { quantity++; }
    void Show(QLineEdit * i, QLineEdit *a, QLineEdit *t, QLineEdit *q);
    void Display(QStandardItemModel *table);
    void EditAuthor(std::string a) { author=a; }
    void EditTitle(std::string t) { title=t; }
    void EditQuantity(int q) { quantity=q; }
    string Author() {return author;}
    string Title() {return title;}
    int Quantity() {return quantity;}
    string Id() {return id;}
};

#endif // BOOK_H

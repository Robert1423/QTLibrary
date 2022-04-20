#ifndef BOOK_H
#define BOOK_H

#include "library.h"

class Book
{
protected:
    std::string author;
    std::string title;
    int quantity;
    std::string id;
public:
    Book();
    Book(std::string a, std::string t, int q) : author(a), title(t), quantity(q) {}
    void SetId(int index);
    bool IsAvalaible();
    void Rent();
    void FinishRent();
    void Show(DialogShowBook * dialog);
    void Display(Library * Ui);
    void EditAuthor(std::string a);
    void EditTitle(std::string t);
    void EditQuantity(int q);
};

#endif // BOOK_H

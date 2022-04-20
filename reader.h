#ifndef READER_H
#define READER_H
#include "library.h"
#include "rent.h"

class Reader
{
protected:
    std::string ID;
    std::string name;
    std::vector<Rent> rents;
public:
    Reader();
    Reader(std::string n) :name(n) {}
    bool CanRent();
    void Rent();
    void FinishRent();
    void Show(DialogShowReader * dialog);
    void Display(Library * Ui);
    void EditName(std::string n);
};

#endif // READER_H

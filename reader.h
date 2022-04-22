#ifndef READER_H
#define READER_H
#include "library.h"
#include "rent.h"

class Reader
{
protected:
    friend class boost::serialization::access;
    std::string ID;
    std::string name;
    double duesum;
    double paid;
    std::vector<Rent> rents;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & ID & name & duesum & paid & rents;
    }
public:
    Reader();
    Reader(std::string n) :name(n), duesum(0), paid(0) {}
    void SetId(int index);
    void Calculate();
    void Pay(double pay);
    bool CanRent();
    void AddRent(Rent &b, DialogRent * dr);
    void FinishRent(string title);
    void Show(QLineEdit *i, QLineEdit *n, QLineEdit *d, QStandardItemModel *table);
    void Display(QStandardItemModel *table);
    void EditName(std::string n);
    string Id() {return ID;}
    string Name() {return name;}
};

#endif // READER_H

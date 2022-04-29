#ifndef READER_H
#define READER_H
#include "library.h"
#include "rent.h"

class Reader
{
protected:
    QString ID;
    QString name;
    double duesum;
    double paid;
    QVector<Rent> rents;
public:
    Reader();
    Reader(QString n, int i) :name(n), duesum(0), paid(0) { SetId(i);}
    void SetId(int index);
    void Calculate();
    void Pay(double pay);
    bool CanRent();
    void AddRent(Rent &b);
    void FinishRent(int i);
    void Show(QLineEdit *i, QLineEdit *n, QLineEdit *d, QStandardItemModel *table);
    void Display(QStandardItemModel *table);
    void EditName(QString n);
    int SearchRents(QString &t);
    Rent FromRents(int i) {return rents[i];}
    double GetDue() {return duesum;}
    double GetPaid() {return paid;}
    QString Id() {return ID;}
    QString Name() {return name;}
    friend QDataStream &operator<<(QDataStream & out, const Reader &b);
    friend QDataStream &operator>>(QDataStream & in, Reader &b);
};

#endif // READER_H

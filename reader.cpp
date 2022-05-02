#include "reader.h"

Reader::Reader()
{

}
void Reader::SetId(int index)
{
    if (index>999)
        ID+="R"+QString::number(index);
    else if (index>99)
        ID+="R0"+QString::number(index);
    else
        ID+="R00"+QString::number(index);
}

void Reader::Calculate()
{
    double sum=0;
    foreach (Rent r, rents)
      sum+=r.CalculateDue();
    if (sum > duesum)
        duesum = sum;
    if (paid > duesum)
        duesum -= paid;
}

void Reader::Pay(double pay)
{
    paid+=pay;
    if (paid == duesum)
    {
        duesum = 0;
        paid = 0;
    }
}
bool Reader::CanRent()
{
    return duesum <= 0 ? true : false;
}
void Reader::AddRent(Rent &b)
{
        rents.append(b);
}
void Reader::FinishRent(int i)
{
    rents.remove(i);
}
void Reader::Show(QLineEdit *i, QLineEdit *n, QLineEdit *d, QStandardItemModel *table)
{
    i->setText(ID);
    n->setText(name);
    d->setText(QString::number(duesum));
    for (Rent r : rents)
        r.Show(table);
}
void Reader::Display(QStandardItemModel *table)
{
    int index = table->rowCount();//sczytanie liczby wierszy
    table->setRowCount(index+1);//dodanie kolejnego wiersza
    QStandardItem *itemId = new QStandardItem(ID);//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,0,itemId);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
    QStandardItem *itemName = new QStandardItem(name);//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,1,itemName);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
}
void Reader::EditName(QString n)
{
    if (QString::compare(n,""))
        name=n;
}

int Reader::SearchRents(QString &t)
{
    for (int i = 0; i < rents.size(); i++)
    {
        if (rents[i].CheckBook().Title().compare(t,Qt::CaseInsensitive) == 0)
            return i;
        if (rents[i].CheckBook().Author().compare(t,Qt::CaseInsensitive) == 0)
            return i;
        if (rents[i].CheckBook().Id().compare(t,Qt::CaseInsensitive) == 0)
            return i;
    }
    return -1;
}

QDataStream &operator<<(QDataStream & out, const Reader &b)
{
    out << b.ID << b.name << b.duesum << b.paid << b.rents;
    return out;
}
QDataStream &operator>>(QDataStream & in, Reader &b)
{
    in >> b.ID >> b.name >> b.duesum >> b.paid >> b.rents;
    return in;
}

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
    duesum=0;
    foreach (Rent r, rents)
      duesum+=r.CalculateDue();
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
    return duesum == 0 ? true : false;
}
void Reader::AddRent(Rent &b, DialogRent *dr)
{
    if (CanRent())
        rents.push_back(b);
    else
        QMessageBox::warning(dr,"Błąd!","Nie można wypożyczyć, zbyt wysoka kara!");
}
void Reader::FinishRent(string title)
{
    int i;
    for ( i = 0; i < (int)rents.size(); i++)
    {
        if (title == rents[i].Title().toStdString())
        {
            rents.remove(i);
            break;
        }
    }
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

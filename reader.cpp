#include "reader.h"

Reader::Reader()
{

}
void Reader::SetId(int index)
{
    if (index>999)
        ID+="R"+to_string(index);
    else if (index>99)
        ID+="R0"+to_string(index);
    else
        ID+="R00"+to_string(index);
}

void Reader::Calculate()
{
    duesum=0;
    for (auto r : rents)
      duesum+=r.CalculateDue();
}

void Reader::Pay(double pay)
{
    paid+=pay;
    if (paid >= duesum)
    {
        duesum = 0;
        paid-=duesum;
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
        if (title == rents[i].Title())
        {
            rents.erase(rents.begin()+i);
            break;
        }
    }
}
void Reader::Show(QLineEdit *i, QLineEdit *n, QLineEdit *d, QStandardItemModel *table)
{
    i->setText(QString::fromStdString(ID));
    n->setText(QString::fromStdString(name));
    d->setText(QString::number(duesum));
    for (Rent r : rents)
        r.Show(table);
}
void Reader::Display(QStandardItemModel *table)
{
    int index = table->rowCount();//sczytanie liczby wierszy
    table->setRowCount(index+1);//dodanie kolejnego wiersza
    QStandardItem *itemId = new QStandardItem(QString::fromStdString(ID));//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,0,itemId);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
    QStandardItem *itemName = new QStandardItem(QString::fromStdString(name));//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,1,itemName);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
}
void Reader::EditName(std::string n)
{
    if (!n.empty())
        name=n;
}

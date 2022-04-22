#include "book.h"

void Book::SetId(int index)
{
    if (index>999)
        id+="B"+to_string(index);
    else if (index>99)
        id+="B0"+to_string(index);
    else
        id+="B00"+to_string(index);
}

bool Book::IsAvalaible()
{
    return quantity>0 ? true : false;
}

void Book::Show(QLineEdit * i, QLineEdit *a, QLineEdit *t, QLineEdit *q)
{
    i->setText(QString::fromStdString(id));
    a->setText(QString::fromStdString(author));
    t->setText(QString::fromStdString(title));
    q->setText(QString::number(quantity));
}

void Book::Display(QStandardItemModel *table)
{
    int index = table->rowCount();//sczytanie liczby wierszy
    table->setRowCount(index+1);//dodanie kolejnego wiersza
    QStandardItem *itemId = new QStandardItem(QString::fromStdString(id));//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,0,itemId);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
    QStandardItem *itemAuthor = new QStandardItem(QString::fromStdString(author));//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,1,itemAuthor);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
    QStandardItem *itemTitle = new QStandardItem(QString::fromStdString(title));//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,2,itemTitle);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
    QStandardItem *itemQuantity = new QStandardItem(QString::number(quantity));//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,3,itemQuantity);
}

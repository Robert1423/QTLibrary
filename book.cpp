#include "book.h"
#include <QLabel>

void Book::SetId(int index)
{
    if (index>999)
        id+="B"+QString::number(index);
    else if (index>99)
        id+="B0"+QString::number(index);
    else
        id+="B00"+QString::number(index);
}

bool Book::IsAvalaible()
{
    return quantity>0 ? true : false;
}

void Book::Show(QLineEdit * i, QLineEdit *a, QLineEdit *t, QLineEdit *q, QLabel *l)
{
    i->setText(id);
    a->setText(author);
    t->setText(title);
    q->setText(QString::number(quantity));
    front = front.scaledToWidth(l->width(),Qt::SmoothTransformation);
    l->setPixmap(QPixmap::fromImage(front));
}

void Book::Display(QStandardItemModel *table)
{
    int index = table->rowCount();//sczytanie liczby wierszy
    table->setRowCount(index+1);//dodanie kolejnego wiersza
    QStandardItem *itemId = new QStandardItem(id);//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,0,itemId);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
    QStandardItem *itemAuthor = new QStandardItem(author);//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,1,itemAuthor);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
    QStandardItem *itemTitle = new QStandardItem(title);//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,2,itemTitle);//wstawienie komórki do tabeli, argumenty: wiersz, kolumna i zawartość
    QStandardItem *itemQuantity = new QStandardItem(QString::number(quantity));//tworzenie komórki tabeli, inicjowanej polem klasy
    table->setItem(index,3,itemQuantity);
}

bool Book::operator==(Book &comp)
{
    bool res = false;
    if (author.compare(comp.author,Qt::CaseInsensitive) == 0)
    {
        if (title.compare(comp.title,Qt::CaseInsensitive) == 0)
            res = true;
    }
    return res;
}

QDataStream& operator<<(QDataStream & out, const Book &b)
{
    out << b.author << b.title << b.quantity << b.id << b.front;
    return out;
}
QDataStream& operator>>(QDataStream &in, Book &b)
{
    in >> b.author >> b.title >> b.quantity >> b.id >> b.front;
    return in;
}

#include "database.h"

const QString filename = "data.json";

Database::Database()
{
    books = BookBase();
    readers = ReaderBase();
}

void Database::Set(BookBase & b, ReaderBase & r)
{
    books = b;
    readers = r;
}
QDataStream &operator<<(QDataStream & out, const Database &b)
{
    out << b.books << b.readers;
    return out;
}
QDataStream &operator>>(QDataStream & in, Database &b)
{
    in >> b.books >> b.readers;
    return in;
}

void Save(Database &c, Library *Ui)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(Ui, "Błąd","Nie można otworzyć pliku");
        return;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_2);
    out << c;
    file.flush();
    file.close();
}
void Load(Database &c, Library *Ui)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(Ui, "Błąd","Nie można otworzyć pliku");
        return;
    }
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_6_2);
    in >> c;
    file.close();
}

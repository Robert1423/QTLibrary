#include "readerbase.h"

ReaderBase::ReaderBase()
{

}
void ReaderBase::ShowBase(QStandardItemModel * table)
{
    foreach (Reader r, readers)
        r.Display(table);
}
vector<int> ReaderBase::SearchAll(QString &t)
{
    vector<int> res;
    for (int i=0; i<(int)readers.size(); i++)
    {
        if (readers[i].Name().contains(t,Qt::CaseInsensitive))
            res.push_back(i);
        if (readers[i].Id().contains(t,Qt::CaseInsensitive))
           res.push_back(i);
    }
    return res;
}

int ReaderBase::Search(QString &t)
{
    for (int i=0; i<(int)readers.size(); i++)
    {
        if (readers[i].Id().compare(t,Qt::CaseInsensitive) == 0)
            return i;
        if (readers[i].Name().compare(t,Qt::CaseInsensitive)==0)
            return i;
    }
    return -1;
}

QDataStream &operator<<(QDataStream & out, const ReaderBase &b)
{
    out << b.readers;
    return out;
}
QDataStream &operator>>(QDataStream & in, ReaderBase &b)
{
    in >> b.readers;
    return in;
}

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
//    transform(t.begin(),t.end(),t.begin(),[](unsigned char c){ return toupper(c); });
    for (int i=0; i<(int)readers.size(); i++)
    {
//        string test = readers[i].Id().toStdString();
//        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (readers[i].Name().contains(t,Qt::CaseInsensitive))
            res.push_back(i);
//        test = readers[i].Name().toStdString();
//        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (readers[i].Id().contains(t,Qt::CaseInsensitive))
           res.push_back(i);
    }
    return res;
}

int ReaderBase::Search(QString &t)
{
//    transform(t.begin(),t.end(),t.begin(),[](unsigned char c){ return toupper(c); });
    for (int i=0; i<(int)readers.size(); i++)
    {
//        string test = readers[i].Id().toStdString();
//        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (readers[i].Id().compare(t,Qt::CaseInsensitive) == 0)
            return i;
//        test = readers[i].Name().toStdString();
//        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
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

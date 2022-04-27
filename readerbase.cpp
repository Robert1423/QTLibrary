#include "readerbase.h"

ReaderBase::ReaderBase()
{

}
void ReaderBase::ShowBase(QStandardItemModel * table)
{
    foreach (Reader r, readers)
        r.Display(table);
}
vector<int> ReaderBase::SearchAll(string &t)
{
    vector<int> res;
    transform(t.begin(),t.end(),t.begin(),[](unsigned char c){ return toupper(c); });
    for (int i=0; i<(int)readers.size(); i++)
    {
        string test = readers[i].Id().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (test.find(t) != string::npos)
            res.push_back(i);
        test = readers[i].Name().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (test.find(t) != string::npos)
           res.push_back(i);
    }
    return res;
}

int ReaderBase::Search(string &t)
{
    transform(t.begin(),t.end(),t.begin(),[](unsigned char c){ return toupper(c); });
    for (int i=0; i<(int)readers.size(); i++)
    {
        string test = readers[i].Id().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (t == test)
            return i;
        test = readers[i].Name().toStdString();
        transform(test.begin(),test.end(),test.begin(),[](unsigned char c){ return toupper(c); });
        if (t == test)
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

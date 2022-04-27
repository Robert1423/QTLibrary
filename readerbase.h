#ifndef READERBASE_H
#define READERBASE_H

#include "reader.h"

class ReaderBase
{
protected:
    QVector<Reader> readers;
public:
    ReaderBase();
    void ShowBase(QStandardItemModel * table);
    void AddReader(Reader &r) {readers.push_back(r);}
    void RemoveReader(int i) {readers.remove(i);}
    vector<int> SearchAll(string &t);
    int Search(string &t);
    int Size() {return readers.size();}
    Reader& operator[](int i){return readers[i];}
    friend QDataStream &operator<<(QDataStream & out, const ReaderBase &b);
    friend QDataStream &operator>>(QDataStream & in, ReaderBase &b);
};

#endif // READERBASE_H

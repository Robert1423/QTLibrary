#ifndef READERBASE_H
#define READERBASE_H

#include "reader.h"

class ReaderBase
{
protected:
    friend class boost::serialization::access;
    std::vector<Reader> readers;
    template<class Archive>
    void serialize(Archive &a, const unsigned version)
    {
        a & readers;
    }
public:
    ReaderBase();
    void ShowBase(QStandardItemModel * table);
    void AddReader(Reader &r) {readers.push_back(r);}
    void RemoveReader(int i) {readers.erase(readers.begin()+i);}
    int Search(string t, int i);
};

#endif // READERBASE_H

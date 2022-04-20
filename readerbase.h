#ifndef READERBASE_H
#define READERBASE_H

#include "reader.h"

class ReaderBase
{
protected:
    std::vector<Reader> readers;
public:
    ReaderBase();
    void ShowBase(Library * Ui);
    void AddReader(Reader r);
    void RemoveReader(int i);
};

#endif // READERBASE_H

#include "readerbase.h"

ReaderBase::ReaderBase()
{

}
void ReaderBase::ShowBase(QStandardItemModel * table)
{
    for (Reader r : readers)
        r.Display(table);
}
int ReaderBase::Search(string t, int i)
{
    for (i; i<(int)readers.size(); i++)
    {
        if (t==readers[i].Id())
            return i;
        if (t==readers[i].Name())
            return i;
    }
    return -1;
}

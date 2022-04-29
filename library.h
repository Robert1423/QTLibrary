#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTableView>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFile>
#include <QCoreApplication>
#include <QDataStream>
#include <QMouseEvent>
#include <QPoint>
#include <vector>
#include <time.h>
#include "dialogaddreader.h"
#include "dialogaddbook.h"
#include "dialogfinishrent.h"
#include "dialogrent.h"
#include "dialogshowreader.h"
#include "dialogshowbook.h"
#include "dialogeditbook.h"
#include "dialogeditreader.h"

using namespace std;
const static double duemultiply = 5;//wartość kary za nieoddanie w terminie, dla uproszczenia
QT_BEGIN_NAMESPACE
namespace Ui { class Library; }
QT_END_NAMESPACE

class Library : public QMainWindow
{
    Q_OBJECT

//    QStandardItemModel *tableViewModel;



public:
    Library(QWidget *parent = nullptr);
    ~Library();


private slots:
    void on_AddReader_released();

    void on_AddBook_released();

    void on_Rent_released();

    void on_Unrent_released();

    void on_ShowBooks_released();

    void on_ShowReaders_released();

    void on_Show_released();

    void on_Edit_released();

    void on_Sort_released();

    void on_Close_released();

    void on_RemoveBook_released();

    void on_FindBook_released();

private:
    Ui::Library *ui;
    DialogAddReader *addReader;
    DialogAddBook *addBook;
    DialogRent *rent;
    DialogFinishRent *finish;
    DialogShowReader *showReader;
    DialogShowBook *showBook;
    DialogEditBook *editBook;
    DialogEditReader *editReader;

//    void mousePressedEvent(QMouseEvent * event);
//    void mouseMoveEvent(QMouseEvent * event);

//    QPoint cur_pos;
//    QPoint new_pos;
};
#endif // LIBRARY_H

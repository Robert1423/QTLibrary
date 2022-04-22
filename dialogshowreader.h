#ifndef DIALOGSHOWREADER_H
#define DIALOGSHOWREADER_H

#include <QStandardItemModel>
#include <QDialog>

namespace Ui {
class DialogShowReader;
}

class DialogShowReader : public QDialog
{
    Q_OBJECT
    QStandardItemModel *rentsTable;

public:
    explicit DialogShowReader(QWidget *parent = nullptr);
    ~DialogShowReader();

private:
    Ui::DialogShowReader *ui;
};

#endif // DIALOGSHOWREADER_H

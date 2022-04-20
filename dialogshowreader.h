#ifndef DIALOGSHOWREADER_H
#define DIALOGSHOWREADER_H

#include <QDialog>

namespace Ui {
class DialogShowReader;
}

class DialogShowReader : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowReader(QWidget *parent = nullptr);
    ~DialogShowReader();

private:
    Ui::DialogShowReader *ui;
};

#endif // DIALOGSHOWREADER_H

#ifndef DIALOGEDITREADER_H
#define DIALOGEDITREADER_H

#include <QDialog>

namespace Ui {
class DialogEditReader;
}

class DialogEditReader : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditReader(QWidget *parent = nullptr);
    ~DialogEditReader();

private:
    Ui::DialogEditReader *ui;
};

#endif // DIALOGEDITREADER_H

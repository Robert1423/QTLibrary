#ifndef DIALOGADDREADER_H
#define DIALOGADDREADER_H

#include <QDialog>

namespace Ui {
class DialogAddReader;
}

class DialogAddReader : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddReader(QWidget *parent = nullptr);
    ~DialogAddReader();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAddReader *ui;
};

#endif // DIALOGADDREADER_H

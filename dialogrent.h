#ifndef DIALOGRENT_H
#define DIALOGRENT_H

#include <QDialog>

namespace Ui {
class DialogRent;
}

class DialogRent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRent(QWidget *parent = nullptr);
    ~DialogRent();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogRent *ui;
};

#endif // DIALOGRENT_H

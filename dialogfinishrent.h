#ifndef DIALOGFINISHRENT_H
#define DIALOGFINISHRENT_H

#include <QDialog>

namespace Ui {
class DialogFinishRent;
}

class DialogFinishRent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFinishRent(QWidget *parent = nullptr);
    ~DialogFinishRent();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogFinishRent *ui;
};

#endif // DIALOGFINISHRENT_H

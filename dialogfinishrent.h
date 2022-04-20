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

private:
    Ui::DialogFinishRent *ui;
};

#endif // DIALOGFINISHRENT_H

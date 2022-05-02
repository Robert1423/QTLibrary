#ifndef DIALOGADDBOOK_H
#define DIALOGADDBOOK_H

#include <QDialog>

namespace Ui {
class DialogAddBook;
}

class DialogAddBook : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddBook(QWidget *parent = nullptr);
    ~DialogAddBook();

private slots:
    void on_buttonBox_accepted();

    void on_Add_released();

private:
    Ui::DialogAddBook *ui;
};

#endif // DIALOGADDBOOK_H

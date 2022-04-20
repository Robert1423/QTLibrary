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

private:
    Ui::DialogAddBook *ui;
};

#endif // DIALOGADDBOOK_H

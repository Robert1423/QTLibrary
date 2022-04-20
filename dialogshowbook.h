#ifndef DIALOGSHOWBOOK_H
#define DIALOGSHOWBOOK_H

#include <QDialog>

namespace Ui {
class DialogShowBook;
}

class DialogShowBook : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowBook(QWidget *parent = nullptr);
    ~DialogShowBook();

private:
    Ui::DialogShowBook *ui;
};

#endif // DIALOGSHOWBOOK_H

#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <QDialog>

namespace Ui {
class Workshop;
}

class Workshop : public QDialog
{
    Q_OBJECT

public:
    explicit Workshop(QWidget *parent = 0);
    ~Workshop();

private:
    Ui::Workshop *ui;
};

#endif // WORKSHOP_H

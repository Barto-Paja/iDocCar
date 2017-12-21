#ifndef NEWREPAIR_H
#define NEWREPAIR_H

#include <QDialog>

namespace Ui {
class newRepair;
}

class newRepair : public QDialog
{
    Q_OBJECT

public:
    explicit newRepair(QWidget *parent = 0);
    ~newRepair();

private:
    Ui::newRepair *ui;
};

#endif // NEWREPAIR_H

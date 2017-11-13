#ifndef MAINMENUGUI_H
#define MAINMENUGUI_H

#include <QMainWindow>
#include <newcar.h>

namespace Ui {
class MainMenuGUI;
}

class MainMenuGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenuGUI(QWidget *parent = 0);
    ~MainMenuGUI();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainMenuGUI *ui;
};

#endif // MAINMENUGUI_H

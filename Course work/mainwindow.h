#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <windows.h>
#include "WHandler.h"
#include "slider.h"
#include "libraries.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionShutDown_triggered();

    void on_actionRestart_triggered();

    void on_actionSleep_triggered();

    void on_okButton_clicked();

    void on_okButton_2_clicked();

private:
    windowsHandler whandler;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "schooltime.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    SchoolTime myschooltime;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openArrivalButton_wasclicked();
    void openDepartureButton_wasclicked();
    void on_computeButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

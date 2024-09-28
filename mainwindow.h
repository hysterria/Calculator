#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "secondwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();
private:
    SecondWindow *secondwindow;
};
#endif // MAINWINDOW_H

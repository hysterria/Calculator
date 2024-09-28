#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class SecondWindow : public QDialog {
    Q_OBJECT

public:
    SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void onButtonClicked();

private:
    QLineEdit *display;
    QString currentInput;
    double lastValue;
    QString lastOperator;
};
#endif // SECONDWINDOW_H

#include "secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) : QDialog(parent) {
    this->setWindowTitle("Calculator");
    this->setGeometry(100, 100, 300, 400);

    // Основной дисплей калькулятора
    display = new QLineEdit(this);
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    // Кнопки калькулятора
    QStringList buttonLabels = { "7", "8", "9", "/",
                                "4", "5", "6", "*",
                                "1", "2", "3", "-",
                                "0", "C", "=", "+" };

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(display, 0, 0, 1, 4);  // Добавляем дисплей в верхнюю часть

    // Добавляем кнопки в сетку
    int pos = 0;
    for (int row = 1; row <= 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            QPushButton *button = new QPushButton(buttonLabels[pos], this);
            connect(button, &QPushButton::clicked, this, &SecondWindow::onButtonClicked);
            layout->addWidget(button, row, col);
            pos++;
        }
    }

    this->setLayout(layout);
}
SecondWindow::~SecondWindow(){}

// Обработка нажатий на кнопки
void SecondWindow::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();

    if (buttonText == "C") {
        currentInput.clear();
        lastValue = 0;
        lastOperator.clear();
        display->clear();
    } else if (buttonText == "=") {
        double result = lastValue;
        if (!currentInput.isEmpty()) {
            double operand = currentInput.toDouble();
            if (lastOperator == "+") result += operand;
            else if (lastOperator == "-") result -= operand;
            else if (lastOperator == "*") result *= operand;
            else if (lastOperator == "/") result /= operand;
        }
        display->setText(QString::number(result));
        currentInput.clear();
        lastOperator.clear();
        lastValue = result;
    } else if (buttonText == "+" || buttonText == "-" || buttonText == "*" || buttonText == "/") {
        lastValue = currentInput.toDouble();
        lastOperator = buttonText;
        currentInput.clear();
    } else {
        currentInput += buttonText;
        display->setText(currentInput);
    }
}

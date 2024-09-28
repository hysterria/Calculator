#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Устанавливаем размеры и название
    this -> setGeometry(0,0,800,600);
    this -> setWindowTitle("Authorization and Calculator");

    // Делаем центральный виджет
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QGroupBox *groupBox = new QGroupBox("Авторизация",this);
    groupBox->setMaximumSize(300,300);

    // Устанавливаем вертикальный и сеточный лэйауты
    QVBoxLayout *vBoxLayout = new QVBoxLayout(groupBox);
    QGridLayout *gridLayout = new QGridLayout();

    // Поля для логина и пароля
    QLabel *labelLogin = new QLabel("Логин", this);
    loginEdit = new QLineEdit(this);

    QLabel *labelPassword = new QLabel("Пароль", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    // Добавляем элементы в сеточный лэйаут
    gridLayout->addWidget(labelLogin, 0, 0);
    gridLayout->addWidget(loginEdit, 0, 1);
    gridLayout->addWidget(labelPassword, 1, 0);
    gridLayout->addWidget(passwordEdit, 1, 1);

    // Кнопка "Вход"
    QPushButton *loginButton = new QPushButton("Вход", this);

    // Добавляем все элементы в вертикальный лэйаут
    vBoxLayout->addLayout(gridLayout);
    vBoxLayout->addWidget(loginButton);

    // Добавляем группу в основной лэйаут
    mainLayout->addWidget(groupBox);

    // Устанавливаем центральный виджет
    this->setCentralWidget(centralWidget);

    // Меню бар и статус бар
    QMenuBar *menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);

    QStatusBar *statusBar = new QStatusBar(this);
    this->setStatusBar(statusBar);

    // Подключаем сигнал кнопки к слоту
    connect(loginButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow() {}

// Слот для обработки нажатия на кнопку входа
void MainWindow::on_pushButton_clicked() {
    QString login_value = loginEdit->text();
    QString password_value = passwordEdit->text();
    if (login_value == "1" && password_value == "1") {
        hide();  // Скрываем главное окно
        secondwindow = new SecondWindow(this);  // Создаем новое окно калькулятора
        secondwindow->show();  // Показываем окно калькулятора
    } else {
        QMessageBox::warning(this, "Авторизация", "Неверный логин или пароль");
    }
}


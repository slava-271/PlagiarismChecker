#include "MainWindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "TextForm.h" // Включаем новый заголовочный файл

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Создаем центральный виджет и компоновщики
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget); // Вертикальный компоновщик для главного окна

    // Создаем горизонтальный компоновщик для текстовых полей
    QHBoxLayout *textLayout = new QHBoxLayout();
    textEdit1 = new QTextEdit(this);
    textEdit2 = new QTextEdit(this);

    // Устанавливаем текстовые поля на растяжение
    textEdit1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    textEdit2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Добавляем текстовые поля в горизонтальный компоновщик
    textLayout->addWidget(textEdit1);
    textLayout->addWidget(textEdit2);

    // Создаем горизонтальный компоновщик для кнопок
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *openButton1 = new QPushButton("Open Original", this);
    QPushButton *openButton2 = new QPushButton("Open Plagiat", this);
    QPushButton *newFormButton = new QPushButton("Find plagiat", this); // Новая кнопка

    // Подключаем кнопки к слотам
    connect(openButton1, &QPushButton::clicked, this, &MainWindow::openFile1);
    connect(newFormButton, &QPushButton::clicked, this, &MainWindow::openTextForm);
    connect(openButton2, &QPushButton::clicked, this, &MainWindow::openFile2);
 // Подключаем новую форму

    // Выравниваем кнопки по центру текстовых полей
    buttonLayout->addWidget(openButton1, 0, Qt::AlignCenter);
    buttonLayout->addWidget(newFormButton, 0, Qt::AlignCenter);
    buttonLayout->addWidget(openButton2, 0, Qt::AlignCenter);
 // Добавляем новую кнопку

    // Добавляем кнопки над текстовыми полями
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(textLayout);

    // Устанавливаем компоновщик как центральный виджет
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {}

// void MainWindow::openFile1() {
//     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File 1"), lastFilePath1); // Используем сохраненный путь
//     if (!fileName.isEmpty()) {
//         QFile file(fileName);

//         if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//             QTextStream in(&file);
//             textEdit1->setPlainText(in.readAll()); // Загружаем текст в первое поле
//             file.close();
//             lastFilePath1 = fileName; // Сохраняем путь
//         }
//     }
// }

void MainWindow::openFile1() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File 1"), lastFilePath1);
    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly)) {
            // Read the entire file into a QByteArray
            QByteArray byteArray = file.readAll();
            // Convert QByteArray to QString using Windows-1251
            QString content = QString::fromLocal8Bit(byteArray);
            textEdit1->setPlainText(content); // Load text into the textEdit1
            file.close();
            lastFilePath1 = fileName; // Save the path
        }
    }
}

// void MainWindow::openFile2() {
//     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File 2"), lastFilePath2); // Используем сохраненный путь
//     if (!fileName.isEmpty()) {
//         QFile file(fileName);
//         if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//             QTextStream in(&file);
//             textEdit2->setPlainText(in.readAll()); // Загружаем текст во второе поле
//             file.close();
//             lastFilePath2 = fileName; // Сохраняем путь
//         }
//     }
// }

void MainWindow::openFile2() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File 2"), lastFilePath2); // Используем сохраненный путь
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) { // Open file for reading only
            // Read the entire file into a QByteArray
            QByteArray byteArray = file.readAll();
            // Convert QByteArray to QString using Windows-1251
            QString content = QString::fromLocal8Bit(byteArray);
            textEdit2->setPlainText(content); // Загружаем текст во второе поле
            file.close();
            lastFilePath2 = fileName; // Сохраняем путь
        }
    }
}


void MainWindow::openTextForm() {
    TextForm *textForm = new TextForm(lastFilePath1, lastFilePath2, this);
    textForm->setModal(false); // Делаем окно немодальным
    textForm->show(); // Показываем форму
}



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include "TextForm.h" // Включаем заголовочный файл для TextForm


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile1();
    void openFile2();
    void openTextForm(); // Новый слот для открытия формы с текстовым полем

private:
    QString lastFilePath1; // Для хранения пути к первому файлу
    QString lastFilePath2;

private:
    QTextEdit *textEdit1; // Первое текстовое поле
    QTextEdit *textEdit2; // Второе текстовое поле
};



#endif // MAINWINDOW_H



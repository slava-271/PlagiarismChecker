#include "TextForm.h"

TextForm::TextForm(QString& path1, QString& path2, QWidget *parent)
    : QDialog(parent, Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Текстовое поле
    QTextEdit *textEdit = new QTextEdit(this);
    layout->addWidget(textEdit);

    setLayout(layout);
    setWindowTitle("Text Form");
    resize(400, 300); // Устанавливаем размер формы

    QProcess process;
    QString program = "C:/3sem/CourseWork/ConsoleApplication6/Debug/ConsoleApplication6.exe"; // Укажите полный путь к .exe
    QStringList arguments;
    arguments << path1 << path2; // Передаем пути как аргументы
    process.start(program,arguments);
    process.waitForFinished();
    // QProcess::startDetached(program, arguments);
    QString path3 = "C:/Course3sem/FileRead.txt";
    QString path0 = "C:/Course3sem/Percentage.txt";


    QFile file(path3); // Используем path1 для открытия файла
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray byteArray = file.readAll();
        QString content = QString::fromLocal8Bit(byteArray); // Конвертируем в QString
        textEdit->setPlainText(content); // Заполняем текстовое поле
        file.close();
    }

    QFile fileBuff(path0);
    if (fileBuff.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray byteArray = fileBuff.readAll();
        QString str = QString::fromLocal8Bit(byteArray); // Конвертируем в QString
        textEdit->append("\nPercentage of plagiat is:");
        textEdit->append(str);

        fileBuff.close();
    }

    ;




}


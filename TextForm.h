#ifndef TEXTFORM_H
#define TEXTFORM_H

#include <QDialog>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class TextForm : public QDialog {
    Q_OBJECT

public:
    TextForm(QString& orig, QString& plag, QWidget *parent = nullptr);
};

#endif // TEXTFORM_H



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString filePath = QDir(QApplication::applicationDirPath()).filePath(tr("memo.txt"));
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(this, tr("ファイルが開けませんでした"), file.errorString());
        return;
    }
    QTextStream out(&file);
    out << ui->lineEdit->text() << endl;
    qDebug() << ui->lineEdit->text();
    file.close();
}

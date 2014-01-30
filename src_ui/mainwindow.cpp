#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <stdio.h>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // ui setup
    ui->setupUi(this);
    ui->TextPath->setText("input.txt");
    ui->TTFPath->setText("script.ttf");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SelectText_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Select Text File Input"),".",tr("text files,(*.txt)"));
    ui->TextPath->setText(path);
}

void MainWindow::on_SelectTTF_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Select TTF File"),".",tr("text files,(*.ttf)"));
    ui->TTFPath->setText(path);
}

void MainWindow::on_Execute_clicked()
{
    // command line call
    // hard coded size of 32
    std::string strCommand = "TextToImage.exe " + ui->TextPath->text().toStdString() +" "+ui->TTFPath->text().toStdString()+" 32";
    system(strCommand.c_str());
}

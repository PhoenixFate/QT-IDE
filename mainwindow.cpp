#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->textEdit1=new QTextEdit();
    QFont f;
    f.setPixelSize(20);
    this->textEdit1->setFont(f);
    QColor c;
    c.setRgb(110,110,110);
    this->textEdit1->setTextColor(c);
    this->setCentralWidget(this->textEdit1);//将这个textEdit放置到对话框的中间
    this->fileMenu=this->menuBar()->addMenu("文件");
    this->editMenu=this->menuBar()->addMenu("编辑");
    this->helpMenu=this->menuBar()->addMenu("帮助");
    this->fileOpen=new QAction("打开",this);
}

MainWindow::~MainWindow()
{
    delete textEdit1;
}

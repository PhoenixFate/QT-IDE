#include "mainwindow.h"
#include <QMessageBox>

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


    //添加menu
    this->fileMenu=this->menuBar()->addMenu("文件");
    this->editMenu=this->menuBar()->addMenu("编辑");
    this->helpMenu=this->menuBar()->addMenu("帮助");


    //file menu相关
    this->fileOpenAction=new QAction("打开",this);
    this->fileOpenAction->setShortcut(tr("Ctrl+O"));
    this->fileMenu->addAction(this->fileOpenAction);
    this->fileExitAction=new QAction("退出",this);
    this->fileExitAction->setShortcut(tr("Ctrl+Q"));
    this->fileMenu->addSeparator();
    this->fileMenu->addAction(this->fileExitAction);

    connect(this->fileOpenAction,SIGNAL(triggered()),this,SLOT(onOpen()));
    connect(this->fileExitAction,SIGNAL(triggered()),this,SLOT(onExit()));


    //edit menu相关
    this->editCopyAction=new QAction("拷贝",this);
    //    this->editCopyAction->setShortcut(tr("Ctrl+C"));
    this->editMenu->addAction(editCopyAction);
    connect(this->editCopyAction,SIGNAL(triggered()),this,SLOT(onCopy()));

    this->editPasteAction=new QAction("粘贴",this);
    this->editMenu->addAction(editPasteAction);
    connect(this->editPasteAction,SIGNAL(triggered()),this,SLOT(onPaste()));
    this->editCutAction=new QAction("剪切",this);
    this->editMenu->addAction(editCutAction);

    connect(this->editCutAction,SIGNAL(triggered()),this,SLOT(onCut()));
    this->editSelectAllAction=new QAction("全选",this);
    this->editMenu->addAction(editSelectAllAction);
    connect(this->editSelectAllAction,SIGNAL(triggered()),this,SLOT(onSelectAll()));

    //help menu相关
    this->helpAboutAction=new QAction("关于",this);
    this->helpAboutAction->setShortcut(tr("Ctrl+H"));
    this->helpMenu->addAction(this->helpAboutAction);
    connect(this->helpAboutAction,SIGNAL(triggered()),this,SLOT(onAbout()));

}

MainWindow::~MainWindow()
{
    delete textEdit1;
}

void MainWindow::onOpen()
{
    QMessageBox::information(this,"title","测试");
}

void MainWindow::onAbout()
{
    QMessageBox::information(this,"title","关于");
}

void MainWindow::onExit()
{
    exit(0);
}

void MainWindow::onCopy()
{
    this->textEdit1->copy();
}

void MainWindow::onPaste()
{
    this->textEdit1->paste();
}

void MainWindow::onCut()
{
    this->textEdit1->cut();
}

void MainWindow::onSelectAll()
{
    textEdit1->selectAll();
}

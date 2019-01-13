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


    //添加menu
    this->fileMenu=this->menuBar()->addMenu("文件");
    this->editMenu=this->menuBar()->addMenu("编辑");
    this->helpMenu=this->menuBar()->addMenu("帮助");


    //file menu相关
    this->fileOpenAction=new QAction("打开",this);
    this->fileOpenAction->setShortcut(tr("Ctrl+O"));
    this->fileMenu->addAction(this->fileOpenAction);
    this->fileMenu->addSeparator();

    this->fileSaveAction=new QAction("保存",this);
    this->fileSaveAction->setShortcut(tr("Ctrl+S"));
    this->fileMenu->addAction(this->fileSaveAction);
    this->fileMenu->addSeparator();

    this->fileExitAction=new QAction("退出",this);
    this->fileExitAction->setShortcut(this->tr("Ctrl+Q"));
    this->fileMenu->addAction(this->fileExitAction);

    connect(this->fileOpenAction,SIGNAL(triggered()),this,SLOT(onOpen()));
    connect(this->fileExitAction,SIGNAL(triggered()),this,SLOT(onExit()));
    connect(this->fileSaveAction,SIGNAL(triggered()),this,SLOT(onSave()));

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
    QString fileName=QFileDialog::getOpenFileName();
    if(fileName.isEmpty())
    {
        //没有选择任何文件
        return;
    }
    const char *fn=fileName.toStdString().data();//QString 转化成 const char*;
    QString content;
    FILE *fp=fopen(fn,"r");
    if(fp==nullptr)
    {
        QMessageBox::information(this,"错误","打开文件失败");
    }else {
        while(!feof(fp)){
            char buf[2048]={'\0'};
            fgets(buf,sizeof(buf),fp);
            content+=buf;
        }
        fclose(fp);
        this->textEdit1->setText(content);//将QS里面的字符串放入text里面
    }

}

void MainWindow::onSave()
{
    QString fileName=QFileDialog::getSaveFileName();
    if(fileName.isEmpty())
    {
        return;
    }
    FILE *fp=fopen(fileName.toStdString().data(),"w");
    if(fp==nullptr)
    {
        QMessageBox::information(this,"错误","打开文件失败");
    }else{
        const char*tp=this->textEdit1->toPlainText().toStdString().data();//将界面中的文字转换为 const char*
        fputs(tp,fp);
        fclose(fp);
    }
}

void MainWindow::onAbout()
{
    QMessageBox::information(this,"title","关于");
}

void MainWindow::onExit()
{
    //exit(0);
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

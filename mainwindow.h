#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTextEdit *textEdit1;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QAction *fileOpen;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H

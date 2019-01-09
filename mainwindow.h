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
    QAction *fileOpenAction;
    QAction *fileExitAction;
    QAction *helpAboutAction;
    QAction *editCopyAction;
    QAction *editPasteAction;
    QAction *editCutAction;
    QAction *editSelectAllAction;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onOpen();
    void onAbout();
    void onExit();
    void onCopy();
    void onPaste();
    void onCut();
    void onSelectAll();
};

#endif // MAINWINDOW_H

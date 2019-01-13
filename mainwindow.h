#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTextEdit *textEdit1;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *buildMenu;
    QMenu *helpMenu;
    QAction *fileOpenAction;
    QAction *fileSaveAction;
    QAction *fileExitAction;
    QAction *helpAboutAction;
    QAction *editCopyAction;
    QAction *editPasteAction;
    QAction *editCutAction;
    QAction *editSelectAllAction;
    QAction *buildCompileActinon;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onOpen();
    void onSave();
    void onAbout();
    void onExit();
    void onCopy();
    void onPaste();
    void onCut();
    void onSelectAll();
};

#endif // MAINWINDOW_H

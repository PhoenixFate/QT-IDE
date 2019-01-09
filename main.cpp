#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600,400);
    w.show();

    return a.exec();
}
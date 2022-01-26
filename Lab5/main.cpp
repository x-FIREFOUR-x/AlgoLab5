#include"windows/windowsworker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    WindowsWorker::open_MainWindow();
    return a.exec();
}

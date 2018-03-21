#include "mainwindow.h"
#include <QApplication>
#include <windows.h>

int main(int argc, char *argv[])
{
    //prevent multi-open
    HANDLE hMutex = CreateMutex(NULL, false, (LPCTSTR)"ToDoStack");
    if (GetLastError() == ERROR_ALREADY_EXISTS){
        return 0;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

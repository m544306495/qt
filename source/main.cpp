#include "widget.h"
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widget w;



    w.show();

    return a.exec();
}





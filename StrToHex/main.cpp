#include "hexwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HexWidget w;
    w.show();

    return a.exec();
}

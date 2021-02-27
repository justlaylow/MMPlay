#include "MMPlay.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MMPlayClass w;
    w.show();
    return a.exec();
}

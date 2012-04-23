#include <QtGui/QApplication>
#include "formtest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormTest w;
    w.show();
    
    return a.exec();
}

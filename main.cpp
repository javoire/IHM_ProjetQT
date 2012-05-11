#include <QtGui/QApplication>
#include "filterform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FilterForm w;
    w.show();
    
    return a.exec();
}

#include <QtGui/QApplication>
#include "filterform.h"
#include "filmdisplay.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    FilmDisplay d;
//    d.show();
//
    FilterForm w;
    w.show();
    
    return a.exec();
}

#include "genrecheckbox.h"
#include "iostream"

using namespace std;

genreCheckBox::genreCheckBox(QWidget *parent) :
    QCheckBox(parent)
{

    connect(this, SIGNAL(toggled(bool)), this, SLOT(getsChecked(bool)));
}

void genreCheckBox::getsChecked(bool checked) {
//    if (checked) {
        emit isChecked(checked, this->objectName());
//        cout << this->objectName().toStdString() << endl;
//    }
}

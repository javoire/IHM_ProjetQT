#include "formtest.h"
#include "ui_formtest.h"
#include "iostream"
#include <QtGui>

using namespace std;

FormTest::FormTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormTest)
{

    doubleSlider = new DoubleSliderWidget(this, 219, 20, 1930, 2012);

//    setCentralWidget(doubleSlider);

    connect(doubleSlider, SIGNAL(valueLowChange(int)), this, SLOT(on_DoubleSlider_valueLowChanged(int)));
    connect(doubleSlider, SIGNAL(valueHighChange(int)), this, SLOT(on_DoubleSlider_valueHighChanged(int)));

    ui->setupUi(this);

    ui->doubleSliderLayout->addWidget(doubleSlider);
}

FormTest::~FormTest()
{
    delete ui;
}

void FormTest::on_DoubleSlider_valueLowChanged(int value) {
    cout << value << endl;
    ui->labelYearMin->setText(QString::number(value));
}
void FormTest::on_DoubleSlider_valueHighChanged(int value) {
    cout << value << endl;
    ui->labelYearMax->setText(QString::number(value));
}

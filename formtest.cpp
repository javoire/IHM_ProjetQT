#include "formtest.h"
#include "ui_formtest.h"
#include "iostream"
#include <QtGui>

using namespace std;

FormTest::FormTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormTest)
{

    doubleSlider = new DoubleSliderWidget(this, 300, 20, 1930, 2012);

//    setCentralWidget(doubleSlider);

    connect(doubleSlider, SIGNAL(valueLowChange(int)), this, SLOT(on_DoubleSlider_valueLowChanged(int)));
    connect(doubleSlider, SIGNAL(valueHighChange(int)), this, SLOT(on_DoubleSlider_valueHighChanged(int)));

    ui->setupUi(this);
}

FormTest::~FormTest()
{
    delete ui;
}

void FormTest::on_DoubleSlider_valueLowChanged(int value) {
    cout << value << endl;
}
void FormTest::on_DoubleSlider_valueHighChanged(int value) {
    cout << value << endl;
}

void FormTest::on_yearFromSlider_valueChanged(int value) {
//    cout << value;
//    if (ui->yearFromSlider->value() > ui->yearToSlider->value())
//        ui->yearToSlider->setValue(value);

//    ui->yearFrom->setText(QString::number(value));
}

void FormTest::on_yearToSlider_valueChanged(int value) {
//    cout << value;
//    if (ui->yearToSlider->value() < ui->yearFromSlider->value())
//        ui->yearFromSlider->setValue(value);
//    ui->yearFrom->setText(QString::number(value));
}

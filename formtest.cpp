#include "formtest.h"
#include "ui_formtest.h"
#include "iostream"

using namespace std;

FormTest::FormTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTest)
{

    ui->setupUi(this);
}

FormTest::~FormTest()
{
    delete ui;
}

void FormTest::on_yearFromSlider_valueChanged(int value) {
//    cout << value;
    if (ui->yearFromSlider->value() > ui->yearToSlider->value())
        ui->yearToSlider->setValue(value);

//    ui->yearFrom->setText(QString::number(value));
}

void FormTest::on_yearToSlider_valueChanged(int value) {
//    cout << value;
    if (ui->yearToSlider->value() < ui->yearFromSlider->value())
        ui->yearFromSlider->setValue(value);
//    ui->yearFrom->setText(QString::number(value));
}

#include "formtest.h"
#include "ui_formtest.h"
#include "iostream"
#include <QtGui>

using namespace std;

FormTest::FormTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormTest)
{

    graphWidget = new GraphWidget(this);
//    QWidget *formWidget = new QWidget(this);
//    QHBoxLayout *layout = new QHBoxLayout;

//    layout->addWidget(graphWidget);
//    layout->addWidget(formWidget);

//    setLayout(layout);

    setCentralWidget(graphWidget);

//    ui->setupUi(this);
}

FormTest::~FormTest()
{
    delete ui;
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

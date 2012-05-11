#include "filterform.h"
#include "ui_filterform.h"
#include "iostream"
#include <QtGui>

using namespace std;

FilterForm::FilterForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilterForm)
{
    ui->setupUi(this);

    int yearMin = 1930;
    int yearMax = 2012;

    doubleSlider = new DoubleSliderWidget(this, 201, 25, yearMin, yearMax);

    connect(doubleSlider, SIGNAL(valueLowChange(int)), this, SLOT(on_DoubleSlider_valueLowChanged(int)));
    connect(doubleSlider, SIGNAL(valueHighChange(int)), this, SLOT(on_DoubleSlider_valueHighChanged(int)));

    // fonts
    checkBoxFont.setFamily(QString::fromUtf8("Myriad Pro"));
    checkBoxFont.setPointSize(12);

    QCheckBox *checkBox = new QCheckBox(this);

    checkBox->setObjectName(QString::fromUtf8("checkBox2"));
    checkBox->setText("Check2");
    checkBox->setFont(checkBoxFont);

    ui->labelYearMin->setText(QString::number(yearMin));
    ui->labelYearMax->setText(QString::number(yearMax));

    ui->yearSliderLayout->addWidget(doubleSlider);
    ui->checkBoxesLeft->addWidget(checkBox);

}

FilterForm::~FilterForm()
{
    delete ui;
}

void FilterForm::on_DoubleSlider_valueLowChanged(int value) {
//    cout << value << endl;
    ui->labelYearMin->setText(QString::number(value));
}
void FilterForm::on_DoubleSlider_valueHighChanged(int value) {
//    cout << value << endl;
    ui->labelYearMax->setText(QString::number(value));
}

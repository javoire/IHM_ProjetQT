#include "filterform.h"
#include "ui_filterform.h"
#include "iostream"
#include <QtGui>
#include <QList>
#include <genrecheckbox.h>

using namespace std;

FilterForm::FilterForm(QWidget *parent) : // take a QList here with all the genres in it...
    QMainWindow(parent),
    ui(new Ui::FilterForm)
{
    ui->setupUi(this);

    // temp until QList is received form constructor...
    QList<QString> genres;
    genres.push_back(QString("drama"));
    genres.push_back(QString("action"));
    genres.push_back(QString("romance"));
    genres.push_back(QString("thriller"));
    genres.push_back(QString("adult"));

    importGenresFromList(genres);

    int yearMin = 1930;
    int yearMax = 2012;

    doubleSlider = new DoubleSliderWidget(this, 201, 25, yearMin, yearMax);

    connect(doubleSlider, SIGNAL(valueLowChange(int)), this, SLOT(on_DoubleSlider_valueLowChanged(int)));
    connect(doubleSlider, SIGNAL(valueHighChange(int)), this, SLOT(on_DoubleSlider_valueHighChanged(int)));

    ui->labelYearMin->setText(QString::number(yearMin));
    ui->labelYearMax->setText(QString::number(yearMax));

    ui->yearSliderLayout->addWidget(doubleSlider);

    placeGenreBoxes();

}

void FilterForm::importGenresFromList(QList<QString> genres) {

    QFont checkBoxFont;
    checkBoxFont.setFamily(QString::fromUtf8("Myriad Pro"));
    checkBoxFont.setPointSize(12);

    // create a checkbox item for each genre
    for (int i=0; i < genres.size(); i++) {

        QString genre = genres.at(i);

        genreCheckBox *genreBox = new genreCheckBox();
        genreBox->setFont(checkBoxFont);
        genreBox->setObjectName(genre);
        genreBox->setText(genre);
        connect(genreBox, SIGNAL(isChecked(bool,QString)), this, SLOT(checkToggled(bool, QString)));

        genreCheckBoxes.append(genreBox);
    }
}

void FilterForm::placeGenreBoxes() {

//    connect(checkBox, SIGNAL(toggled(bool)), this, SLOT(checkToggled(bool)));

    // place the checkboxes on UI
    int i;
    for (i = 0; i < genreCheckBoxes.size()/2; i++) { // put half here
        ui->checkBoxesLeft->addWidget(genreCheckBoxes.at(i));
    }

    for (int j = i; j < genreCheckBoxes.size(); j++) { // put half here
        ui->checkBoxesRight->addWidget(genreCheckBoxes.at(j));
    }

}

void FilterForm::checkToggled(bool checked, QString name) {
    cout << checked << endl;
    cout << name.toStdString() << endl;
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

#include "filterform.h"
#include "ui_filterform.h"
#include "iostream"
#include <QtGui>
#include <QList>
#include <genrecheckbox.h>

using namespace std;

FilterForm::FilterForm(QWidget *parent) : // take a QList here with all the genres in it... also take year min and max
    QMainWindow(parent),
    ui(new Ui::FilterForm)
{
    ui->setupUi(this);

    // temp until QList is received form constructor...
    QList<QString> genres;
    genres.push_back(QString("Drama"));
    genres.push_back(QString("Action"));
    genres.push_back(QString("Romance"));
    genres.push_back(QString("Thriller"));
    genres.push_back(QString("Adult"));
    genres.push_back(QString("Science-Fiction"));
    genres.push_back(QString("Adventure"));
    genres.push_back(QString("Mystery"));
    genres.push_back(QString("Horror"));
    genres.push_back(QString("Documentary"));
    genres.push_back(QString("Comedy"));
    genres.push_back(QString("Biography"));
    genres.push_back(QString("Drama"));
    genres.push_back(QString("Action"));
    genres.push_back(QString("Romance"));
    genres.push_back(QString("Thriller"));
    genres.push_back(QString("Adult"));
    genres.push_back(QString("Science-Fiction"));
    genres.push_back(QString("Adventure"));
    genres.push_back(QString("Mystery"));
    genres.push_back(QString("Horror"));
    genres.push_back(QString("Documentary"));
    genres.push_back(QString("Comedy"));
    genres.push_back(QString("Biography"));

    // temp. these should come from constructor also
    int yearMin = 1930;
    int yearMax = 2012;

    // generate UI elements
    placeYearSlider(yearMin, yearMax);
    createGenreCheckBoxes(genres);
    placeGenreBoxes();

}

void FilterForm::placeYearSlider(int yearMin, int yearMax) {


    doubleSlider = new DoubleSliderWidget(this, 201, 25, yearMin, yearMax);

    connect(doubleSlider, SIGNAL(valueLowChange(int)), this, SLOT(DoubleSlider_valueLowChanged(int)));
    connect(doubleSlider, SIGNAL(valueHighChange(int)), this, SLOT(DoubleSlider_valueHighChanged(int)));

    ui->labelYearMin->setText(QString::number(yearMin));
    ui->labelYearMax->setText(QString::number(yearMax));

    ui->yearSliderLayout->addWidget(doubleSlider);

}

bool FilterForm::createGenreCheckBoxes(QList<QString> genres) {

    if (genres.isEmpty())
        return false;

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

        genreCheckBoxes.append(genreBox); // store all in one list
    }

    return true;
}

bool FilterForm::placeGenreBoxes() {

    if(genreCheckBoxes.isEmpty())
        return false;

    // place the checkboxes on UI
    int i;
    for (i = 0; i < genreCheckBoxes.size()/2; i++) { // put half here
        ui->checkBoxesLeft->addWidget(genreCheckBoxes.at(i));
    }

    for (i; i < genreCheckBoxes.size(); i++) { // put rest here
        ui->checkBoxesRight->addWidget(genreCheckBoxes.at(i));
    }

    return true;
}

void FilterForm::checkToggled(bool checked, QString name) {

    if (checked) { // add genre
        chosenGenresList.append(name);
    } else if (!checked) { // remove genre
        int indexToRemove = chosenGenresList.indexOf(name);

        if(!name.isNull())
            chosenGenresList.removeAt(indexToRemove);
    }

    string genres = "";
    for (int i = 0; i < chosenGenresList.size(); i++) {

        genres = genres + chosenGenresList.at(i).toStdString() + " ";

    }
    cout << "current chosen genres: " << genres << endl;

    emit chosenGenres(chosenGenresList);
}

FilterForm::~FilterForm()
{
    delete ui;
}

void FilterForm::DoubleSlider_valueLowChanged(int value) {
//    cout << value << endl;
    ui->labelYearMin->setText(QString::number(value));

    emit yearMinChanged(value);
}
void FilterForm::DoubleSlider_valueHighChanged(int value) {
//    cout << value << endl;
    ui->labelYearMax->setText(QString::number(value));

    emit yearMaxChanged(value);
}

void FilterForm::on_titleInput_textChanged(const QString &arg1)
{
    cout << arg1.toStdString() << endl;
    emit titleChanged(arg1);
}

void FilterForm::on_Search_released()
{
    cout << "search clicked" << endl;
    emit searchButtonClicked();
}

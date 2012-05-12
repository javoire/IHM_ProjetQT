#include "filterform.h"
#include "ui_filterform.h"
#include "iostream"
#include <QtGui>
#include <QList>
#include "genrecheckbox.h"
#include "filmdisplay.h"

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

    connect(doubleSlider, SIGNAL(yearMinChange(int)), this, SLOT(DoubleSlider_yearMinChanged(int)));
    connect(doubleSlider, SIGNAL(yearMaxChange(int)), this, SLOT(DoubleSlider_yearMaxChanged(int)));
    connect(doubleSlider, SIGNAL(yearLowSetByUser(int)), this, SLOT(DoubleSlider_yearMinSetByUser(int)));
    connect(doubleSlider, SIGNAL(yearHighSetByUser(int)), this, SLOT(DoubleSlider_yearMaxSetByUser(int)));

    ui->labelYearMin->setText(QString::number(yearMin));
    ui->labelYearMax->setText(QString::number(yearMax));

    ui->yearSliderLayout->addWidget(doubleSlider);

}

bool FilterForm::createGenreCheckBoxes(QList<QString> genres) {

    if (genres.isEmpty())
        return false;

    QFont checkBoxFont;
    checkBoxFont.setFamily(QString::fromUtf8("Myriad Pro"));
    checkBoxFont.setPointSize(7);

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

void FilterForm::checkToggled(bool isChecked, QString name) {

    cout << isChecked << " " << name.toStdString() << endl;
    emit genreIsClicked(isChecked, name);
}

FilterForm::~FilterForm()
{
    delete ui;
}

// these two are called only when the user releases the mouse: has chosen a year
void FilterForm::DoubleSlider_yearMinSetByUser(int value) {
    emit yearMinChanged(value);
    cout << value << endl;
}
void FilterForm::DoubleSlider_yearMaxSetByUser(int value) {
    emit yearMaxChanged(value);
    cout << value << endl;
}

// these two updates the labels in real time
void FilterForm::DoubleSlider_yearMinChanged(int value) {
//    cout << value << endl;
    ui->labelYearMin->setText(QString::number(value));
}
void FilterForm::DoubleSlider_yearMaxChanged(int value) {
//    cout << value << endl;
    ui->labelYearMax->setText(QString::number(value));
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

void FilterForm::on_buttonPopup_released()
{
    cout << "clicked" << endl;

//    QFrame* popup = new QFrame(this, Qt::Popup | Qt::Window);
//    popup->resize(560,220);
//    popup->setFrameStyle(6);

    QWidget* popup = new QWidget(this, Qt::Popup | Qt::Window);

    FilmDummy *film = new FilmDummy();

    FilmDisplay *fmd = new FilmDisplay(popup, film);

    popup->show();


}

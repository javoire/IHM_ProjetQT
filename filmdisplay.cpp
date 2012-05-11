#include "filmdisplay.h"
#include "ui_filmdisplay.h"
#include "filmdummy.h"
#include <QString>

FilmDisplay::FilmDisplay(QWidget *parent, FilmDummy *film) :
    QWidget(parent),
    ui(new Ui::FilmDisplay)
{
    ui->setupUi(this);

    FilmDummy *film1 = new FilmDummy();

    ui->labelTitle->setText(QString::fromStdString(film1->name()));
    ui->labelGenre->setText(QString::fromStdString(film1->genre()));
    ui->labelRating->setText(QString::number((double)film1->rating()/10));
    ui->labelLength->setText(QString::number(film1->length()).append(" min"));

}

FilmDisplay::~FilmDisplay()
{
    delete ui;
}

#include "filmdisplay.h"
#include "ui_filmdisplay.h"
#include "filmdummy.h"
#include <QString>

FilmDisplay::FilmDisplay(QFrame *parent, FilmDummy *film) :
    QFrame(parent),
    ui(new Ui::FilmDisplay)
{
    ui->setupUi(this);

    parent1 = parent;

    ui->labelTitle->setText(QString::fromStdString(film->name()));
    ui->labelGenre->setText(QString::fromStdString(film->genre()));
    ui->labelRating->setText(QString::number((double)film->rating()/10));
    ui->labelLength->setText(QString::number(film->length()).append(" min"));

}

FilmDisplay::~FilmDisplay()
{
    delete ui;
}

void FilmDisplay::on_buttonClose_released()
{
    parent1->close();
}

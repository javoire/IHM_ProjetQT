#include "filmdisplay.h"
#include "ui_filmdisplay.h"

FilmDisplay::FilmDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilmDisplay)
{
    ui->setupUi(this);
}

FilmDisplay::~FilmDisplay()
{
    delete ui;
}

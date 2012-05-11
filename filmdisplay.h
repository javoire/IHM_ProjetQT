#ifndef FILMDISPLAY_H
#define FILMDISPLAY_H

#include <QWidget>
#include "filmdummy.h"

namespace Ui {
class FilmDisplay;
}

class FilmDisplay : public QWidget
{
    Q_OBJECT
    
public:
    FilmDisplay(QWidget *parent = 0, FilmDummy *film = 0);
    ~FilmDisplay();
    
private:
    Ui::FilmDisplay *ui;
};

#endif // FILMDISPLAY_H

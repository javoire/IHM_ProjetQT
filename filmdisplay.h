#ifndef FILMDISPLAY_H
#define FILMDISPLAY_H

#include <QFrame>
#include "filmdummy.h"

namespace Ui {
class FilmDisplay;
}

class FilmDisplay : public QFrame
{
    Q_OBJECT
    
public:
    FilmDisplay(QFrame *parent = 0, FilmDummy *film = 0);
    ~FilmDisplay();
    Ui::FilmDisplay *ui;
    QFrame *parent1;

private:


private slots:
    void on_buttonClose_released();
};

#endif // FILMDISPLAY_H

#ifndef FILMDISPLAY_H
#define FILMDISPLAY_H

#include <QWidget>

namespace Ui {
class FilmDisplay;
}

class FilmDisplay : public QWidget
{
    Q_OBJECT
    
public:
    explicit FilmDisplay(QWidget *parent = 0);
    ~FilmDisplay();
    
private:
    Ui::FilmDisplay *ui;
};

#endif // FILMDISPLAY_H

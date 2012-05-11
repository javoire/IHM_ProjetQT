#ifndef FILTERFORM_H
#define FILTERFORM_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QSlider>
#include <QLineEdit>
#include <QList>
#include <doublesliderwidget.h>
#include <genrecheckbox.h>

namespace Ui {
class FilterForm;
}

class FilterForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FilterForm(QWidget *parent = 0);
    void placeGenreBoxes();
    void importGenresFromList(QList<QString> genres);
    ~FilterForm();

signals:
    void chosenGenres(QList<QString> genres);
    
public slots:
    void on_DoubleSlider_valueLowChanged(int value);
    void on_DoubleSlider_valueHighChanged(int value);
    void checkToggled(bool checked, QString name);

private:
    Ui::FilterForm *ui;
    QSlider* yearToSlider;
    DoubleSliderWidget* doubleSlider;
    QLineEdit *titleInput;
    QList<QCheckBox*> genreCheckBoxes;

};

#endif // FORMTEST_H

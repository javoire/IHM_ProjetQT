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
    void placeYearSlider(int yearMin, int yearMax);
    void createGenreCheckBoxes(QList<QString> genres);
    ~FilterForm();

signals:
    void chosenGenres(QList<QString> genres);
    void yearMinChanged(int yearMin);
    void yearMaxChanged(int yearMax);
    void titleChanged(QString title);
    void searchButtonClicked();
    
public slots:
    void on_DoubleSlider_valueLowChanged(int value);
    void on_DoubleSlider_valueHighChanged(int value);
    void checkToggled(bool checked, QString name);

private slots:
    void on_titleInput_textChanged(const QString &arg1);

    void on_Search_released();

private:
    Ui::FilterForm *ui;
    QSlider* yearToSlider;
    DoubleSliderWidget* doubleSlider;
    QLineEdit *titleInput;
    QList<QCheckBox*> genreCheckBoxes;
    QList<QString> chosenGenresList;

};

#endif // FORMTEST_H

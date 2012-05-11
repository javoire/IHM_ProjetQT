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
    bool placeGenreBoxes();
    void placeYearSlider(int yearMin, int yearMax);
    bool createGenreCheckBoxes(QList<QString> genres);
    ~FilterForm();

signals:
    void genreIsClicked(bool checked, QString name);
    void yearMinChanged(int yearMin);
    void yearMaxChanged(int yearMax);
    void titleChanged(QString title);
    void searchButtonClicked();
    
public slots:
    void DoubleSlider_yearMinChanged(int value);
    void DoubleSlider_yearMaxChanged(int value);
    void DoubleSlider_yearMinSetByUser(int value);
    void DoubleSlider_yearMaxSetByUser(int value);
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

};

#endif // FORMTEST_H

#ifndef FILTERFORM_H
#define FILTERFORM_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QSlider>
#include <QLineEdit>
#include <QList>
#include <doublesliderwidget.h>.h>

namespace Ui {
class FilterForm;
}

class FilterForm : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FilterForm(QWidget *parent = 0);
    ~FilterForm();
    
private slots:
    void on_DoubleSlider_valueLowChanged(int value);
    void on_DoubleSlider_valueHighChanged(int value);

private:
    Ui::FilterForm *ui;
    QSlider* yearToSlider;
    DoubleSliderWidget* doubleSlider;
    QLineEdit *titleInput;
    QFont checkBoxFont;
    QList<QCheckBox> checkBoxes;

};

#endif // FORMTEST_H

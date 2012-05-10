#ifndef FORMTEST_H
#define FORMTEST_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QSlider>
#include <doublesliderwidget.h>.h>

namespace Ui {
class FormTest;
}

class FormTest : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FormTest(QWidget *parent = 0);
    ~FormTest();
    
private slots:
    void on_DoubleSlider_valueLowChanged(int value);
    void on_DoubleSlider_valueHighChanged(int value);

private:
    Ui::FormTest *ui;
    QSlider* yearToSlider;
    DoubleSliderWidget* doubleSlider;

};

#endif // FORMTEST_H

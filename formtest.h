#ifndef FORMTEST_H
#define FORMTEST_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QSlider>
#include <graphwidget.h>

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
    void on_yearFromSlider_valueChanged(int value);
    void on_yearToSlider_valueChanged(int value);

private:
    Ui::FormTest *ui;
    QSlider* yearToSlider;
    GraphWidget* graphWidget;

};

#endif // FORMTEST_H

#ifndef FORMTEST_H
#define FORMTEST_H

#include <QWidget>
#include <QString>

namespace Ui {
class FormTest;
}

class FormTest : public QWidget
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

};

#endif // FORMTEST_H

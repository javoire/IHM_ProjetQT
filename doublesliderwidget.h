#ifndef DOUBLESLIDERWIDGET_H
#define DOUBLESLIDERWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QCheckBox>
#include <QGroupBox>
#include "sliderhandle.h"

class DoubleSliderWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit DoubleSliderWidget(QWidget *parent = 0, int width = 0, int height = 0, int setValueLow = 1900, int setValueHigh = 2012);
    void itemMoved(SliderHandle *item = 0);
    void itemReleased(SliderHandle *item = 0);
    void calcYearValues(SliderHandle *item = 0);
    void createYearSlider(int width, int height);
    
signals:
    int valueHighChange(int highVal);
    int valueLowChange(int lowVal);

public slots:

private:
    QGraphicsScene *scene;
    QGraphicsRectItem *slider;
    QGraphicsRectItem *sliderBG;
    QPoint leftPoint;
    QPoint rightPoint;
    QPoint sliderPos;
    SliderHandle *handleLeft;
    SliderHandle *handleRight;
    SliderHandle *visibleHandleLeft;
    SliderHandle *visibleHandleRight;
    double sliderHeight;
    double sliderWidth;
    double handleWidth;
    double sliderMinWidth;
    int valueLow;
    int valueHigh;
    QList<double> filmsPerYear;
};

#endif // DOUBLESLIDERWIDGET_H

#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "sliderhandle.h"

class GraphWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = 0);
    void itemMoved(SliderHandle *item = 0);
    void detectCollisions(SliderHandle *item);
    void itemReleased(SliderHandle *item = 0);
    
signals:
    
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

};

#endif // GRAPHWIDGET_H

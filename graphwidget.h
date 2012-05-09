#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "slidergrab.h"

class GraphWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = 0);
    void itemMoved(SliderGrab *item = 0);
    void detectCollisions(SliderGrab *item);
    void itemReleased(SliderGrab *item = 0);
    
signals:
    
public slots:

private:
    QGraphicsScene *scene;
    QGraphicsRectItem *slider;
    QPoint startPoint;
    QPoint endPoint;
    SliderGrab *yearFrom;
    SliderGrab *yearFromHandle;
    SliderGrab *yearTo;
    SliderGrab *yearToHandle;
};

#endif // GRAPHWIDGET_H

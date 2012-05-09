#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "slider.h"

class GraphWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = 0);
    void itemMoved(Slider *item = 0);
    void detectCollisions(Slider *item);
    void itemReleased(Slider *item = 0);
    
signals:
    
public slots:

private:
    QGraphicsScene *scene;
    QGraphicsRectItem *slider;
    QPoint startPoint;
    QPoint endPoint;
    Slider *yearFrom;
    Slider *yearFromHandle;
    Slider *yearTo;
    Slider *yearToHandle;
};

#endif // GRAPHWIDGET_H

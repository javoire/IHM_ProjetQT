#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "slider.h"

class GraphWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = 0);
    void itemMoved(Slider *item = 0);
    void detectCollisions(Slider *item);
    
signals:
    
public slots:

private:
    QGraphicsScene *scene;
    Slider *yearFrom;
    Slider *yearFromHandle;
    Slider *yearTo;
    Slider *yearToHandle;
};

#endif // GRAPHWIDGET_H

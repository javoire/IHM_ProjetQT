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
    
signals:
    
public slots:

private:
    QGraphicsScene *scene;
    Slider *yearFrom;
    
};

#endif // GRAPHWIDGET_H

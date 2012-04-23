#include "graphwidget.h"

GraphWidget::GraphWidget(QWidget *parent) :
    QGraphicsView(parent)
{
     QGraphicsScene *scene = new QGraphicsScene(this);
}

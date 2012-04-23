#ifndef SLIDER_H
#define SLIDER_H

#include <QGraphicsItem>

class GraphWidget;
class QGraphicsSceneMouseEvent;

class Slider : public QGraphicsItem
{
public:
    Slider(GraphWidget *graphWidget);

private:
     GraphWidget *graph;
};

#endif // SLIDER_H

#ifndef SLIDER_H
#define SLIDER_H

#include <QGraphicsItem>

class GraphWidget;
class QGraphicsSceneMouseEvent;

class Slider : public QGraphicsItem
{
public:
    Slider(GraphWidget *graphWidget);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
//    bool collidesWithItem ( const QGraphicsItem * other, Qt::ItemSelectionMode mode );

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    GraphWidget *graph;
};

#endif // SLIDER_H

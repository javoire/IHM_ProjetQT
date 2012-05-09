#ifndef SLIDER_H
#define SLIDER_H

#include <QGraphicsItem>
#include <QGraphicsObject>

class GraphWidget;
class QGraphicsSceneMouseEvent;

class SliderGrab : public QGraphicsObject
{
public:
    SliderGrab(GraphWidget *graphWidget, char *name);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    char *name;

public slots:
    void isDragged();

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void setMovable(bool movable);

private:
    GraphWidget *graph;
    qreal posY;
};

#endif // SLIDER_H

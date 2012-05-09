#ifndef SLIDER_H
#define SLIDER_H

#include <QGraphicsItem>
#include <QGraphicsObject>

class GraphWidget;
class QGraphicsSceneMouseEvent;

class SliderHandle : public QGraphicsObject
{
public:
    SliderHandle(GraphWidget *graphWidget, char *name, double width, double height);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setMovable(bool movable);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    char *name;

public slots:
    void isDragged();

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    GraphWidget *graph;
    qreal posY;
    double width;
    double height;
};

#endif // SLIDER_H

#ifndef SLIDER_H
#define SLIDER_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QLinearGradient>

class DoubleSliderWidget;
class QGraphicsSceneMouseEvent;

class SliderHandle : public QGraphicsObject
{
public:
    SliderHandle(DoubleSliderWidget *graphWidget, char *name, double width, double height);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPen(QPen pen);
    void setBrush(QColor setColor);
    void setMovable(bool movable);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const;
    char *name;

//signals:
//    int xChangedValue(int value);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    DoubleSliderWidget *doubleSlider;
    double width;
    double height;
    QPen pen;
    QColor color;
    QBrush brush;
};

#endif // SLIDER_H

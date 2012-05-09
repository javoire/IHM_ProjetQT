#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <iostream>

#include "sliderhandle.h"
#include "graphwidget.h"

using namespace std;

SliderHandle::SliderHandle(GraphWidget *graphWidget, char *sliderName, double setWidth, double setHeight)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

    width = setWidth;
    height = setHeight;

    name = sliderName;
}

void SliderHandle::setMovable(bool movable) {
    if(movable)
        setFlag(ItemIsMovable, true);
    else
        setFlag(ItemIsMovable, false);
}

QRectF SliderHandle::boundingRect() const
{
//    qreal strokeWidth = 2;
//    return QRectF(30 - strokeWidth, 30 - strokeWidth,
//                  60 + strokeWidth, 60 + strokeWidth);
    return QRect(0, 0, width, height);
}

QPainterPath SliderHandle::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, width, height);
    return path;
}

bool SliderHandle::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {

    return QGraphicsItem::collidesWithItem(other, mode);

}

QVariant SliderHandle::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        graph->itemMoved(this);
        graph->detectCollisions(this);
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void SliderHandle::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    update();
    cout << this->name << endl;
    QGraphicsItem::mousePressEvent(event);
}

void SliderHandle::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void SliderHandle::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    update();
    graph->itemReleased(this);
    QGraphicsItem::mouseReleaseEvent(event);
}

void SliderHandle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(QPen(Qt::red, 0));
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, width, height);
}

void SliderHandle::isDragged() {
    cout << "dragged" << endl;
}

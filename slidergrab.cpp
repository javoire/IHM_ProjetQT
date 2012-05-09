#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <iostream>

#include "slidergrab.h"
#include "graphwidget.h"

using namespace std;

SliderGrab::SliderGrab(GraphWidget *graphWidget, char *sliderName)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

    name = sliderName;
}

QRectF SliderGrab::boundingRect() const
{
    qreal strokeWidth = 2;
    return QRectF(30 - strokeWidth, 30 - strokeWidth,
                  63 + strokeWidth, 63 + strokeWidth);
}

QPainterPath SliderGrab::shape() const
{
    QPainterPath path;
    path.addEllipse(30, 30, 60, 60);
    return path;
}

bool SliderGrab::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {

    return QGraphicsItem::collidesWithItem(other, mode);

}

QVariant SliderGrab::itemChange(GraphicsItemChange change, const QVariant &value)
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

void SliderGrab::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    update();
    cout << this->pos().y() << endl;
    QGraphicsItem::mousePressEvent(event);
}

void SliderGrab::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void SliderGrab::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    update();
    graph->itemReleased(this);
    QGraphicsItem::mouseReleaseEvent(event);
}

void SliderGrab::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(QPen(Qt::red, 0));
    painter->setBrush(Qt::red);
    painter->drawEllipse(30, 30, 60, 60);
}

void SliderGrab::isDragged() {
    cout << "dragged" << endl;
}

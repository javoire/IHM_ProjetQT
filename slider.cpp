#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <iostream>

#include "slider.h"
#include "graphwidget.h"

using namespace std;

Slider::Slider(GraphWidget *graphWidget, char *sliderName)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

    name = sliderName;
}

QRectF Slider::boundingRect() const
{
    qreal strokeWidth = 2;
    return QRectF(30 - strokeWidth, 30 - strokeWidth,
                  63 + strokeWidth, 63 + strokeWidth);
}

QPainterPath Slider::shape() const
{
    QPainterPath path;
    path.addEllipse(30, 30, 60, 60);
    return path;
}

bool Slider::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {

    return QGraphicsItem::collidesWithItem(other, mode);

}

QVariant Slider::itemChange(GraphicsItemChange change, const QVariant &value)
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

void Slider::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    update();
    cout << this->pos().y() << endl;
    QGraphicsItem::mousePressEvent(event);
}

void Slider::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    update();
    QGraphicsItem::mouseMoveEvent(event);
}

void Slider::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    update();
    graph->itemReleased(this);
    QGraphicsItem::mouseReleaseEvent(event);
}

void Slider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(QPen(Qt::red, 0));
    painter->setBrush(Qt::red);
    painter->drawEllipse(30, 30, 60, 60);
}

void Slider::isDragged() {
    cout << "dragged" << endl;
}

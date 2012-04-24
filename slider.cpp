#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <iostream>

#include "slider.h"
#include "graphwidget.h"

using namespace std;

Slider::Slider(GraphWidget *graphWidget)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

    this->setY(20);
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

//bool Slider::collidesWithItem ( const QGraphicsItem * other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape ) {

//    update();
////    cout << other->x() << other->y() << endl;

//    if (this->contains(other->pos())) {
//        cout << 'coll';
//        return true;
//    }
//}

QVariant Slider::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void Slider::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    update();
//    this->setY(30);
    QGraphicsItem::mousePressEvent(event);
}

void Slider::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    update();
//    this->setY(30);
    QGraphicsItem::mouseMoveEvent(event);
}

void Slider::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    update();
//    this->setY(30);
    QGraphicsItem::mouseReleaseEvent(event);
}

void Slider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

//    this->setY(30);

    painter->setPen(QPen(Qt::red, 0));
    painter->setBrush(Qt::red);
    painter->drawEllipse(30, 30, 60, 60);
}

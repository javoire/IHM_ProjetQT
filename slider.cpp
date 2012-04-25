#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <iostream>

#include "slider.h"
#include "graphwidget.h"

using namespace std;

Slider::Slider(GraphWidget *graphWidget, char *name)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);

    sliderName = name;
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

void detectCollision() {

}

bool Slider::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {


    bool collision = QGraphicsItem::collidesWithItem(other, mode);

    if(collision) {
        cout << other->x() << endl;
    }

    return collision;

}

QVariant Slider::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        graph->itemMoved();
        graph->detectCollisions(this);
//        cout << sliderName << endl;
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

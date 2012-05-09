#include "graphwidget.h"
#include "slider.h"
#include "math.h"

#include <iostream>

using namespace std;

GraphWidget::GraphWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, 600, 600);

    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(1), qreal(1));
    setMinimumSize(600, 600);
    setWindowTitle(tr("Slider"));

    yearFrom = new Slider(this, "yearFrom");
    yearTo = new Slider(this, "yearTo");
    yearFromHandle = new Slider(this, "yearFromHandle");
    yearToHandle = new Slider(this, "yearToHandle");

//    startPoint.setX(200);
//    startPoint.setY(300);
//    endPoint.setX(300);
//    endPoint.setY(320);

    yearFrom->setPos(0, 0);
    yearTo->setPos(200, 0);
    yearFromHandle->setPos(yearFrom->x(), 100);
    yearToHandle->setPos(yearTo->x(), 100);

    startPoint.setX(yearFrom->x()+60);
    startPoint.setY(300);
    endPoint.setX(yearTo->x()+60);
    endPoint.setY(320);

    slider = new QGraphicsRectItem(QRect(startPoint, endPoint));

    scene->addItem(slider);
    scene->addItem(yearFrom);
    scene->addItem(yearTo);
    scene->addItem(yearFromHandle);
    scene->addItem(yearToHandle);

//    connect(yearFrom, SIGNAL(xChanged()), yearTo, SLOT(isDragged()));
//    connect(yearFrom, zChanged(), )
}

void GraphWidget::detectCollisions(Slider *item) {

    QList<QGraphicsItem*> allItems = this->items();

    (QGraphicsObject*)item = item;

    int i = 0;
    for (i=0; i<allItems.count(); i++) {

        QGraphicsItem* other = allItems[i];

        if(item == yearTo || item == yearFrom) { // only collide these for now

            if(item != other) { // skip itself
                if(item->collidesWithItem(other)) {

                    double dx = 1;
                    double dy = 1;

                    dx = item->x()-other->x();
                    dy = item->y()-other->y();

                    // distance to center of yearFrom?
                    double dd = sqrt(pow(dx, 2) + pow(dy, 2));

    //                other->moveBy(-dx/dd,-dy/dd); // calculate direction and repel other from item
                    other->moveBy(-dx/dd,0); // calculate direction and repel other from item
                }
            }
        }
    }
}

void GraphWidget::itemReleased(Slider *item) {
    if(item == yearFromHandle)
        item->setY(50);
    if(item == yearToHandle)
        item->setY(50);

}

void GraphWidget::itemMoved(Slider *item) {
    if (item == yearFromHandle) {
        startPoint.setX(item->x());
        yearFrom->setX(item->x());
    }
    if (item == yearToHandle) {
        endPoint.setX(item->x());
        yearTo->setX(item->x());
    }
    if (item == yearFrom )
        yearFromHandle->setX(item->x());
    if (item == yearTo)
        yearToHandle->setX(item->x());

}

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
    yearFromHandle = new Slider(this, "yearFromHandle");
    yearTo = new Slider(this, "yearTo");
    yearToHandle = new Slider(this, "yearToHandle");

    scene->addItem(yearFrom);
    scene->addItem(yearFromHandle);
    scene->addItem(yearTo);
    scene->addItem(yearToHandle);

    yearFrom->setPos(0, 0);
    yearFromHandle->setPos(yearFrom->x(), 100);
    yearTo->setPos(200, 0);
    yearToHandle->setPos(yearTo->x(), 100);

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

void GraphWidget::itemMoved(Slider *item) {
    if (item == yearFromHandle)
        yearFrom->setX(yearFromHandle->x());
    if (item == yearToHandle)
        yearTo->setX(yearToHandle->x());
}

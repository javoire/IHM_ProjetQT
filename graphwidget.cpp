#include "graphwidget.h"
#include "sliderhandle.h"
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

    // global vars
    sliderHeight = 30;
    sliderWidth = 400;
    handleWidth = 50;
    sliderMinWidth = 0 + 2 * handleWidth;
    sliderPos.setX(100);
    sliderPos.setY(200);

    // size of slider
    leftPoint.setX(sliderPos.x());
    leftPoint.setY(sliderPos.y());
    rightPoint.setX(sliderPos.x()+sliderWidth);
    rightPoint.setY(sliderPos.y()+sliderHeight);

    // create the elements
    sliderBG = new QGraphicsRectItem(QRect(leftPoint, rightPoint));
    slider = new QGraphicsRectItem(QRect(leftPoint, rightPoint));
    handleLeft = new SliderHandle(this, "sliderLeft", handleWidth, sliderHeight);
    handleRight = new SliderHandle(this, "sliderRight", handleWidth, sliderHeight);
    visibleHandleLeft = new SliderHandle(this, "sliderLeft", handleWidth, sliderHeight);
    visibleHandleRight = new SliderHandle(this, "sliderRight", handleWidth, sliderHeight);

    visibleHandleLeft->setMovable(false);
    visibleHandleRight->setMovable(false);

    // position handles
    handleRight->setX(rightPoint.x()-handleWidth);
    handleRight->setY(sliderPos.y());
    handleLeft->setX(leftPoint.x());
    handleLeft->setY(sliderPos.y());

    visibleHandleLeft->setPos(handleLeft->pos());
    visibleHandleRight->setPos(handleRight->pos());

    scene->addItem(slider);
    scene->addItem(sliderBG);
    scene->addItem(handleLeft);
    scene->addItem(handleRight);
    scene->addItem(visibleHandleLeft);
    scene->addItem(visibleHandleRight);

}

void GraphWidget::detectCollisions(SliderHandle *item) {

    //    QList<QGraphicsItem*> allItems = this->items();

    //    (QGraphicsObject*)item = item;

    //    int i = 0;
    //    for (i=0; i<allItems.count(); i++) {

    //        QGraphicsItem* other = allItems[i];

    //        if(item == yearTo || item == yearFrom) { // only collide these for now

    //            if(item != other) { // skip itself
    //                if(item->collidesWithItem(other)) {

    //                    double dx = 1;
    //                    double dy = 1;

    //                    dx = item->x()-other->x();
    //                    dy = item->y()-other->y();

    //                    // distance to center of yearFrom?
    //                    double dd = sqrt(pow(dx, 2) + pow(dy, 2));

    //    //                other->moveBy(-dx/dd,-dy/dd); // calculate direction and repel other from item
    //                    other->moveBy(-dx/dd,0); // calculate direction and repel other from item
    //                }
    //            }
    //        }
    //    }
}

void GraphWidget::itemReleased(SliderHandle *item) {
    if ( item == handleLeft)
        item->setY(sliderPos.y());
    if ( item == handleRight)
        item->setY(sliderPos.y());
}

void GraphWidget::itemMoved(SliderHandle *item) {

    if (item == handleLeft) {

        visibleHandleLeft->setX(handleLeft->x()); // move the visual handle with the real handle

        leftPoint.setX(handleLeft->x()); // adjust slider size with handle movement
        slider->setRect(QRect(leftPoint, rightPoint));

        if ( item->x() > handleRight->x()-sliderMinWidth) // collide with and push other handle
            handleRight->setX(item->x()+sliderMinWidth);

        double xmin = sliderBG->rect().topLeft().x(); // find left boundary

        if (item->x() < xmin) // don't exceed sliders boundaries
            item->setX(xmin);
    }

    if (item == handleRight) {

        visibleHandleRight->setX(handleRight->x());

        rightPoint.setX(handleRight->x()+handleWidth);
        slider->setRect(QRect(leftPoint, rightPoint));

        if ( item->x() < handleLeft->x()+sliderMinWidth)
            handleLeft->setX(item->x()-sliderMinWidth);

        double xmax = sliderBG->rect().bottomRight().x();

        if (item->x() > xmax-handleWidth)
            item->setX(xmax-1-handleWidth);
    }

}

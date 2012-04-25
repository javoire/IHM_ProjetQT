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
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(600, 600);
    setWindowTitle(tr("Slider"));

    yearFrom = new Slider(this, "yearFrom");
    yearTo = new Slider(this, "yearTo");

    scene->addItem(yearFrom);
    scene->addItem(yearTo);

    yearFrom->setPos(0, 0);
    yearTo->setPos(100, 200);

}

void GraphWidget::detectCollisions(Slider *item) {

    QList<QGraphicsItem*> allItems = this->items();

    (QGraphicsItem*)item = item;

    int i = 0;
    for (i=0; i<allItems.count(); i++) {

        QGraphicsItem* other = allItems[i];

        if(item != other) { // skip itself
            if(item->collidesWithItem(other)) {

                double dx = 1;
                double dy = 1;

                dx = item->x()-other->x();
                dy = item->y()-other->y();

                // distance to center of yearFrom?
                double dd = sqrt(pow(dx, 2) + pow(dy, 2));

                other->moveBy(-dx/dd,-dy/dd); // calculate direction
            }
        }
    }
}

void GraphWidget::itemMoved() {

//    cout << "mooooved" << endl;

//    if(yearFrom->collidesWithItem(yearTo, Qt::ItemSelectionMode(1)))
//        cout << 12;
//    }
//    else {
//        cout << 100 << endl;
//    }
}

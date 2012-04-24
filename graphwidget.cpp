#include "graphwidget.h"
#include "slider.h"

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

    yearFrom = new Slider(this);
    yearTo = new Slider(this);


    scene->addItem(yearFrom);
    scene->addItem(yearTo);

    yearFrom->setPos(50, 50);
    yearTo->setPos(20, 80);

    if(yearFrom->collidesWithItem(yearTo, Qt::ItemSelectionMode(1)))
        cout << 12;

}

void GraphWidget::itemMoved() {
    cout << 'mooved';
}

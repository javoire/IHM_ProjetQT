#include "doublesliderwidget.h"
#include "sliderhandle.h"
#include "math.h"

#include <iostream>
#include <QGridLayout>
#include <QGroupBox>

using namespace std;

DoubleSliderWidget::DoubleSliderWidget(QWidget *parent, int width, int height, int setValueLow, int setValueHigh) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, width, height);

    valueLow = setValueLow;
    valueHigh = setValueHigh;

    int margin = 0;

    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(1), qreal(1));
//    setMinimumSize(width, height);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle(tr("Slider"));
    setFixedSize(width+margin, height+margin);

    setContentsMargins(QMargins(margin, margin, margin, margin));
    setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    setLineWidth(1);
    createYearSlider(width, height);

}

void DoubleSliderWidget::createYearSlider(int width, int height) {
    // global vars
    sliderHeight = height;
    sliderWidth = width;
    handleWidth = 15;
    sliderMinWidth = 0 + handleWidth;
    sliderPos.setX(0);
    sliderPos.setY(0);

    // size of slider
    leftPoint.setX(sliderPos.x());
    leftPoint.setY(sliderPos.y());
    rightPoint.setX(sliderPos.x()+sliderWidth);
    rightPoint.setY(sliderPos.y()+sliderHeight);

    // create the elements
//    sliderBG = new QGraphicsRectItem(QRect(leftPoint, rightPoint));
    slider = new QGraphicsRectItem(QRect(leftPoint, rightPoint));
    handleLeft = new SliderHandle(this, "sliderLeft", handleWidth, sliderHeight);
    handleRight = new SliderHandle(this, "sliderRight", handleWidth, sliderHeight);
    visibleHandleLeft = new SliderHandle(this, "sliderLeft", handleWidth, sliderHeight);
    visibleHandleRight = new SliderHandle(this, "sliderRight", handleWidth, sliderHeight);

//    sliderBG->setPen(Qt::NoPen);
//    sliderBG->setPen(QPen(QColor(100,100,100,255), 0));
    slider->setPen(Qt::NoPen);

//    sliderBG->setBrush(QColor(230,230,230,255));
    slider->setBrush(QColor(230,230,230,255));

    handleLeft->setBrush(QColor(255,255,255,0));
    handleRight->setBrush(QColor(255,255,255,0));

    handleRight->setZValue(5);
    handleLeft->setZValue(5);
    visibleHandleLeft->setZValue(4);
    visibleHandleRight->setZValue(4);
//    sliderBG->setZValue(0);
    slider->setZValue(1);

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
//    scene->addItem(sliderBG);
    scene->addItem(handleLeft);
    scene->addItem(handleRight);
    scene->addItem(visibleHandleLeft);
    scene->addItem(visibleHandleRight);
}

void DoubleSliderWidget::itemReleased(SliderHandle *item) {

    /*  TODO: improve. the sliderhandle must return to it's place not only on release. bug: it doesnt return on
        release if the cursor leaves the window */

    // return the actual sliderhandle on top of the visual one on release
    if ( item == handleLeft)
        item->setY(sliderPos.y());
    if ( item == handleRight)
        item->setY(sliderPos.y());
}

void DoubleSliderWidget::calcYearValues(SliderHandle *item) {

    double pos = 0;
    double posPercent = 0;

    // get position of handles in percent
    if ( item == handleLeft ) {

        pos = visibleHandleLeft->x();
        posPercent = pos/(sliderWidth-handleWidth*2);

//        cout << static_cast<int>(posPercent)*100 << " %" << endl;

        // emit signal
        int yearMin = valueLow + (valueHigh - valueLow)*posPercent;
        emit valueLowChange(yearMin);

    }

    if ( item == handleRight ) {

        pos = visibleHandleRight->x()-handleWidth;
        posPercent = (pos/(sliderWidth-handleWidth*2));

//        cout << static_cast<int>(posPercent)*100 << " %" << endl;

        // emit signal
        int yearMax = valueLow + (valueHigh - valueLow)*posPercent;
        emit valueHighChange(yearMax);

    }

}

void DoubleSliderWidget::itemMoved(SliderHandle *item) {

    /* "collision" behaviour of slider endpoints */
    if (item == handleLeft) {

        visibleHandleLeft->setX(handleLeft->x()); // move the visual handle with the real handle

        leftPoint.setX(handleLeft->x()); // adjust slider size with handle movement
        slider->setRect(QRect(leftPoint, rightPoint));

        if ( item->x() > handleRight->x()-sliderMinWidth) // collide with and push other handle
            handleRight->setX(item->x()+sliderMinWidth);

        double xmin = 0; // left boundary

        if (item->x() < xmin) // don't exceed sliders boundaries
            item->setX(xmin);

    }

    if (item == handleRight) {

        visibleHandleRight->setX(handleRight->x()+1);

        rightPoint.setX(handleRight->x()+handleWidth);
        slider->setRect(QRect(leftPoint, rightPoint));

        if ( item->x() < handleLeft->x()+sliderMinWidth)
            handleLeft->setX(item->x()-sliderMinWidth);

        double xmax = this->width(); // right boundary

        if (item->x() > xmax-handleWidth)
            item->setX(xmax-1-handleWidth);
    }

    /* return year values */

}
#include <QTimer>
#include "MyGraphicsItem.h"
#include "MyWindow.h"

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
{
    // ...

    MyGraphicsItem *animationItem = new MyGraphicsItem(QPixmap(":/Images/rickLeft.jpg"));
    animationItem->setPos(0, 0);

    scene->addItem(animationItem);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, animationItem, &MyGraphicsItem::move);
    timer->start(16); // Adjust the interval as needed for smoother or faster animation
}

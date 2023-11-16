#include "MyGraphicsItem.h"
#include <QObject>
#include <QGraphicsPixmapItem>

MyGraphicsItem::MyGraphicsItem(QPixmap image, qreal velocity, QObject *parent)
    : QGraphicsPixmapItem(image, nullptr), velocity(5.0) {
    setPos(0, 0); // Initial position
}

void MyGraphicsItem::move()
{
    QPointF currentPosition = pos();
    QPointF newPosition = currentPosition + QPointF(velocity, 0); // Move horizontally
    setPos(newPosition);
}

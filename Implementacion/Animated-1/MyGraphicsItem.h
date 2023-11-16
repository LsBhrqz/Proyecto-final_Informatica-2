#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>

class MyGraphicsItem : public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    MyGraphicsItem(QPixmap image, qreal velocity, QObject *parent = nullptr);
public slots:
    void move();

private:
    qreal velocity;
};
#endif // MYGRAPHICSITEM_H

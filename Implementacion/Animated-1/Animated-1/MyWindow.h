#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsView>
#include "MyGraphicsItem.h"

class MyWindow : public QMainWindow {
    Q_OBJECT

public:
    MyWindow(QWidget *parent = nullptr);
    // ...

private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    MyGraphicsItem *animationItem;
    QPushButton *startButton;
    // ...
};

#endif // MYWINDOW_H

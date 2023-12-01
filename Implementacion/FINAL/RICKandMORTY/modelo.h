#ifndef MODELO_H
#define MODELO_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsEllipseItem>
#include <cmath>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class modelo : public QObject
{
        Q_OBJECT

private:
    bool movimiento = true;

    double velInicial;
    double angTiro;
    double velX = 0;
    double velY = 0;
    double velInY;
    double velInX;
    float coefRest;
    double gravedad;
    double xIn;
    double yIn;
    double coordX;
    double coordY;
    double anchoObj;
    double altoObj;
    double anchoPant;
    double altoPant;

public:
    void constructor(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant);
    double tiempo = 0.05;
    void setValues();

    void collide();

    void jump();

    double bounce(double _velEvent);

    void updateValues();

    bool seMueve();

    double getcoordX();

    double getcoordY();
};
#endif // MODELO_H

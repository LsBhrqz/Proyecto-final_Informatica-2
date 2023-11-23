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

class modelo{
    private:
        bool movimiento = true;
        double tiempo = 0;
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

    public:
        modelo(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav);

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

#ifndef MODELO_H
#define MODELO_H
#include <cstdlib>
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
#include <string>
#include <vector>
#include <time.h>
#include <ctime>


using namespace std;

class modelo : public QObject{
public:
    bool movimiento = true;
    double velInicial;
    double angTiro;
    double velX = 0;
    double velY = 0;
    double velInY;
    double velInX;
    float coefRest;
    vector <string> caras;
    double xIn;
    double yIn;
    double coordX;
    double coordY;
    double anchoObj;
    double altoObj;
    double anchoPant;
    double altoPant;

    void constructor(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant);

    double tiempo = 0.05;
    double tiempoGeneral = 0;
    double gravedad;

    void setValues();

    void collide(bool f);

    void jump();

    double bounce(double _velEvent, bool h);

    void updateValues();

    bool seMueve();

    double getcoordX();

    double getcoordY();

    double angAleatorio();
};

#endif // MODELO_H

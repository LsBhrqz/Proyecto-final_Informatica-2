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
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <string>
#include <vector>
#include <time.h>
#include <ctime>
#include <QProgressBar>

using namespace std;

class modelo : public QObject, public QGraphicsPixmapItem{
public:
    //QProgressBar *barraVida;
    bool movimiento;
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
    bool colEnemigo;

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

    void colisionEnemigo(double posInX, double posInY, double anchoIn, double altoIn, double posDestX, double posDestY, double anchoDest, double altoDest);

    void angAleatorio();
};

#endif // MODELO_H

#include "modelo.h"

void modelo::constructor(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant){
    xIn = _xIn;
    yIn = _yIn;
    angTiro = _angTiro;
    velInicial = _velInicial;
    if(_Grav){
        coefRest = 0.45;
        gravedad = 9.81;
    }
    else{
        coefRest = 1;
        gravedad = 0;
    }
    setValues();
    anchoObj = _anchoObj;
    altoObj = _altoObj;
    anchoPant = _anchoPant;
    altoPant = _altoPant;
}

void modelo::setValues(){
    coordX = xIn;
    coordY = yIn;
    velInY = velInicial * sin(angTiro * (M_PI/180));
    velInX = velInicial * cos(angTiro * (M_PI/180));
}

void modelo::jump(){
    coordX = xIn + (velInX * tiempo);
    coordY = yIn - (velInY * tiempo - (0.5 * gravedad * (tiempo * tiempo)));
    velY = velInY - (gravedad*tiempo);
    velX = velInX;

    qDebug() << "abscisa " << coordX;
    qDebug() << "ordenada " << coordY;
}

double modelo::bounce(double velEvent){
    velEvent = -velEvent * coefRest;
    return velEvent;
}

void modelo::collide(){
    //Colisiones en el eje horizontal
    if(coordX > (anchoPant - anchoObj) || coordX < anchoObj){
        velX = bounce(velX);

        if(coordX > (anchoPant - anchoObj)){
            xIn = coordX - 1;
            yIn = coordY - 1;
        }

        if(coordX < anchoObj){
            xIn = coordX + 1;
            yIn = coordY + 1;
        }

        updateValues();

        qDebug() << "Choque en X";
        qDebug() << "angle " << angTiro;
    }

    //Colisiones en el eje vertical

    if(coordY > (altoPant - altoObj) || coordY < altoObj){
        velY = bounce(velY);

        if(coordY > (altoPant - altoObj)){
            yIn = coordY - 1;
            xIn = coordX - 1;
        }

        if(coordY < altoObj){
            yIn = coordY + 1;
            xIn = coordX + 1;
        }

        updateValues();

        qDebug() << "angle " << angTiro;

        //Condición para parar el rebote
        if (qAbs(velY) < 2.2) {
            velY = 0;
            movimiento = false;
        }
    }

}

void modelo::updateValues(){
    tiempo = 0.05;

    velInicial = pow(((pow(velX,2) + pow(velY,2))), 0.5);
    angTiro = atan2(velY,velX) * 180 / M_PI;
    if(angTiro < 0){
        angTiro += 360;
    }

    velInY = (velInicial * sin(angTiro * (M_PI/180)));
    velInX = (velInicial * cos(angTiro * (M_PI/180)));
    qDebug() << "abscisa " << coordX;
    qDebug() << "ordenada " << coordY;
}

bool modelo::seMueve(){
    if(!movimiento){
        return false;
    }
    return true;
}

double modelo::getcoordX(){
    return coordX;
}

double modelo::getcoordY(){
    return coordY;
}

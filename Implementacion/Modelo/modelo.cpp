#include "modelo.h"

modelo::modelo(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav){
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
    tiempo += 0.05;
}

double modelo::bounce(double velEvent){
    velEvent = -velEvent * coefRest;
    return velEvent;
}

void modelo::collide(){
    //Colisiones en el eje horizontal
    if(coordX > 680){

        velX = bounce(velX);

        updateValues();

        qDebug() << "Choque en X";
        qDebug() << "angle " << angTiro;
    }

    //Colisiones en el eje vertical

    if(coordY > 580){

        velY = bounce(velY);

        updateValues();

        qDebug() << "angle " << angTiro;

        //Condición para parar el rebote
        if (qAbs(velY) < 2.5) {
            velY = 0;
            movimiento = false;
        }
    }
}

void modelo::updateValues(){
    tiempo = 0;
    xIn = coordX - 1;
    yIn = coordY - 1;

    velInicial = pow(((pow(velX,2) + pow(velY,2))), 0.5);
    angTiro = atan2(velY,velX) * 180 / M_PI;
    if(angTiro < 0){
        angTiro += 360;
    }

    velInY = (velInicial * sin(angTiro * (M_PI/180)));
    velInX = (velInicial * cos(angTiro * (M_PI/180)));
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

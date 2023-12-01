#include <arma.h>

arma::arma(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant){
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

bool arma::impacto(int tiempoExplosion){
    while(tiempExplosion >= 0){
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
    return false;
}


bool arma::impactoPared(){
    if(coordX > (anchoPant - anchoObj) || coordX < anchoObj){
        return true;
    }

    else if(coordY > (altoPant - altoObj) || coordY < altoObj){
        return true;
    }

    return false;
}

bool arma::impactoEnemigo(double coordXenemigo, double coordYenemigo){

    if(coordX >  || coordX < ){
        return true;
    }

    else if(coordY > (altoPant - altoObj) || coordY < altoObj){
        return true;
    }

    return false;
}



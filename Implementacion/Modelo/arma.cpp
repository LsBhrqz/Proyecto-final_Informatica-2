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

void arma::setValues(){
    coordX = xIn;
    coordY = yIn;
    velInY = velInicial * sin(angTiro * (M_PI/180));
    velInX = velInicial * cos(angTiro * (M_PI/180));
}

void arma::impacto(){
    //Colisiones en el eje horizontal
    if(coordX > (anchoPant - anchoObj) || coordX < anchoObj){
        if(arma.caras[1] = carabomba){
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
        else{
            delete arma;
        }
    }


    //Colisiones en el eje vertical

    if(coordY > (altoPant - altoObj) || coordY < altoObj){
        if(arma.caras[1] == carabomba){
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
        else{
            delete arma;
        }
    }

    //colisiones contra enemigos


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

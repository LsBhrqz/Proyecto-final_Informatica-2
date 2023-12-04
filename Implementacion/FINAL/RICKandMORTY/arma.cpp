#include <arma.h>

bool arma::impacto(int tiempoExplosion){
    while(tiempoExplosion >= 0){
        bool action = true;
        //Colisiones en el eje horizontal
        if(coordX > (anchoPant - anchoObj) || coordX < anchoObj){
            velX = bounce(velX, action);

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

            velY = bounce(velY, action);

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

        tiempoExplosion -= 0.05;
    }
    return false;
}


bool arma::impacto(){
    if(coordX > (anchoPant - anchoObj) || coordX < anchoObj){
        return true;
    }

    else if(coordY > (altoPant - altoObj) || coordY < altoObj){
        return true;
    }

    return false;
}

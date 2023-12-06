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

    //barraVida= nullptr;
    //barraVida->setRange(0,100);
    //barraVida->setValue(100);
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

double modelo::bounce(double velEvent, bool action){
    if(action){
        velEvent = -velEvent * coefRest;

    }
    else{
        velEvent = 0;
    }
    return velEvent;
}

void modelo::collide(bool action){
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

void modelo::angAleatorio(){
    srand(time(NULL));
    angTiro = 180 + rand()% (360 - 180);

}

void modelo::colisionEnemigo(double posInX, double posInY, double anchoIn, double altoIn, double posDestX, double posDestY, double anchoDest, double altoDest){

    int arreglo1[4]={posInX,posInY,anchoIn,altoIn};
    int arreglo2[4]={posDestX,posDestY,anchoDest, altoDest};
    int x=0,y=1, w=2,h=3;

    int arreglomayorx[4];
    //int arreglomayory[4];
    //int arreglomenory[4];
    int arreglomenorx[4];

    if(arreglo1[x]<= arreglo2[x]){
        for(int i=0; i<4;i++){
            arreglomayorx[i]=arreglo2[i];
            arreglomenorx[i]=arreglo1[i];
        }
    }else{
        for(int i=0; i<4;i++){
            arreglomayorx[i]=arreglo1[i];
            arreglomenorx[i]=arreglo2[i];
        }
    }
    /*
    if(arreglo1[y]<= arreglo2[y]){
        for(int i=0; i<4;i++){
            arreglomayory[i]=arreglo2[i];
            arreglomenory[i]=arreglo1[i];
        }
    }else{
        for(int i=0; i<4;i++){
            arreglomayory[i]=arreglo1[i];
            arreglomenory[i]=arreglo2[i];
        }
    }

*/
    //verifico que estén dentro en la x
    if((arreglomenorx[x]+arreglomenorx[w])>=arreglomayorx[x]){
        colEnemigo=true;
    }else{
        colEnemigo=false;
    }


    /*
    //Primero comparo si los arreglos son iguales en X
    if(arreglo1[x]==arreglo2[x] && (arreglo1[x]+arreglo1[w] == arreglo2[x]+ arreglo2[w]) ){
        //Ahora comparo si son iguales en y
        if(arreglo1[y]==arreglo2[y] && (arreglo1[y]+arreglo1[h] == arreglo2[y]+ arreglo2[h])){
            interseccion[x]= arreglo1[x];interseccion[y]= arreglo1[y];
            interseccion[w]= arreglo1[w];interseccion[h]= arreglo1[h];
            //Quiere decir que son exactamente el mismo
            colEnemigo = true;
        }
    }else{
        //En este caso puede que haya una parte dentro de otra o que no haya interseccion

        //Comparo las x
        if((arreglo1[x] >= arreglo2[x])){
            //Determino la que está más a la derecha

            //interseccion[x]=arreglo1[x];

            //Verifico si la interseccion no existe
            if((arreglo2[x] + arreglo2[w]) <= arreglo1[x]){

                //Las x de una figura están dentro de la otra
            }else if(arreglo1[x]+arreglo1[w] <= arreglo2[x]+arreglo2[w]){
                interseccion[w]= arreglo1[x]+arreglo1[w]-interseccion[x];

                //Una x está dentro de una figura
            }else{
                interseccion[w]=arreglo2[x]+arreglo2[w]-interseccion[x];
            }

        }else{

            //Determino la que está más a la derecha
            interseccion[x]=arreglo2[x];

            //Verifico si la interseccion no existe
            if((arreglo1[x]+ arreglo1[w])<= arreglo2[x]){

                //Las x de una figura están dentro de la otra
            }else if(arreglo2[x]+arreglo2[w] <= arreglo1[x]+arreglo1[w]){
                interseccion[w]= arreglo2[x]+arreglo2[w]-interseccion[x];

                //Una x está dentro de la figura
            }else{
                interseccion[w]=arreglo1[x]+arreglo1[w]-interseccion[x];
            }
        }

        //Despues comparo las y
        if((arreglo1[y] >= arreglo2[y])){

            //Determino la y que está más abajo
            interseccion[y]=arreglo2[y];

            //Evaluo si no existe la intersecion
            if((arreglo1[y] + arreglo1[h]) <= arreglo2[y]){

                //Las y están dentro de la otra figura
            }else if( (arreglo1[y] + arreglo1[h]) >= (arreglo2[y] + arreglo2[h]) ){
                interseccion[h]= arreglo2[y] + arreglo2[h] - interseccion[y];

                //Unas y están dentro de ula otra figura
            }else{
                interseccion[h]= arreglo1[y] + arreglo1[h] - interseccion[y];
            }

        }else{

            //Determino la y que está más abajo
            interseccion[y]=arreglo1[y];

            //Evaluo si no existe la intersecion
            if((arreglo2[y] + arreglo2[h]) <= arreglo1[y]){

                //Las y están dentro de la otra figura
            }else if( (arreglo2[y] + arreglo2[h]) >= (arreglo1[y] + arreglo1[h]) ){
                interseccion[h]= arreglo1[y] + arreglo1[h] - interseccion[y];

                //Unas y están dentro de ula otra figura
            }else{
                interseccion[h]= arreglo2[y] + arreglo2[h] - interseccion[y];
            }
        }
    }
    //arreglar condición
    for(int i = 2; i<4; i++){
        if(interseccion[i] == 0){
            colEnemigo = false;
        }
        else{
            colEnemigo = true;
            break;
        }

    }*/
}

#include <personaje.h>
/*
personaje::personaje(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant){

}
*/
void personaje::disparar(){
    if((personaje.salud >= 0) && (personaje.caras[1] == disparo)){
        arma bola(construir y disparar en dirección a Morty);
    }
}
/*
void personaje::generar(int numtuber){
    for(int i = 0; i < numtuber ; i++){

    }
}
*/
void personaje::morir(){
    //explosión de muerte
}

void personaje::herido(){
    salud -= 5;
}

#ifndef MORTY_H
#define MORTY_H

#include "arma.h"

class Morty : public modelo
{
public:
    Morty();
    int saludMorty;
    arma equipada;
    void manejarMorty();
    void dispararMorty();
    void gameOver();
    bool moverI=false;
    bool moverD= false;
    bool moverArr= false;
    bool moverAb= false;
    int contadorposicionmorty=0;
};


#endif // MORTY_H




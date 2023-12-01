#ifndef MORTY_H
#define MORTY_H
#include <modelo.h>
#include "arma.h"

class Morty : public modelo{
    private:
        int saludMorty;
        arma equipada;
    public:
        Morty(double _xIn, double _yIn, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant);
        void manejarMorty();
        void dispararMorty();
        void gameOver();
};


#endif // MORTY_H

#ifndef MORTY_H
#define MORTY_H
#include <modelo.h>
#include "arma.h"

class Morty : public modelo{
    private:
        int saludMorty;
        arma equipada;
    public:
        void manejarMorty();
        void dispararMorty();
        void gameOver();
};


#endif // MORTY_H

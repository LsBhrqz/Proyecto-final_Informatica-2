#ifndef USUARIO_H
#define USUARIO_H
#include <personaje.h>

class usuario : public personaje{
    private:
        arma equipada;
    public:
        usuario(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant);
        void manejarMorty();
        void dispararMorty();
        void gameOver();
};




#endif // USUARIO_H

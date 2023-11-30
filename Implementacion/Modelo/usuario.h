#ifndef USUARIO_H
#define USUARIO_H
#include <modelo.h>

class usuario : public modelo{
    private:
        int saludMorty;
        arma equipada;
    public:
        usuario(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant);
        void manejarMorty();
        void dispararMorty();
        void gameOver();
};


#endif // USUARIO_H

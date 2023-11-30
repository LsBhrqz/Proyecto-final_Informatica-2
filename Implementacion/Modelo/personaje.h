#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <modelo.h>

class personaje : public modelo{
    private:
        int salud;
        arma bola;
    public:
        personaje(double _xIn, double _yIn, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant);
        void disparar(arma bola);
        void caminar(bool move);
        void morir();
};


#endif // PERSONAJE_H

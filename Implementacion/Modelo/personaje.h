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
        void generar();
        void morir();
        void herido(int salud);
};


#endif // PERSONAJE_H

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <arma.h>

class personaje : public modelo{
private:
    int salud;

public:
    personaje();
    int cara;
    int getSalud();
    void morir();
    void herido();
    void cambiarCara();

};

#endif // PERSONAJE_H

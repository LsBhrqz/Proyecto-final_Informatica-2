#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <arma.h>

class personaje : public modelo, public QGraphicsPixmapItem{
private:
    int salud=100;
public:
    personaje();
    int getSalud();
    void morir();
    void herido();
};

#endif // PERSONAJE_H

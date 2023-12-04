#ifndef ARMA_H
#define ARMA_H
#include "modelo.h"
#include "personaje.h"
class arma : public modelo{
public:
    bool impacto(int tiempoExplosion);
    bool impacto();
};



#endif // ARMA_H

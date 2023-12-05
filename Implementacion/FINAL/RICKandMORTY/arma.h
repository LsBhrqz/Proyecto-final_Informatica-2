#ifndef ARMA_H
#define ARMA_H
#include "modelo.h"

class arma : public modelo{

public:
    bool impacto(int tiempoExplosion);
    void impacto();
    bool impacto(double _coordXenemigo, double _coordYenemigo, double anchoEnemigo, double altoEnemigo);
    void ubicarMorty(double coordXmorty, double coordYmorty, double coordInx, double coordIny);

};


#endif // ARMA_H

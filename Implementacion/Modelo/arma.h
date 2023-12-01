#ifndef ARMA_H
#define ARMA_H
#include "modelo.h"

class arma : public modelo{
    public:
      //arma(double _xIn, double _yIn, double _angTiro, double _velInicial, bool _Grav, double _anchoObj, double _altoObj, double _anchoPant, double _altoPant);
        bool impacto(int tiempoExplosion);
        bool impacto();
        bool impacto(double _coordXenemigo, double _coordYenemigo);
};


#endif // ARMA_H

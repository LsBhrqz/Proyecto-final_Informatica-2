#ifndef MORTY_H
#define MORTY_H

#include "arma.h"
#include <QGraphicsItem>
#include <QPainter>
#include "modelo.h"

class Morty : public modelo, public QGraphicsPixmapItem
{
public:
    Morty(QGraphicsItem* im = nullptr);
    int saludMorty;
    arma equipada;
    void manejarMorty();
    void dispararMorty();
    void gameOver();
    bool moverI=false;
    bool moverD= false;
    bool moverArr= false;
    bool moverAb= false;
    void animar();
};


#endif // MORTY_H




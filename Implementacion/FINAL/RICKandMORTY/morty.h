#ifndef MORTY_H
#define MORTY_H

#include "arma.h"
#include <QGraphicsItem>
#include <QPainter>
#include "modelo.h"

class Morty : public modelo
{
private:
    int saludMorty;
    arma equipada;
public:
    Morty();
    QRectF boundingRect() const;
    void manejarMorty();
    void dispararMorty();
    void gameOver();
    void paint(QPainter *painter);

};


#endif // MORTY_H




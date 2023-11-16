#include "Rick.h"




//Definir el jugador y la imgen
Rick::Rick(QGraphicsItem *im):QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap(":/Images/rickLeft.jpg"));
}

//Simulacion de caminar
void Rick::mov()
{
    if (cont<5)
    {
        setPixmap(QPixmap(":/Images/rickLeft.jpg"));
        //flag=false;
    }
    else if ( cont >5)
    {
        setPixmap(QPixmap(":/Images/rickRight.jpg"));
        //flag=true;
    }
    if (cont==10)cont=0;

    cont++;

}
void Rick::setX(int newX)
{
    x = newX;
}

int Rick::getX() const
{
    return x;
}

int Rick::getY() const
{
    return y;
}

void Rick::setY(int newY)
{
    y = newY;
}

//Definir posicion en la grafica
void Rick::posicion()
{
    setPos(x,y);
}

void Rick::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

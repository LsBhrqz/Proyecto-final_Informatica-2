#include "morty.h"

Morty::Morty(QGraphicsItem *im):QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap(":/img/Mortyfrente.png"));
}

void Morty::gameOver(){

}


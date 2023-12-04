#include "morty.h"

Morty::Morty(QGraphicsItem *im):QGraphicsPixmapItem(im)
{
    setPixmap(QPixmap(":/img/Mortyfrente.png"));
    anchoObj= 83; altoObj=110; gravedad=9.81; coefRest=0;
}

void Morty::gameOver(){

}


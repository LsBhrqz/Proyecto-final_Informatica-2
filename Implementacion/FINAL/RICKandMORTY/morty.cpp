#include "morty.h"

Morty::Morty(){

}

void Morty::paint(QPainter *painter){
    QPixmap pixmap;
    pixmap.load(":/img/Mortyfrente.png");
    painter->drawPixmap(boundingRect(), pixmap, pixmap.rect());
}

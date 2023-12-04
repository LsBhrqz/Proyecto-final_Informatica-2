#include <personaje.h>


void personaje::morir(){
    //explosión de muerte y terminación de nivel
}

void personaje::herido(){
    salud -= 5;
}

int personaje::getSalud(){
    return salud;
}

personaje::personaje(){
    salud=100;
}

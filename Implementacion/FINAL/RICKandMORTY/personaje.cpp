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
    cara = 0;
}

void personaje::cambiarCara() {
    if(cara == 0){
        cara = 1;
        qDebug() << "cambió la cara";
    }
    else if (cara == 1) {
        cara = 2;
    }
    else{
        cara = 0;
    }
}

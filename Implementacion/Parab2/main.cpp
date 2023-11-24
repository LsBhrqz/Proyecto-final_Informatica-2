#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsEllipseItem>
#include <cmath>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>

void updateValues(double &xIn, double &yIn, double &tiempoX, double &tiempoY, double &velInX, double &velInY, double &ang, int &dir, bool &colX, double &velIn, double &velY, QGraphicsEllipseItem &particle);


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Definir la escena y mostrarla

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    scene.setSceneRect(0,0,500, 500);
    view.show();

    // Crear la partícula y dibujarla
    QGraphicsEllipseItem particle(0, 0, 20, 20);
    particle.setBrush(Qt::red);
    scene.addItem(&particle);

    //Definir variables y constantes:

    double tiempoX, tiempoY = 0;
    bool colX = true;

    //Aceleración debido a la gravedad
    double g = 9.81;

    // Coordenadas en x,y

    double xIn = 50;
    double yIn = 250;
    double x = xIn;
    double y = yIn;

    //Velocidad y ángulo inicial
    double velIn = 40;
    double ang = 45;
    double velInX = velIn * cos(ang * (M_PI/180));
    double velInY = velIn * sin(ang * (M_PI/180));
    double velX = velInX; // la vel en x siempre será la misma
    double velY = velInY;

    //double coefRest = 1;
    int dir = 1;

    //Definir el timer y las rutinas al interior
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {

        //En cada ejecución del timer calculamos las posiciones en (x,y)

        x = xIn + velX * tiempoX * dir;
        y = (yIn - (velInY * tiempoY - (0.5 * g * (tiempoY * tiempoY))));
        velY = velInY - g*tiempoY;
        tiempoX +=0.1;
        tiempoY +=0.1;

        //Si hay una colisión, recalculamos parámetros

        //Colisiones en el eje horizontal
        if (x > scene.width() - particle.boundingRect().width() ){ //le resto el ancho de la partícula
            colX = true;
            //particle.setX(scene.width()-particle.boundingRect().width()-2);
            updateValues(xIn, yIn, tiempoX, tiempoY, velX, velY, ang, dir, colX, velIn, velY, particle);

            qDebug() << "Choque en X";
            //timer.stop();
        }

        //Colisiones en el eje vertical

        if (y > scene.height()-particle.boundingRect().height()){
            yIn = scene.height()-particle.boundingRect().height()-1;
            colX = false;
            qDebug() << "angle " << ang << " "<<velY<<velX<<" "<<x<<y<<velIn<<yIn;
            updateValues(xIn, yIn, tiempoX, tiempoY, velX, velY, ang, dir, colX, velIn, velY, particle);

            qDebug() << "angle " << ang << " "<<velY<<velX<<" "<<x<<y<<velIn<<yIn;

            //Condición para parar el rebote
            if (qAbs(velY) < 1.0) {
                velY = 0;
                timer.stop();

            }
        }
        // Actualizar la posición de la partícula
        particle.setPos(x, y);

        // Actualizar tiempo
        qDebug() << velY << velX ;




    });
    QPushButton pushButton("Change Gravity");
    QObject::connect(&pushButton, &QPushButton::clicked, [&]() {
        g *= 2;
    });

    QVBoxLayout layout;
    layout.addWidget(&view);
    layout.addWidget(&pushButton);

    // Create a main widget, set the layout, and set it as the central widget
    QWidget mainWidget;
    mainWidget.setLayout(&layout);
    mainWidget.show();


    timer.start(15);

    return a.exec();
}

void updateValues(double &xIn, double &yIn, double &tiempoX, double &tiempoY, double &velInX, double &velInY, double &ang, int &dir, bool &colX, double &velIn, double &velY, QGraphicsEllipseItem &particle){

    if (colX){ //Falta recalcular el ángulo
        dir=dir*(-1);
        xIn = particle.x();
        tiempoX = 0;
    }
    else{
        //yIn = particle.y();
        xIn = particle.x();

        //velY *=0.5;

        tiempoY = 0;
        tiempoX = 0;
        velInY = velIn * sin(ang * (M_PI/180));
        velInX = velInX*0.5;
        velIn = sqrt(pow(velInX,2)+pow(velInY,2)) * 0.5;
        //ang = -atan2(velInY, velInX) * 180 / M_PI;
    }



}

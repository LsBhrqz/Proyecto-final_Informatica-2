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

/*
void collide();

void jump();

void bounce();

void updateValues();
*/

void updateValues(double &xIn, double &yIn, double &coordX, double &tiempo, double &coordY, double &velX, double &velY, double &velInX, double &velInY, double &angTiro, double &velInicial, QGraphicsEllipseItem &particle);


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Definir la escena y mostrarla

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    scene.setSceneRect(0,0,700,600);
    view.show();


    // Crear la partícula y dibujarla
    QGraphicsEllipseItem particle(0, 0, 10, 10);
    particle.setBrush(Qt::red);
    scene.addItem(&particle);

    //Definir variables y constantes:

    double tiempo = 0;
    double velInicial = 30;
    double angTiro = 30;
    double velX = 0;
    double velY = 0;
    double velInY = velInicial * sin(angTiro * (M_PI/180));
    double velInX = velInicial * cos(angTiro * (M_PI/180));
    float coefRest = 0.45;
    double gravedad = 9.81;
    double xIn = 100;
    double yIn = 100;
    double coordX = xIn;
    double coordY = yIn;

    //Definir el timer y las rutinas

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {

        //En cada ejecución del timer calculamos las posiciones en (x,y)

        coordX = xIn + (velInX * tiempo);
        coordY = yIn - (velInY * tiempo - (0.5 * gravedad * (tiempo * tiempo)));
        velY = velInY - (gravedad*tiempo);
        velX = velInX;

        //Si hay una colisión, recalculamos parámetros

        //Colisiones en el eje horizontal
        if(coordX > scene.width() - particle.boundingRect().width()){

            velX = -velX * coefRest;

            updateValues(xIn, yIn, coordX, tiempo, coordY, velX, velY, velInX, velInY, angTiro, velInicial, particle);

            qDebug() << "Choque en X";
            qDebug() << "angle " << angTiro;
        }

        //Colisiones en el eje vertical

        if(coordY > scene.height()-particle.boundingRect().height()){

            velY = -velY * coefRest;

            updateValues(xIn, yIn, coordX, tiempo, coordY, velX, velY, velInX, velInY, angTiro, velInicial, particle);

            qDebug() << "angle " << angTiro;

            //Condición para parar el rebote
            if (qAbs(velY) < 2.5) {
                velY = 0;
                timer.stop();

            }
        }
//updateValues(xIn, yIn, coordX, tiempo, coordY, velX, velY, velInX, velInY, angTiro, velInicial, particle);
        // Actualizar la posición de la partícula
        particle.setPos(coordX, coordY);

        // Actualizar tiempo
        qDebug() << velY << velX ;

        tiempo += 0.05;

    });
    QPushButton pushButton("Change Gravity");
    QObject::connect(&pushButton, &QPushButton::clicked, [&]() {
        gravedad *= 2;
    });

    QVBoxLayout layout;
    layout.addWidget(&view);
    layout.addWidget(&pushButton);

    // Create a main widget, set the layout, and set it as the central widget
    QWidget mainWidget;
    mainWidget.setLayout(&layout);
    mainWidget.show();


    timer.start(15);

    return app.exec();
}

void updateValues(double &xIn, double &yIn, double &coordX, double &tiempo, double &coordY, double &velX, double &velY, double &velInX, double &velInY, double &angTiro, double &velInicial, QGraphicsEllipseItem &particle){

    tiempo = 0;
    xIn = coordX - 1;
    yIn = coordY - 1;

    velInicial = pow(((pow(velX,2) + pow(velY,2))), 0.5);
    angTiro = atan2(velY,velX) * 180 / M_PI;
    if(angTiro < 0){
        angTiro += 360;
    }

    velInY = (velInicial * sin(angTiro * (M_PI/180)));
    velInX = (velInicial * cos(angTiro * (M_PI/180)));

}

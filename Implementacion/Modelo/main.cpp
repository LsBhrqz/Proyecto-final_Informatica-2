#include "mainwindow.h"
#include "modelo.h"

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

    modelo pelota(100, 100, 30, 80, false);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&](){

        pelota.jump();

        pelota.collide();

        particle.setPos(pelota.getcoordX(), pelota.getcoordY());

        if(!(pelota.seMueve())){
            timer.stop();
        }

    });

    QPushButton pushButton("Change Gravity");
    QObject::connect(&pushButton, &QPushButton::clicked, [&]() {

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

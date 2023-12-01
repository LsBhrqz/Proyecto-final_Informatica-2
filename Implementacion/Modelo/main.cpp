#include "mainwindow.h"
#include "modelo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Definir la escena y mostrarla

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    scene.setSceneRect(0,0,800,650);
    view.show();


    // Crear la partícula y dibujarla
    QGraphicsEllipseItem particle(0, 0, 10, 10);
    particle.setBrush(Qt::red);
    scene.addItem(&particle);

    double anchoPant = scene.width();
    double altoPant = scene.height();
    double anchoObj = particle.boundingRect().width();
    double altoObj = particle.boundingRect().height();

    modelo pelota(700.0, 600.0, 30.0, 180.0, true, anchoObj, altoObj, anchoPant, altoPant);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&](){
        //Evaluar si el algoritmo sirve, de lo contrario cambiar la estrucutra
        //Reevaluar tiros y conservaciones
        //Tener en cuenta herencias

        pelota.jump();

        pelota.collide();

        particle.setPos(pelota.getcoordX(), pelota.getcoordY());

        if(!(pelota.seMueve()) || pelota.tiempoGeneral > 30){
            timer.stop();
        }
        else{
            pelota.tiempo += 0.05;
            pelota.tiempoGeneral += 0.05;
        }

    });

    QPushButton pushButton("Change Gravity");
    QObject::connect(&pushButton, &QPushButton::clicked, [&]() {
        pelota.gravedad = 0;
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

#include "mainwindow.h"
#include "modelo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Definir la escena y mostrarla

    QGraphicsScene scene(0,0,800,800);
    QGraphicsView view(&scene);
    scene.setSceneRect(0,0,850,850);
    view.show();

    scene.setBackgroundBrush(QPixmap(":/fotos/presentacion.png").scaled(850, 850));

    // Crear la partícula y dibujarla
    QGraphicsEllipseItem particle(0, 0, 10, 10);
    particle.setBrush(Qt::red);
    scene.addItem(&particle);

    double anchoPant = scene.width();
    double altoPant = scene.height();
    double anchoObj = particle.boundingRect().width();
    double altoObj = particle.boundingRect().height();

    modelo pelota(300, 200, 80, 200, true, anchoObj, altoObj, anchoPant, altoPant);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&](){
        pelota.jump();

        pelota.collide();

        particle.setPos(pelota.getcoordX(), pelota.getcoordY());

        if(!(pelota.seMueve())){
            timer.stop();
        }
        else{
            pelota.tiempo += 0.05;
        }

    });



    QVBoxLayout layout;
    layout.addWidget(&view);

    // Create a main widget, set the layout, and set it as the central widget
    QWidget mainWidget;
    mainWidget.setLayout(&layout);
    mainWidget.show();


    timer.start(15);

    return app.exec();
}

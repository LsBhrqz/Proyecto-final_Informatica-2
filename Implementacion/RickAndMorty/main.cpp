/*#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Crear una etiqueta para mostrar la imagen
    QLabel label;

    // Cargar la imagen utilizando QPixmap
    QPixmap pixmap("C:/PROYECTOfINALiNFORMATICA/Proyecto-final_Informatica-2/Implementacion/RickAndMorty/imagenes/presentacion.png");  // Cambia "ruta_de_tu_imagen.jpg" con la ruta de tu imagen

    // Ajustar la imagen a la etiqueta
    label.setPixmap(pixmap.scaled(label.size(), Qt::KeepAspectRatio));

    // Mostrar la etiqueta
    label.show();

    return a.exec();
}
*/

/*#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
*/
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Crear la escena y la vista
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    // Crear un QGraphicsPixmapItem para la imagen
    QGraphicsPixmapItem pixmapItem;

    // Cargar la imagen desde un archivo
    QPixmap imagen("C:/PROYECTOfINALiNFORMATICA/Proyecto-final_Informatica-2/Implementacion/RickAndMorty/imagenes/presentacion.png");  // Reemplaza "ruta_de_tu_imagen.png" con la ruta de tu imagen
    pixmapItem.setPixmap(imagen);

    // Agregar el QGraphicsPixmapItem a la escena
    scene.addItem(&pixmapItem);

    // Crear un temporizador
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        // Cambiar la imagen cada vez que el temporizador se activa
        QPixmap nuevaImagen("C:/PROYECTOfINALiNFORMATICA/Proyecto-final_Informatica-2/Implementacion/RickAndMorty/imagenes/presentacion.png");  // Reemplaza "nueva_ruta_de_imagen.png" con la nueva ruta
        pixmapItem.setPixmap(nuevaImagen);
    });

    // Configurar el intervalo del temporizador en milisegundos (por ejemplo, 1000 para 1 segundo)
    timer.start(10000);

    // Mostrar la vista
    view.show();

    return a.exec();
}

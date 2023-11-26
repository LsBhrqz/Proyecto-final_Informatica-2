#ifndef PRESENTADOR_H
#define PRESENTADOR_H

#include <QCoreApplication>
#include <QTimer>
#include <QPixmap>
#include <QLabel>

class presentador : public QObject {
    Q_OBJECT

public slots:
    void abrirImagen() {
        etiqueta.show();

        // Cargar la imagen usando QPixmap desde el recurso
        QPixmap nuevaImagen(":/fotos/presentacion.png");
        nuevaImagen.scaled(1000, 500);

        // Actualizar la imagen en la etiqueta
        etiqueta.setPixmap(nuevaImagen);

        if(tiempoTranscurrido >= 10000){
            temporizador.stop();
        } else {
            tiempoTranscurrido += temporizador.interval();
        }
    }

public:
    QTimer temporizador;
    int tiempoTranscurrido = 0;
    QLabel etiqueta;
};


#endif // PRESENTADOR_H


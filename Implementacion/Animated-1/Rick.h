#ifndef RICK_H
#define RICK_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Rick:public QObject,
                public QGraphicsPixmapItem //hereda de QObject (para características de objetos de Qt) y de QGraphicsPixmapItem (para objetos gráficos en una escena gráfica de Qt).
{
    Q_OBJECT
private:
    int x;
    int y;
    bool flag=true;
    int cont=0;
public:
    Rick(QGraphicsItem* im = 0); //se inicializa con nullptr en el constructor. Valor predeterminado que se asigna al parámetro en caso de que no se proporcione ningún valor al crear un objeto de la clase.
    void setX(int newX);
    void setY(int newY);
    int getX() const;
    int getY() const;

    //Definir posicion graficar
    void posicion();
    void posicion(int newX, int newY);
    //Simular caminar
    void mov();
};

#endif // RICK_H

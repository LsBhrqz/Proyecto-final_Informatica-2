#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) // Se llama al constructor de la clase base QMainWindow, pasándole parent como argumento, que es un puntero al widget padre.
    , ui(new Ui::MainWindow) // Se inicializa el miembro ui con un nuevo objeto de la clase Ui::MainWindow
    //La clase Ui::MainWindow es una clase generada automáticamente por Qt Designer, que contiene la interfaz de usuario diseñada
      //visualmente para la ventana principal. Este objeto ui se utiliza para acceder a los elementos de la interfaz gráfica definidos
      //en el archivo de diseño (ui_mainwindow.h).
{
    ui->setupUi(this);
    scene = new QGraphicsScene();    //Definir Escena para montar la "obra"
    scene->setSceneRect(0,0,500,500); //Definir los limites de la escena
    scene->setSceneRect(ui->graphicsView->rect());
    ui->graphicsView->setScene(scene); //Dar la escena al graphics
    scene->addRect(scene->sceneRect()); //Dibujar cuadrado de la escena


    //Adicionar Background

    QPixmap backgroundImage(":/Images/background.jpg");
    QGraphicsPixmapItem *bgImage = new QGraphicsPixmapItem(backgroundImage);
    bgImage->setPos(0, 0);
    scene->addItem(bgImage);


    jugador = new Rick();
    jugador->posicion(250,250);
    scene->addItem(jugador);




    //Definir timer y conectar con funcion hmov
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(hmov()));
    timer->stop();


    //Timer para el BG


    QTimer* bgTimer = new QTimer(this);
    connect(bgTimer, &QTimer::timeout, this, [this, bgImage]() {
        // Mover la imagen horizontalmente
        const int moveSpeed = 2;  // Ajustar la posición en pixeles
        qreal newX = bgImage->x() - moveSpeed;  // Mover a la derecha o desplazar a la izq.
        qDebug() << "Pos" << bgImage->pixmap().width();
        qDebug() << "Pos2" << newX;
        // Organizar el loop
        if (newX <= -(bgImage->pixmap().width()-500)) {
            //newX = scene->width();
            newX=0;
        }
        bgImage->setX(newX);  // Set the new x-coordinate
    });

    // Ajuste del loop del timer
    bgTimer->start(30);  // ¿Qué pasa si cambio este valor? ¿Cómo afecta el movimiento?




}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete jugador;
    delete timer;
    delete bgImage;

}



//Funcion de teclas
void MainWindow::keyPressEvent(QKeyEvent *event){       //Funciones de teclas
    if(event->key()==Qt::Key_F4) close();

    if(event->key()==Qt::Key_D ){
        if(jugador->getX()>(500-36)) jugador->posicion(0,jugador->getY());
        jugador->setX(jugador->getX()+vel);
    }

    if(event->key()==Qt::Key_A){
        jugador->setX(jugador->getX()-vel);
    }

    if(event->key()==Qt::Key_W){
        jugador->setY(jugador->getY()-vel);
    }

    if(event->key()==Qt::Key_S){
        jugador->setY(jugador->getY()+vel);
    }
    jugador->mov();
    jugador->posicion();
}

//Movimiento automatico con timer
void MainWindow::hmov()
{
    if(jugador->getX()>(500-36)) jugador->posicion(0,jugador->getY());
    jugador->setX(jugador->getX()+1);
    jugador->posicion();
}

//Si se presiona el boton
void MainWindow::on_pushButton_clicked()
{
    if (timer->isActive()) timer->stop();
    else timer->start(5);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    // Tomar la posición del clic
    QPointF mousePos = ui->graphicsView->mapToScene(event->pos());

        createShotAnimation(mousePos);
}


void MainWindow::createShotAnimation(const QPointF &shootPosition) {
        //QPointF jugadorPos = jugador->pos();
        //QGraphicsEllipseItem *shot = new QGraphicsEllipseItem();
        QPointF jugadorPos = jugador->pos(); // Tomar la posición
        QGraphicsEllipseItem *shot = new QGraphicsEllipseItem(0, 0, 10, 10);
        shot->setPos(jugadorPos); // Se crea y se asigna la pos del jugador
        shot->setBrush(QBrush(Qt::red));
        scene->addItem(shot);
        //qDebug() << "Pos Tiro " << shot->pos();
        //qDebug() << "Pos Jugador " << jugadorPos;
        //qDebug() << "Direcc" << shootPosition-jugadorPos;


        // Crear un timer para que se muestre la animación (loop)
        QTimer *shotTimer = new QTimer(this);
        connect(shotTimer, &QTimer::timeout, [this, shot, shootPosition,shotTimer]() { //El código de la función se ejecuta una vez se termina el timer
            // calcular el siguiente paso
            QPointF shotPos = shot->pos();
            //qDebug() << "Tiro" << shotPos;

            QPointF shotMovement = calculateShotMovement(shotPos, shootPosition);

            // Moverse más cerca del destino
            shot->moveBy(shotMovement.x(), shotMovement.y());

            // Revisar si llega a un punto definido
            if (reachedTarget(shotPos, shootPosition)) {
                shotTimer->stop();
                scene->removeItem(shot); // Borrelo una vez llegue
                delete shot;
            }
        });
        shotTimer->start(50);
}


/*QPointF MainWindow::calculateShotMovement(const QPointF &currentPos, const QPointF &targetPos) {
        // Calculate the movement vector for the shot's animation step
        // Calculate the direction vector from the current position to the target
        qDebug() << "Pos Tiro " << targetPos;
        qDebug() << "Pos Actual " << currentPos;
        QPointF direction = targetPos - currentPos;
        qDebug() << "Resta " << direction;

        // Normalize the direction vector
        qreal distance = qSqrt(direction.x() * direction.x() + direction.y() * direction.y());
        if (distance > 0) {
        direction /= distance;
        }

        // Define a fixed speed for the shot's movement
        qreal speed = 2.0;

        // Adjust the magnitude for the step size by multiplying the normalized direction by the speed
        return direction * speed;
}*/


QPointF MainWindow::calculateShotMovement(const QPointF &currentPos, const QPointF &targetPos) {
    // Calcular el movimiento
    //qDebug() << "Pos 1 " << currentPos;
    //qDebug() << "Pos 2 " << targetPos;
    QPointF direction = targetPos - currentPos;
    direction *= 0.1; // Paso
    //qDebug() << "Dir " << direction;
    return direction;
}

bool MainWindow::reachedTarget(const QPointF &currentPos, const QPointF &targetPos) {
    return (QPointF(currentPos - targetPos).manhattanLength() < 5); //
}

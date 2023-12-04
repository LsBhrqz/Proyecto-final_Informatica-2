#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QKeyEvent>
#include <QDebug>
#include <QTime>

int ancho_pantalla= 1280;
int alto_pantalla=722;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene),
    JUGAR(nullptr),
    nivel1(nullptr),
    nivel2(nullptr)
{
   // setFocusPolicy(Qt::StrongFocus);
    ui->setupUi(this);
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, ancho_pantalla, alto_pantalla);
    setFixedSize(ancho_pantalla+20, alto_pantalla+20);


    ui->graphicsView->resize(ancho_pantalla, alto_pantalla);
    //ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    //ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/img/presentacion.png").scaled(ancho_pantalla, alto_pantalla));


    JUGAR = new QPushButton(QIcon(":/img/logo.png"), " JUGAR", ui->centralwidget);

    // Establecer la posición y el tamaño del botón en el widget
    JUGAR->setGeometry(1055, 645, 150, 50);

    JUGAR->setStyleSheet("QPushButton { background-color: red; border: 2px solid darkred; border-radius: 5px; padding: 5px; color: white; font-size: 16px; } QPushButton:hover { background-color: darkred; }");

    // Conectar la señal clicked() del botón a una función
    connect(JUGAR, &QPushButton::clicked, this, &MainWindow::on_JUGAR_Clicked);


    nivel1 = new QPushButton("NIVEL 1", ui->centralwidget);
    nivel1->setObjectName("nivel1");
    nivel1->hide();

    // Establecer la posición y el tamaño del botón en el widget
    nivel1->setGeometry(100, 100, 350, 194);

    nivel1->setStyleSheet("QPushButton { background-image: url(:/img/nivel1.png); background-color: red; border: 2px solid darkred; border-radius: 5px; padding: 5px; color: white; font-size: 40px; } QPushButton:hover { background-color: darkred; }");

    // Conectar la señal clicked() del botón a una función
    connect(nivel1, &QPushButton::clicked, this, &MainWindow::on_Nivel1_Clicked);

    nivel2 = new QPushButton("NIVEL 2", ui->centralwidget);
    nivel2->setObjectName("nivel2");
    nivel2->hide();

    // Establecer la posición y el tamaño del botón en el widget
    nivel2->setGeometry(900, 100, 350, 194);

    nivel2->setStyleSheet("QPushButton { background-image: url(:/img/nivel2.jpg); background-color: blue; border: 2px solid darkblue; border-radius: 5px; padding: 5px; color: white; font-size: 40px; } QPushButton:hover { background-color: darkblue; }");

    // Conectar la señal clicked() del botón a una función
    connect(nivel2, &QPushButton::clicked, this, &MainWindow::on_Nivel2_Clicked);

    // En el constructor de MainWindow


    //connect(this, &MainWindow::teclaPresionadaSignal, this, &MainWindow::moverMorty);

}



void MainWindow::on_JUGAR_Clicked()
{
    scene->setBackgroundBrush(QPixmap(":/img/fondoniveles.jpg").scaled(ancho_pantalla, alto_pantalla));
    JUGAR->hide();
    nivel1->show();
    nivel2->show();
}

void MainWindow::on_Nivel1_Clicked()
{
    scene->setBackgroundBrush(QPixmap(":/img/fondohepatitisB.png").scaled(ancho_pantalla, alto_pantalla));
    nivel1->hide();
    nivel2->hide();

    //Llamo a la función que pone a correr el nivel uno con los Qtimers y todo
   /*
    while(continuarj){
        continuidadnivel1(continuarj, scene);
    }*/
    morty= new Morty();
    morty->constructor(200.00, 560.0, 0.0, 0.0, true, 83.0, 110.0, 1280.0, 722.0);
    morty->setPos(morty->getcoordX(), morty->getcoordY());
    scene->addItem(morty);

    // En tu constructor de MainWindow

}

void MainWindow::on_Nivel2_Clicked()
{
    scene->setBackgroundBrush(QPixmap(":/img/fondotuberculosis.jpg").scaled(ancho_pantalla, alto_pantalla));
    nivel1->hide();
    nivel2->hide();
}

void MainWindow::animar(){
    morty->xIn=morty->coordX;
    morty->yIn= morty->coordY;
    morty->jump();
    collideM();
    if(permitirmovx && permitirmovy){
        morty->setPos(morty->coordX, morty->coordY);
    }
    morty->tiempo+=0.05;

}

void MainWindow::collideM(){
    if(morty->coordX > (morty->anchoPant - morty->anchoObj) || morty->coordX < 0){
        if(morty->coordX > (morty->anchoPant - morty->anchoObj)){
            //Derecha
            morty->coordX-=15;
        }else{
            //Izquierda
            morty->coordX+=15;
        }
        morty->velX=morty->bounce(morty->velX, false);
        permitirmovx= false;
    }else{
        permitirmovx= true;
    }

    if(morty->coordY > 560 || morty->coordY < 0){
        if(morty->coordY > 560){
            //Abajo
            morty->coordY=560;
            morty->tiempo=0;
            tempo->stop();
        }else{
            //Arriba
            morty->coordY=0;
        }
        morty->velX=0;
        morty->velY= morty->bounce(morty->velY, false);
        permitirmovy= false;

    }else{
        permitirmovy= true;
    }
}



// En el cpp de MainWindow
void MainWindow::keyPressEvent(QKeyEvent *event) {
    permitirmovx=true; permitirmovy=true;
    collideM();
    if (event->key() == Qt::Key_A) {
        collideM();
        if(permitirmovx){
            morty->velInX=-4;
            qDebug() << "izquierda";
            if(cont==0){
                morty->setPixmap(QPixmap(":/img/Mortyizquierda.png"));
                cont=1;
            }else{
                morty->setPixmap(QPixmap(":/img/Mortyizquierdaavanza.png"));
                cont=0;
            }
            morty->setPos(morty->getcoordX()-15, morty->getcoordY());
            morty->coordX-=15;
        }
    } else if (event->key() == Qt::Key_W)  {
        collideM();
        if(permitirmovy){
            qDebug() << "Arriba-izquierda";
            morty->velInY=10;
            tempo= new QTimer(this);
            connect(tempo, SIGNAL(timeout()), this, SLOT(animar()));
            tempo->start(10);
        }
    } else if (event->key()== Qt::Key_D) {
        collideM();
        if(permitirmovx){
            morty->velInX=+4;
            qDebug() << "Derecha";
            if(cont==0){
                morty->setPixmap(QPixmap(":/img/Mortyderecha.png"));
                cont=1;
            }else{
                morty->setPixmap(QPixmap(":/img/Mortyderechaavanza.png"));
                cont=0;
            }
            morty->setPos(morty->getcoordX()+15, morty->getcoordY());
            morty->coordX+=15;
        }

    }


}


MainWindow::~MainWindow()
{
    delete scene;
    scene = nullptr;
    delete ui;
    delete JUGAR;
    delete nivel1;
    delete nivel2;
    delete timerMorty;
    delete morty;
}


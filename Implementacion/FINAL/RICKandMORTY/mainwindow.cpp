#include "mainwindow.h"

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

    JUGAR->setGeometry(1055, 645, 150, 50);

    JUGAR->setStyleSheet("QPushButton { background-color: red; border: 2px solid darkred; border-radius: 5px; padding: 5px; color: white; font-size: 16px; } QPushButton:hover { background-color: darkred; }");

    connect(JUGAR, &QPushButton::clicked, this, &MainWindow::on_JUGAR_Clicked);


    nivel1 = new QPushButton("NIVEL 1", ui->centralwidget);
    nivel1->setObjectName("nivel1");
    nivel1->hide();

    nivel1->setGeometry(100, 100, 350, 194);

    nivel1->setStyleSheet("QPushButton { background-image: url(:/img/nivel1.png); background-color: red; border: 2px solid darkred; border-radius: 5px; padding: 5px; color: white; font-size: 40px; } QPushButton:hover { background-color: darkred; }");

    connect(nivel1, &QPushButton::clicked, this, &MainWindow::on_Nivel1_Clicked);

    nivel2 = new QPushButton("NIVEL 2", ui->centralwidget);
    nivel2->setObjectName("nivel2");
    nivel2->hide();

    nivel2->setGeometry(900, 100, 350, 194);

    nivel2->setStyleSheet("QPushButton { background-image: url(:/img/nivel2.jpg); background-color: blue; border: 2px solid darkblue; border-radius: 5px; padding: 5px; color: white; font-size: 40px; } QPushButton:hover { background-color: darkblue; }");

    // Conectar la señal clicked() del botón a una función
    connect(nivel2, &QPushButton::clicked, this, &MainWindow::on_Nivel2_Clicked);

    tempo = new QTimer(this);
    connect(tempo, SIGNAL(timeout()), this, SLOT(animar()));

}


void MainWindow::disparar(arma *bola){

    tiempoTiro = new QTimer(this);
    connect(tiempoTiro, &QTimer::timeout, [=](){

        bola->jump();
        morty->setPos(morty->coordX, morty->coordY);
        bola->impacto();

        bola->colisionEnemigo(bola->coordX, bola->coordY, bola->anchoObj, bola->altoObj, morty->coordX, morty->coordY, morty->anchoObj, morty->altoObj);
        if(bola->colEnemigo){
            morty->hide();

            hepatitisB->hide();
            //tiempoTiro->stop();
            particle->hide();
        }

        if(bola->movimiento){

            tiempoTiro->stop();
            //delete tiempoTiro;
            particle->hide();
            //delete bola;


        }
        else{
            particle->setPos(bola->coordX, bola->coordY);
            bola->tiempo +=0.5;
        }
    });

    tiempoTiro->start(10);

}

void MainWindow::dispararlaser(arma *laser, QTimer* propio){

    propio = new QTimer(this);
    connect(propio, &QTimer::timeout, [=](){
        laser->jump();
        laser->impacto();
        if(laser->movimiento){
            propio->stop();
            //delete tiempoTiro;
            laser->hide();
            //delete laser;
        }
        else{
            laser->setPos(laser->coordX, laser->coordY);
            laser->tiempo +=0.5;
            laser->colisionEnemigo(laser->coordX, laser->coordY, laser->anchoObj, laser->altoObj, hepatitisB->coordX, hepatitisB->coordY, hepatitisB->anchoObj, hepatitisB->altoObj );
            if(laser->colEnemigo){
                hepatitisB->hide();
            }
        }
    });
    propio->start(10);
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

    jugando=true;

    morty= new Morty();

    morty->constructor(200.00, 560.0, 0.0, 0.0, true, 83.0, 110.0, 1280.0, 722.0);

    morty->setPos(morty->getcoordX(), morty->getcoordY());

    scene->addItem(morty);
    /*
    widgetContenedor = new QWidget(this);
    morty->barraVida = new QProgressBar(widgetContenedor);
    morty->barraVida->setRange(0, 100);
    morty->barraVida->setValue(100);

    // Agrega el widget a la escena
    ui->graphicsView->scene()->addWidget(widgetContenedor);

    // Configura la posición y el tamaño del widget
    widgetContenedor->setGeometry(10, 10, 200, 30);

*/

    hepatitisB = new personaje();
    hepatitisB->constructor(775.0, 400.0, 0.0, 0.0, false, 405.0, 350.0, 1280.0, 722.0);
    hepatitisB->setPos(hepatitisB->xIn, hepatitisB->yIn);
    scene->addItem(hepatitisB);


    QTimer * cronometro = new QTimer(this);
    connect(cronometro, &QTimer::timeout, [=](){
        if(hepatitisB->cara == 0){
            hepatitisB->setPixmap(QPixmap(":/img/hepatitisb1.png"));
        }else if (hepatitisB->cara == 1){
            hepatitisB->setPixmap(QPixmap(":/img/hepatitisb2.png"));
        }else{
            hepatitisB->setPixmap(QPixmap(":/img/hepatitisb3.png"));
            arma* bola = new arma;
            bola->ubicarMorty(morty->coordX,morty->coordY+40, 890, 460);//aquí va el morty->posiciones en equiz y lle, en los dos primeros parámetros
            bola->constructor(890, 460, bola->angTiro, 5, false, 30, 30, 1280, 722);

            yoeralabola();
            disparar(bola);

            if(bola->colEnemigo){
                cronometro->stop();
            }


        }
        hepatitisB->cambiarCara();
    });
    cronometro->start(500);
}

void MainWindow::yoeralabola(){
    particle = new QGraphicsEllipseItem(0, 0, 30, 30);
    particle->setBrush(Qt::yellow);
    particle->setPos(750,400);
    scene->addItem(particle);
    particle->show();

}

void MainWindow::on_Nivel2_Clicked()
{
    scene->setBackgroundBrush(QPixmap(":/img/fondotuberculosis.jpg").scaled(ancho_pantalla, alto_pantalla));
    nivel1->hide();
    nivel2->hide();

    jugando=true;

    morty= new Morty();

    morty->constructor(200.00, 560.0, 0.0, 0.0, true, 83.0, 110.0, 1280.0, 722.0);

    morty->setPos(morty->getcoordX(), morty->getcoordY());

    scene->addItem(morty);
    /*
    widgetContenedor = new QWidget(this);
    morty->barraVida = new QProgressBar(widgetContenedor);
    morty->barraVida->setRange(0, 100);
    morty->barraVida->setValue(100);

    // Agrega el widget a la escena
    ui->graphicsView->scene()->addWidget(widgetContenedor);

    // Configura la posición y el tamaño del widget
    widgetContenedor->setGeometry(10, 10, 200, 30);

*/

    personaje *tuberculosis = new personaje();
    tuberculosis->angAleatorio();
    tuberculosis->constructor(775.0, 400.0, tuberculosis->angTiro, 80.0, false, 405.0, 350.0, 1280.0, 722.0);
    tuberculosis->setPos(tuberculosis->xIn, tuberculosis->yIn);
    scene->addItem(tuberculosis);

    bool boot = true;
    QTimer *cronometro = new QTimer(this);
    connect(cronometro, &QTimer::timeout, [=](){
        if(tuberculosis->cara == 0){
            tuberculosis->setPixmap(QPixmap(":/img/tuberculosis1.png"));
        }else if (tuberculosis->cara == 1){
            tuberculosis->setPixmap(QPixmap(":/img/tuberculosis2.png"));
        }else{
            tuberculosis->setPixmap(QPixmap(":/img/tuberculosis3.png"));
            //bola->ubicarMorty(300,700, 890, 460);//aquí va el morty->posiciones en equiz y lle, en los dos primeros parámetros

            //tuberculosis->constructor(890, 460, tuberculosis->angTiro, 20, false, 30, 30, 1280, 722);
            tuberculosis->jump();
            tuberculosis->collide(boot);
            tuberculosis->setPos(tuberculosis->coordX, tuberculosis->coordY);
            tuberculosis->tiempo += 0.05;
        }
        tuberculosis->cambiarCara();
    });
    cronometro->start(500);




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
            morty->coordY-=10;
            morty->velY=0;
            morty->tiempo=0;
            tempo->stop();
        }else{
            //Arriba
            morty->coordY=0;
        }
        permitirmovy= false;

    }else{
        permitirmovy= true;
    }
}

// En el cpp de MainWindow
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(jugando){
        permitirmovx=true; permitirmovy=true;
        collideM();
        if (event->key() == Qt::Key_A) {
            //collideM();

            if(permitirmovx){

                morty->contadorposicionmorty=-1;

                if(cont==0){
                    morty->setPixmap(QPixmap(":/img/Mortyizquierda.png"));

                    cont=1;
                }else{
                    morty->setPixmap(QPixmap(":/img/Mortyizquierdaavanza.png"));

                    cont=0;
                }
                morty->velInX=-2;

                morty->setPos(morty->getcoordX()-20, morty->getcoordY());
                morty->coordX-=20;
            }
        } if (event->key() == Qt::Key_W)  {

            if(permitirmovy){

                if(morty->contadorposicionmorty==-1){
                    morty->setPixmap(QPixmap(":/img/Mortyizquierdaavanza.png"));
                    morty->velInX=-3;
                }else if(morty->contadorposicionmorty==0){
                    morty->setPixmap(QPixmap(":/img/Mortyfrente.png"));
                    morty->velInX=0;
                }else{
                    morty->setPixmap(QPixmap(":/img/Mortyderechaavanza.png"));
                    morty->velInX=3;
                }

                qDebug() << morty->velX;
                qDebug() << morty->velY;
                morty->velInY=10;

                tempo->start(10);
            }


        } if (event->key()== Qt::Key_D) {
            //collideM();
            if(permitirmovx){
                morty->contadorposicionmorty=1;
                qDebug() << "Derecha";
                if(cont==0){
                    morty->setPixmap(QPixmap(":/img/Mortyderecha.png"));
                    cont=1;
                }else{
                    morty->setPixmap(QPixmap(":/img/Mortyderechaavanza.png"));

                    cont=0;
                }
                morty->velInX=2;
                morty->setPos(morty->getcoordX()+20, morty->getcoordY());
                morty->coordX+=20;
            }
        }if(event->key()== Qt::Key_S){
            morty->setPixmap(QPixmap(":/img/Mortyfrente.png"));
            morty->contadorposicionmorty=0;

        }if(event->key()== Qt::Key_Space){
            if(morty->contadorposicionmorty==1){
                arma* laser= new arma();
                //laser->ubicarMorty(300,700, 890, 460);//aquí va el morty->posiciones en equiz y lle, en los dos primeros parámetros
                laser->setPixmap(QPixmap(":/img/laser.png"));
                laser->constructor(morty->coordX+20, morty->coordY+10, 0, 20, false, 67, 10, 1280, 722);
                laser->setPos(morty->coordX+80, morty->coordY+20);
                scene->addItem(laser);
                dispararlaser(laser, laser->propio);
            }

        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(jugando){
        if (event->key() == Qt::Key_A){
            morty->setPixmap(QPixmap(":/img/Mortyizquierda.png"));
            morty->velX=0;

        }else if (event->key() == Qt::Key_W){


        }else if (event->key() == Qt::Key_D){
            morty->velX=0;

            morty->setPixmap(QPixmap(":/img/Mortyderecha.png"));
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
    delete morty;
    delete tempo;
    delete hepatitisB;
    delete widgetContenedor;
    delete particle;

}

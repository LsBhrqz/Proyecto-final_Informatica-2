#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>


int ancho_pantalla= 1280;
int alto_pantalla=720;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, ancho_pantalla, alto_pantalla);
    setFixedSize(ancho_pantalla+20, alto_pantalla+43);


    ui->graphicsView->resize(ancho_pantalla, alto_pantalla);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/img/presentacion.png").scaled(ancho_pantalla, alto_pantalla));
    //Aquí es donde debo colocar el código para que cuando se instancie corra todo*/


}

MainWindow::~MainWindow()
{
    delete scene;
    scene = nullptr;
    delete ui;
}


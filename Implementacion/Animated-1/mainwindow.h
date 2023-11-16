#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow> // Clase que incluye la ventana principal
#include <QGraphicsScene> // Manejo de gráficos
#include <QKeyEvent> // Captura de teclas
#include <QTimer>
#include "Rick.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; } //Delimitan el namespace de Qt. Define la interfaz de usuario
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT //Detección de señales, acceder a la información de clases

public:
    MainWindow(QWidget *parent = nullptr); //constructor
    ~MainWindow(); //Destructor

    void keyPressEvent(QKeyEvent *event); //método sobrecargado
    void mousePressEvent(QMouseEvent *event);
    void createShotAnimation(const QPointF &shootPosition);


private slots: // conectan eventos con funciones
    void on_pushButton_clicked();
    void hmov();

    QPointF calculateShotMovement(const QPointF &currentPos, const QPointF &targetPos);
    bool reachedTarget(const QPointF &currentPos, const QPointF &targetPos);

private:
    int vel=5;   //pixeles que se mueve
    Ui::MainWindow *ui;
    QGraphicsScene *scene; //escena para objetos gráficos e interacción
    Rick *jugador;
    QTimer *timer;
    QGraphicsPixmapItem *bgImage;

};
#endif // MAINWINDOW_H

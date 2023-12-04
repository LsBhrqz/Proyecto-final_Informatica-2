#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "morty.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QTime>
#include "personaje.h"
#include "arma.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget *widgetContenedor;
    Morty *morty;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPushButton *JUGAR, *nivel1, *nivel2;
    QTimer *timerMorty;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int cont=0;
    QTimer *tempo;
    bool permitirmovx=false;
    bool permitirmovy=false;
    bool jugando=false;
    personaje* hepatitisB;
    bool teclasostenida;

private slots:
    void animar();
    void on_JUGAR_Clicked();
    void on_Nivel1_Clicked();
    void on_Nivel2_Clicked();
    void collideM();
};
#endif // MAINWINDOW_H

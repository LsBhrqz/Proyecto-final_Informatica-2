#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPushButton>
#include "morty.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Morty *morty;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QPushButton *JUGAR, *nivel1, *nivel2;
    QTimer *timerMorty;
    void keyPressEvent(QKeyEvent *event);
private slots:

    void on_JUGAR_Clicked();
    void on_Nivel1_Clicked();
    void on_Nivel2_Clicked();

};
#endif // MAINWINDOW_H

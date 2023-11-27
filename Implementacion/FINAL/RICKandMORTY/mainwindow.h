#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_JUGAR_Clicked();
    void on_Nivel1_Clicked();
    void on_Nivel2_Clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene* scene;

};
#endif // MAINWINDOW_H

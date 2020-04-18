#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent)
        : QMainWindow(parent)
{
    int dx=dw.width();
    int dy=dw.height();

//    this->gameScene = new GameScene();
    this->lvl1 = new Level1();

    mainView = new QGraphicsView();
//    mainView->setScene(gameScene);
    mainView->setScene(lvl1);
//    mainView->scale(1,1);
    mainView->scale(0.5, 0.5);

    this->setCentralWidget(mainView);

    this->setWindowTitle("Main view");
//    this->resize(dx, dy);

}



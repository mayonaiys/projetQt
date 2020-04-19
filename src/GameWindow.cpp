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
    mainView->scale(0.9,0.9);

    this->setCentralWidget(mainView);

    this->setWindowTitle("GameWindow");
    this->setFixedSize(dx, dy);

    connect(this->lvl1->getPlayer(), SIGNAL(Itswin()),this, SLOT(Itswin()));
    connect(this->lvl1->getPlayer(), SIGNAL(Itsloose()),this, SLOT(Itsloose()));

}

void GameWindow::Itswin() {
    VictoryWindow* victoryWindow = new VictoryWindow();
    victoryWindow->show();
    this->close();
}

void GameWindow::Itsloose() {
    GameOverWindow* gameover = new GameOverWindow();
    gameover->show();
    this->close();
}



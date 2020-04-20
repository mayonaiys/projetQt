#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent)
        : QMainWindow(parent)
{
    time = 0 ;
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

    QTimer* time = new QTimer();
    time->start(100);
    connect(time, SIGNAL(timeout()), this, SLOT(updatetime()));

    timeprint = new QLabel(mainView);
    timeprint->setFixedSize(100,10);
    timeprint->move(20, 950);

    scoreprint = new QLabel(mainView);
    scoreprint->setFixedSize(100,10);
    scoreprint->move(20, 925);


}
void GameWindow::updatetime(){
    this->time += 0.1;
    scoreprint->setText("score = "+QString::number(this->lvl1->getPlayer()->getScore()));
    timeprint->setText("time = "+QString::number(this->time)+" sec");
}
void GameWindow::Itswin() {
    VictoryWindow* victoryWindow = new VictoryWindow();
    victoryWindow->show();
    int timeplayed = this->time;
    this->lvl1->writescore(this->time, this->lvl1->getPlayer()->getScore());
    this->close();
}

void GameWindow::Itsloose() {
    GameOverWindow* gameover = new GameOverWindow();
    gameover->show();
    this->close();
}



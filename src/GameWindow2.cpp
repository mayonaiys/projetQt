#include "GameWindow2.h"

GameWindow2::GameWindow2(QWidget *parent)
        : QMainWindow(parent)
{
    time = 0 ;
    int dx=dw.width();
    int dy=dw.height();

    this->lvl2 = new Level2();
    mainView = new QGraphicsView();
    mainView->setScene(lvl2);
    mainView->scale(0.9,0.9);
    this->setCentralWidget(mainView);
    this->setWindowTitle("GameWindow2");
    this->setFixedSize(dx, dy);

    connect(this->lvl2->getPlayer(), SIGNAL(Itswin()),this, SLOT(Itswin()));
    connect(this->lvl2->getPlayer(), SIGNAL(Itsloose()),this, SLOT(Itsloose()));

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
void GameWindow2::updatetime(){
    this->time += 0.1;
    scoreprint->setText("score = "+QString::number(this->lvl2->getPlayer()->getScore()));
    timeprint->setText("time = "+QString::number(this->time)+" sec");
}
void GameWindow2::Itswin() {
    VictoryWindow* victoryWindow = new VictoryWindow();
    victoryWindow->show();
    int timeplayed = this->time;
    this->lvl2->writescore(this->time, this->lvl2->getPlayer()->getScore());
    this->close();
}
void GameWindow2::Itsloose() {
    GameOverWindow* gameover = new GameOverWindow();
    gameover->show();
    this->close();
}



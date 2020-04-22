//
// Created by Théo on 22/04/2020.
//

#include "GameWindow3.h"

GameWindow3::GameWindow3(QWidget *parent)
        : QMainWindow(parent)
{
    time = 0 ;
    int dx=dw.width();
    int dy=dw.height();

    this->lvl3 = new Level3();
    mainView = new QGraphicsView();
    mainView->setScene(lvl3);
    mainView->scale(0.9,0.9);
    this->setCentralWidget(mainView);
    this->setWindowTitle("GameWindow3");
    this->setFixedSize(dx, dy);

    connect(this->lvl3->getPlayer(), SIGNAL(Itswin()),this, SLOT(Itswin()));
    connect(this->lvl3->getPlayer(), SIGNAL(Itsloose()),this, SLOT(Itsloose()));

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
void GameWindow3::updatetime(){
    this->time += 0.1;
    scoreprint->setText("score = "+QString::number(this->lvl3->getPlayer()->getScore()));
    timeprint->setText("time = "+QString::number(this->time)+" sec");
}
void GameWindow3::Itswin() {
    VictoryWindow* victoryWindow = new VictoryWindow();
    victoryWindow->show();
    int timeplayed = this->time;
    this->lvl3->writescore(this->time, this->lvl3->getPlayer()->getScore());
    this->close();
}
void GameWindow3::Itsloose() {
    GameOverWindow* gameover = new GameOverWindow();
    gameover->show();
    this->close();
}



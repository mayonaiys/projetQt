#include "GameWindow1.h"

GameWindow1::GameWindow1(QWidget *parent)
        : QMainWindow(parent)
{
    time = 0 ;
    int dx=dw.width();
    int dy=dw.height();

    this->lvl1 = new Level1();

    mainView = new QGraphicsView();
    mainView->setScene(lvl1);
    mainView->scale(0.9,0.9);

//    QGraphicsView* playerView = new QGraphicsView();
//    playerView->setScene(lvl1);
//    playerView->resize(300, 300);
//    playerView->setWindowTitle(lvl1->getPlayer()->getDescription());
//    playerView->centerOn(lvl1->getPlayer());
//    playerView->show();


    this->setCentralWidget(mainView);
    this->setWindowTitle("GameWindow1");
    this->setFixedSize(dx, dy);


    timeprint = new QLabel(mainView);
    timeprint->setFixedSize(100,10);
    timeprint->move(20, 950);

    scoreprint = new QLabel(mainView);
    scoreprint->setFixedSize(100,10);
    scoreprint->move(20, 925);

    connect(this->lvl1->getPlayer(), SIGNAL(Itswin()),this, SLOT(Itswin()));
    connect(this->lvl1->getPlayer(), SIGNAL(Itsloose()),this, SLOT(Itsloose()));

    QTimer* time = new QTimer();
    time->start(100);
    connect(time, SIGNAL(timeout()), this, SLOT(updatetime()));

}
void GameWindow1::updatetime(){
    this->time += 0.1;
    scoreprint->setText("score = "+QString::number(this->lvl1->getPlayer()->getScore()));
    timeprint->setText("time = "+QString::number(this->time)+" sec");
}
void GameWindow1::Itswin() {
    VictoryWindow* victoryWindow = new VictoryWindow();
    victoryWindow->show();
    int timeplayed = this->time;
    this->lvl1->writescore(this->time, this->lvl1->getPlayer()->getScore());
    this->close();
}

void GameWindow1::Itsloose() {
    GameOverWindow* gameover = new GameOverWindow();
    gameover->show();
    this->close();
}



#include "GameScene.h"

GameScene::GameScene() {

    this->background.load("../img/FondEspace.png");
    this->setSceneRect(0, 0, background.width(), background.height());

    this->player = new Player("player", "../img/player.png", 1 , background.height() -144 -54);
    this->addItem(player);//144 sur 100 player.png

    //ajout des obsctacles
//    Wall* ground = new Wall("ground", "../img/Ground.png", 0, 0);
//    Wall* obstacle = new Wall("obstacle1", "../img/Wall.png",0,0);
//    this->addItem(obstacle);
//    this->addItem(ground);

//    this->timer = new QTimer(this);
//    this->timer->start(30);

//    connect(timer, SIGNAL(timeout()), this, SLOT(keyPressEvent()));
//    this->player->keyPressEvent(background, event);

}
void GameScene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}

void GameScene::keyPressEvent(QKeyEvent* event){
    this->player->keyPressEvent(background, event);
}

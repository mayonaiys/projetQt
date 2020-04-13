#include "GameScene.h"

GameScene::GameScene() {

    this->background.load("../img/FondEspace.png");
        this->setSceneRect(0, 0, background.width(), background.height());

    this->player = new Player("player", "../img/player.png");
    this->addItem(player);
    player->setPos(background.width()/2, background.height()/2);

    this->timer = new QTimer(this);
    this->timer->start(30);

    connect(timer, SIGNAL(timeout()), this, SLOT(keyPressEvent()));

}
void GameScene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}
void GameScene::keyPressEvent(QKeyEvent* event) {

    if(event->key() == Qt::Key_Left){
//        player->setPos(player->getX() - 10 , player->getY());
        player->move(-10,0);
    }
    if(event->key() == Qt::Key_Right){
//        player->setPos(player->getX() + 10, player->getY());
        player->move(10,0);
    }
    if(event->key() == Qt::Key_Up){
//        player->setPos(player->getX(), player->getY()-10);
        player->move(0,-10);
    }
    if(event->key() == Qt::Key_Down){
//        player->setPos(player->getX(), player->getY()+10);
        player->move(0,+10);
    }
}



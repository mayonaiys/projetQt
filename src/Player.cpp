//
// Created by Théo on 12/04/2020.
//

#include "Player.h"
using namespace std;

void Player::move(int x, int y) {
    this->x += x;
    this->y += y;
}

void Player::draw() {
    this->setPos(this->getX(), this->getY());
}
void Player::jumpUp(){// attention test pour le disconnect
    if(this->getIsJump() && !this->getOnGround()){
//        cout << "jump up\n";
//        cout << "j = " << this->isjump << " og =" << this->onGround << endl;
        if (this->getY() <= this->currentHeight - this->jumpHeight) {
            this->isjump = false;
            this->onGround = false;
            disconnect(timerPLayer,SIGNAL(timeout()), this, SLOT(jumpUp()));
            connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpDown()));
        } else {
            this->move(0, -10);
            this->draw();

            QList<QGraphicsItem *> colliding_item = collidingItems();
            for (int i = 0; i < colliding_item.length(); i++) {
                if (typeid(*(colliding_item[i])) == typeid(Ground)) {
                    this->move(0, 5);
                    this->draw();

                    this->isjump = false;
                    this->onGround = false;

                    disconnect(timerPLayer,SIGNAL(timeout()), this, SLOT(jumpUp()));
                    connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpDown()));
                }
                if (typeid(*(colliding_item[i])) == typeid(Piece)) {
                    delete colliding_item[i];
                    this->score += 1000;
                }
                if (typeid(*(colliding_item[i])) == typeid(JetPack)) {
                    delete colliding_item[i];
                    this->jumpHeight += 200;

                }
            }
        }
    }
}
void Player::jumpDown(){
    if(!this->onGround&& !this->isjump){
//        cout << "jump down\n";
//        cout << "j = " << this->isjump << " og =" << this->onGround << endl;
        if (!this->getOnGround() && !this->isjump) {
            this->move(0, 5);
            this->draw();

        }
        QList<QGraphicsItem *> colliding_item = collidingItems();
        for (int i = 0; i < colliding_item.length(); i++) {
            if (typeid(*(colliding_item[i])) == typeid(Ground) || typeid(*colliding_item[i]) == typeid(MovingGround)) {
               this->setIsJump(false);
               this->setOnGround(true);
//                cout << "au sol \n";
//                cout << "j = " << this->isjump << " og =" << this->onGround << endl;
                this->currentHeight = this->getY();
                disconnect(timerPLayer,SIGNAL(timeout()), this, SLOT(jumpDown ()));
            }
            if(typeid(*(colliding_item[i])) == typeid(Flammes)){
                emit Itsloose();
                this->restart();
            }
            if(typeid(*(colliding_item[i])) == typeid(FinalFlag)){
                emit Itswin();
                this->restart();
            }
            if (typeid(*(colliding_item[i])) == typeid(Piece)) {
                delete colliding_item[i];
                this->score += 1000;
            }
            if (typeid(*(colliding_item[i])) == typeid(JetPack)) {
                delete colliding_item[i];
                this->jumpHeight += 200;

            }
            if(typeid(*colliding_item[i]) == typeid(MovingGround)){
                //on saut comme si c'etait un trampo
                this->setCurrentHeight(this->pos().y());
                if (!this->isjump && this->onGround) {
                    timerPLayer->start(50);
                    this->setOnGround(false);
                    this->setIsJump(true);
                    connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpUp()));

                }
            }
        }
    }
}

bool Player::inscreen(int x, int y, QPixmap background){
    return this->pos().x() + x >= 0 && this->pos().x() + x <= background.width() - 100 &&
            this->pos().y() + y >= 0 && this->pos().y() + y  <= background.height() - 144;
}
void Player :: keyPressEvent(QPixmap background, QKeyEvent* event) {
    if(event->key() == Qt::Key_Left){
        bool verifWall = false;
        bool verifOnGround = false;
        QList<QGraphicsItem *> colliding_item = collidingItems();
        for (int i = 0; i < colliding_item.length(); i++) {
            if (typeid(*(colliding_item[i])) == typeid(Wall) || typeid(*(colliding_item[i])) == typeid(MovingGround)) {
                verifWall = true;
            }
        }
        if(inscreen(-10,0,background) && !verifWall){
            this->move(-10, 0);
            this->draw();
            QList<QGraphicsItem *> colliding_item2 = collidingItems();
            for (int i = 0; i < colliding_item2.length(); i++) {
                if (typeid(*(colliding_item2[i])) == typeid(Wall) || typeid(*(colliding_item2[i])) == typeid(MovingGround)) {
//                    cout<<"wall\n";
                    this->move(10, 0);
                    this->draw();
                }
                if (typeid(*(colliding_item2[i])) == typeid(Piece)) {
                    delete colliding_item2[i];
                    this->score += 1000;
                }
                if (typeid(*(colliding_item2[i])) == typeid(JetPack)) {
                    delete colliding_item2[i];
                    this->jumpHeight += 200;

                }
                if(typeid(*(colliding_item2[i])) == typeid(FinalFlag)){
                    emit Itswin();
                    this->restart();
                }
            }
        }
        QList<QGraphicsItem *> colliding_item2 = collidingItems();
        for (int i = 0; i < colliding_item2.length(); i++) {
            if (typeid(*(colliding_item2[i])) == typeid(Ground)) {
                verifOnGround = true;
            }
        }
        if(!this->getIsJump() && !verifOnGround){
            this->setOnGround(false);
            disconnect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpDown()));
            connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpDown()));
        }
    }
    if(event->key() == Qt::Key_Right) {
        bool verifWall = false;
        bool verifOnGround = false;
        QList<QGraphicsItem *> colliding_item1 = collidingItems();
        for (int i = 0; i < colliding_item1.length(); i++) {
            if (typeid(*(colliding_item1[i])) == typeid(Wall) || typeid(*(colliding_item1[i])) == typeid(MovingGround)) {
                verifWall = true;
            }
        }
        if(inscreen(10,0,background) && !verifWall){
            this->move(10, 0);
            this->draw();
            bool verifGround = false;
            QList<QGraphicsItem *> colliding_item2 = collidingItems();
            for (int i = 0; i < colliding_item2.length(); i++) {
                if (typeid(*(colliding_item2[i])) == typeid(Wall) || typeid(*(colliding_item2[i])) == typeid(MovingGround) ) {
//                    cout<<"wall\n";
                    this->move(-10, 0);
                    this->draw();
                }
                if (typeid(*(colliding_item2[i])) == typeid(Piece)) {
                    delete colliding_item2[i];
                    this->score += 1000;
                }
                if (typeid(*(colliding_item2[i])) == typeid(JetPack)) {
                    delete colliding_item2[i];
                    this->jumpHeight += 200;

                }
                if(typeid(*(colliding_item2[i])) == typeid(FinalFlag)){
                    emit Itswin();
                    this->restart();
                }
            }
        }

        QList<QGraphicsItem *> colliding_item3 = collidingItems();
        for (int i = 0; i < colliding_item3.length(); i++) {
            if (typeid(*(colliding_item3[i])) == typeid(Ground) || typeid(*(colliding_item3[i])) == typeid(MovingGround)) {
                verifOnGround = true;
            }
            if (typeid(*(colliding_item3[i])) == typeid(Piece)) {
                delete colliding_item3[i];
                this->score += 1000;
            }
            if (typeid(*(colliding_item3[i])) == typeid(JetPack)) {
                delete colliding_item3[i];
                this->jumpHeight += 200;

            }
            if(typeid(*(colliding_item3[i])) == typeid(FinalFlag)){
                emit Itswin();
                this->restart();
            }
        }
        if(!this->getIsJump() && !verifOnGround){
            this->setOnGround(false);
            disconnect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpDown()));
            connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpDown()));
        }
    }
    if(!this->isjump) {
        if (event->key() == Qt::Key_Up) {
            //ne pas sauter a l'infini
            this->setCurrentHeight(this->pos().y());
            if (!this->isjump && this->onGround) {
                timerPLayer->start(50);
                this->setOnGround(false);
                this->setIsJump(true);
                connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpUp()));

            }
        }
    }
//    if (event->key() == Qt::Key_Down) {
//        if(inscreen(0,10,background)) {
////            disconnect(timerPLayer,SIGNAL(timeout()), this, SLOT(jumpUp()));
//            disconnect(timerPLayer,SIGNAL(timeout()), this, SLOT(jumpUp()));
//            bool verif = false;
//
//            QList<QGraphicsItem *> colliding_item = collidingItems();
//            for (int i = 0; i < colliding_item.length(); i++) {
//                if (typeid(*(colliding_item[i])) == typeid(Wall)) {
//                    verif = true;
////                    cout<<"on wall";
//                }
//            }
//            this->onGround = verif;
//            this->isjump = false;
//            connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpDown()));
//        }
//    }

}
void Player::restart(){
    this->setPos(1 ,910);
    this->setX(1);
    this->setY(910);
}
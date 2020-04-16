//
// Created by Théo on 12/04/2020.
//

#include "Player.h"

void Player::move(int x, int y) {
    this->x += x;
    this->y += y;
}

void Player::draw() {
    this->setPos(this->getX(), this->getY());
}

void Player::jumpUp(){// attention test pour le disconnect
    if(this->getIsJump() && !this->getOnGround()){
        cout << "jump up\n";
        cout << "j = " << this->isjump << " og =" << this->onGround << endl;
        if (this->getY() <= this->currentHeight - this->jumpHeight) {
            this->isjump = false;
            this->onGround = false;
            disconnect(timerPLayer,SIGNAL(timeout()), this, SLOT(jumpUp()));
            connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpDown()));
        } else {
            this->move(0, -5);
            this->draw();
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
            if (typeid(*(colliding_item[i])) == typeid(Sol)) {
               this->isjump = false;
               this->onGround = true;
//                cout << "au sol \n";
//                cout << "j = " << this->isjump << " og =" << this->onGround << endl;
                this->currentHeight = this->getY();
                disconnect(timerPLayer,SIGNAL(timeout()), this, SLOT(jumpDown()));
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
        if(inscreen(-10,0,background)) {
            this->move(-10, 0);
            this->draw();
        }
    }
    if(event->key() == Qt::Key_Right) {
        if(inscreen(10,0,background)) {
            this->move(10, 0);
            this->draw();
        }
    }
    if (event->key() == Qt::Key_Up) {
        this->setCurrentHeight(this->pos().y());

        if(!this->isjump && this->onGround){
            timerPLayer->start(50);
            this->onGround = false;
            this->isjump = true;
            cout<<"monte\n";
            cout<<"j = "<<this->isjump<<" og ="<<this->onGround<<endl;
            connect(timerPLayer, SIGNAL(timeout()), this, SLOT(jumpUp()));

        }
    }
    if (event->key() == Qt::Key_Down) {
        if(inscreen(0,10,background)) {
            this->move(0, 10);
            this->draw();
        }
    }

}

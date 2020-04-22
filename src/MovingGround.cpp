//
// Created by Théo on 21/04/2020.
//

#include "MovingGround.h"
void MovingGround::moveR() {
    if(this->right){
        if(this->pos().x() < this->currentX + this->longeur){
            this->setPos(this->pos().x() + 5 , this->pos().y());
        }else{
            this->right = false;
            this->currentX = this->pos().x();
        }
    }else{
        this->moveL();
    }
}
void MovingGround:: moveL(){
    if(!this->right) {
        if (this->pos().x() > this->currentX - this->longeur) {
            this->setPos(this->pos().x() - 5, this->pos().y());

            QList<QGraphicsItem *> colliding_item = collidingItems();
            for (int i = 0; i < colliding_item.length(); i++) {

            }

        } else {
            this->right = true;
            this->currentX = this->pos().x();
        }
    }else{
        this->moveR();
    }
}
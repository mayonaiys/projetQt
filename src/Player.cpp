//
// Created by Théo on 12/04/2020.
//

#include "Player.h"

void Player::move(int x, int y) {
    QPointF pos = this->pos();
    int ax = pos.x();
    int ay =pos.y();
    this->setPos(ax + x,  ay + y);
}

//
// Created by Théo on 21/04/2020.
//

#ifndef PROJETQT_LEVEL2_H
#define PROJETQT_LEVEL2_H



#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QKeyEvent>

#include "Player.h"
#include "Ground.h"
#include "Flammes.h"
#include "FinalFlag.h"
#include "Piece.h"
#include "MovingGround.h"

class Level2 : public QGraphicsScene{
Q_OBJECT

private :
    QPixmap background;
    Player* player;
    QTimer* time;
public:
    Level2();
    void writescore(float time, int score);
    void drawBackground(QPainter* painter, const QRectF& rect);

    Player* getPlayer(){return this->player ;};

public slots :
    void keyPressEvent(QKeyEvent* event);
};



#endif //PROJETQT_LEVEL2_H

//
// Created by Théo on 22/04/2020.
//

#ifndef PROJETQT_LEVEL3_H
#define PROJETQT_LEVEL3_H

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QKeyEvent>

#include "Player.h"
#include "Wall.h"
#include "Ground.h"
#include "Flammes.h"
#include "FinalFlag.h"
#include "Piece.h"

class Level3 : public QGraphicsScene {
Q_OBJECT

private :
    QPixmap background;
    Player* player;

public:
    Level3();
    void writescore(float time, int score);
    void drawBackground(QPainter* painter, const QRectF& rect);

    Player* getPlayer(){return this->player ;};

public slots :
    void keyPressEvent(QKeyEvent* event);
};




#endif //PROJETQT_LEVEL3_H

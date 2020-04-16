//
// Created by Théo on 11/04/2020.
//

#ifndef PROJETQT_GAMESCENE_H
#define PROJETQT_GAMESCENE_H
#include <iostream>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QRectF>
#include <QKeyEvent>

#include "Player.h"
#include "Sol.h"

using namespace std;
class GameScene : public QGraphicsScene {

Q_OBJECT

private :
    QPixmap background;
    QTimer* timer;
    Player* player;

public:
    GameScene();
    void drawBackground(QPainter* painter, const QRectF& rect);

public slots :
    void keyPressEvent(QKeyEvent* event);
};


#endif //PROJETQT_GAMESCENE_H

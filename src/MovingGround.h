//
// Created by Théo on 21/04/2020.
//

#ifndef PROJETQT_MOVINGGROUND_H
#define PROJETQT_MOVINGGROUND_H

#include <QtWidgets/QGraphicsItem>
#include <QTimer>
#include <iostream>
#include "Player.h"
using namespace std;

class MovingGround : public QObject , public QGraphicsPixmapItem{
Q_OBJECT
private:
    QString description;
    int currentX;
    int longeur;
    bool right;
    QTimer* time;

public:
    MovingGround(QString description, QString imageFileName, int x, int y) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->setPos(x,y);
        this->longeur = 1000 ;
        this->currentX = this->pos().x();
        this->right = true,

        time = new QTimer();
        time->start(50);
        connect(time, SIGNAL(timeout()), this, SLOT(moveR()));
    }
    void moveL();
public slots:
    void moveR();
signals:
    void onplayer();

};


#endif //PROJETQT_MOVINGGROUND_H

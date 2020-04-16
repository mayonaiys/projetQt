//
// Created by Théo on 12/04/2020.
//

#ifndef PROJETQT_PLAYER_H
#define PROJETQT_PLAYER_H

#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "Sol.h"

using namespace std;

class Player :  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT;
    //ATTRIBUTS
private:
    QString description;
    QTimer* timerPLayer;
    //nbr de vie ?
    int x;
    int y;
    int currentHeight;
    int jumpHeight;
    bool isjump;
    bool onGround;

    //METHODES
public:
    //CONSTRUCTEUR ET DESTRUCTEUR
    Player(QString description, QString imageFileName, int x , int y ) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->setPos(x,y);
        this->x = pos().x();
        this->y = pos().y();

        this->timerPLayer = new QTimer();

        this->onGround = true;
        this->isjump = false;

        this->jumpHeight = 200;//un saut de 300 pxl
        this->currentHeight = this->x - 144 ;//car la hauteur du perso
    }
    //FONCTION PLAYER
    bool inscreen(int x, int y, QPixmap background);
    void move(int x, int y);
    void draw();
    const QString &getDescription() const { return this->description; }
    void setDescription(const QString &description) { this->description = description; }

    // SETTERS AND GETTERS
    void setX(int x){this->x = x;};
    void setY(int y){this->y = y;};
    int getX(){return this->x;};
    int getY(){return this->y;};

    void setIsJump(bool isjump){ this->isjump = isjump;};
    void setOnGround(bool onGround){ this->onGround = onGround;};
    bool getIsJump(){ return this->isjump;};
    bool getOnGround(){return this->onGround;};

    void setCurrentHeight(int y){ this->currentHeight = y;};
    int getCurrentHeight(){return this->currentHeight;};


    // SLOTS
public slots :
    void keyPressEvent(QPixmap background, QKeyEvent* event);
    void jumpUp();
    void jumpDown();


};


#endif //PROJETQT_PLAYER_H

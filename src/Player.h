//
// Created by Théo on 12/04/2020.
//

#ifndef PROJETQT_PLAYER_H
#define PROJETQT_PLAYER_H
#include <iostream>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

using namespace std;
class Player : public QGraphicsPixmapItem{
private:
    QString description;
    float speed;
public:
    Player(QString description, QString imageFileName, float speed = 0) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->speed = 0;
    }
    void move(int x, int y);
    const QString &getDescription() const { return this->description; }
    void setDescription(const QString &description) { this->description = description; }
    void setSpeed(int speed) { this->speed = speed; }
    int getSpeed() const { return speed; }
    int getX(){return this->pos().x();}
    int getY(){return this->pos().y();}
};


#endif //PROJETQT_PLAYER_H

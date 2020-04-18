//
// Created by Théo on 16/04/2020.
//

#ifndef PROJETQT_WALL_H
#define PROJETQT_WALL_H

#include <QtWidgets/QGraphicsItem>

class Wall : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QString description;
public:
    Wall(QString description, QString imageFileName, int x, int y) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->setPos(x,y);
    }

};


#endif //PROJETQT_WALL_H

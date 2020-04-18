//
// Created by Théo on 17/04/2020.
//

#ifndef PROJETQT_GROUND_H
#define PROJETQT_GROUND_H


#include <QtWidgets/QGraphicsItem>

class Ground : public QObject , public QGraphicsPixmapItem{
Q_OBJECT
private:
    QString description;
public:
    Ground(QString description, QString imageFileName, int x, int y) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->setPos(x,y);
    }

};


#endif //PROJETQT_GROUND_H

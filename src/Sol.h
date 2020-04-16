//
// Created by Théo on 16/04/2020.
//

#ifndef PROJETQT_SOL_H
#define PROJETQT_SOL_H

#include <QtWidgets/QGraphicsItem>

class Sol : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QString description;
public:
    Sol(QString description, QString imageFileName, int x, int y) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->setPos(x,y);
    }

};


#endif //PROJETQT_SOL_H

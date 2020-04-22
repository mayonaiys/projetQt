//
// Created by Théo on 22/04/2020.
//

#ifndef PROJETQT_JETPACK_H
#define PROJETQT_JETPACK_H


#include <QtWidgets/QGraphicsItem>

class JetPack : public QObject , public QGraphicsPixmapItem{
Q_OBJECT
private:
    QString description;
public:
    JetPack(QString description, QString imageFileName, int x, int y) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->setPos(x,y);
    }
};


#endif //PROJETQT_JETPACK_H

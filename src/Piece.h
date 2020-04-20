//
// Created by Théo on 20/04/2020.
//

#ifndef PROJETQT_PIECE_H
#define PROJETQT_PIECE_H


#include <QtWidgets/QGraphicsItem>

class Piece : public QObject , public QGraphicsPixmapItem{
Q_OBJECT
private:
    QString description;
public:
    Piece(QString description, QString imageFileName, int x, int y) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description){
        this->setPos(x,y);
    }
};


#endif //PROJETQT_PIECE_H

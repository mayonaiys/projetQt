//
// Created by Théo on 11/04/2020.
//

#ifndef PROJETQT_GAMEWINDOW_H
#define PROJETQT_GAMEWINDOW_H

#include "Level1.h"
//#include "GameScene.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QVector>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>


class GameWindow : public QMainWindow
{
Q_OBJECT

private :
//    GameScene* gameScene;
    Level1* lvl1;
    QGraphicsView* mainView;
    QVBoxLayout* vertical;
    QDesktopWidget dw;

public:
    GameWindow(QWidget* parent = nullptr);
    virtual ~GameWindow() {};

public slots:
    void Itswin();
    void Itsloose();

};


#endif //PROJETQT_GAMEWINDOW_H

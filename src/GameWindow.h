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
#include <QPushButton>
#include <QLabel>
#include <QString>


class GameWindow : public QMainWindow
{
Q_OBJECT

private :
//    GameScene* gameScene;
    Level1* lvl1;
    QGraphicsView* mainView;
    QDesktopWidget dw;
    float time;
    QLabel* timeprint;
    QLabel* scoreprint;
public:
    GameWindow(QWidget* parent = nullptr);
    virtual ~GameWindow() {};

public slots:
    void Itswin();
    void Itsloose();
    void updatetime();

};


#endif //PROJETQT_GAMEWINDOW_H

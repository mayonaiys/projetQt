//
// Created by Théo on 11/04/2020.
//

#ifndef PROJETQT_GAMEWINDOW1_H
#define PROJETQT_GAMEWINDOW1_H

#include "Level1.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include <QString>


class GameWindow1 : public QMainWindow
{
Q_OBJECT

private :

    Level1* lvl1;
    QGraphicsView* mainView;
    QDesktopWidget dw;
    float time;
    QLabel* timeprint;
    QLabel* scoreprint;
public:
    GameWindow1(QWidget* parent = nullptr);
    virtual ~GameWindow1() {};

public slots:
    void Itswin();
    void Itsloose();
    void updatetime();

};


#endif //PROJETQT_GAMEWINDOW1_H

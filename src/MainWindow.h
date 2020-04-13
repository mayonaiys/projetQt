//
// Created by Théo on 11/04/2020.
//

#ifndef PROJETQT_MAINWINDOW_H
#define PROJETQT_MAINWINDOW_H


#include "GameScene.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QVector>
#include <QHBoxLayout>


class MainWindow : public QMainWindow
{
Q_OBJECT

private :
    GameScene* gameScene;
    QGraphicsView* mainView;
    QDesktopWidget dw;

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow() {};

};


#endif //PROJETQT_MAINWINDOW_H

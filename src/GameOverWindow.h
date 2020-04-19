//
// Created by Théo on 19/04/2020.
//

#ifndef PROJETQT_GAMEOVERWINDOW_H
#define PROJETQT_GAMEOVERWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class GameOverWindow: public QMainWindow {
    Q_OBJECT

public:
    GameOverWindow(QWidget *parent = nullptr);

public slots:
    void pressMainPage();
    void restart();

};


#endif //PROJETQT_GAMEOVERWINDOW_H

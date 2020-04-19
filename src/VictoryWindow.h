//
// Created by Théo on 19/04/2020.
//

#ifndef PROJETQT_VICTORYWINDOW_H
#define PROJETQT_VICTORYWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class VictoryWindow : public QMainWindow {
Q_OBJECT

public:
    VictoryWindow(QWidget *parent = nullptr);

public slots:
    void pressNextLevel();
    void pressMainPage();
};


#endif //PROJETQT_VICTORYWINDOW_H

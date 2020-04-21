//
// Created by Théo on 21/04/2020.
//

#ifndef PROJETQT_TUTO1_H
#define PROJETQT_TUTO1_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

class tuto1 : public QMainWindow {
Q_OBJECT

public:
    tuto1(QWidget *parent = nullptr);

public slots:
    void pressMainMenu();
    void pressNext();
};

#endif //PROJETQT_TUTO1_H

//
// Created by Théo on 21/04/2020.
//

#ifndef PROJETQT_TUTO2_H
#define PROJETQT_TUTO2_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

class tuto2 : public QMainWindow {
Q_OBJECT

public:
    tuto2(QWidget *parent = nullptr);

public slots:
    void pressMainMenu();
    void pressNext();
    void pressPrec();
};

#endif //PROJETQT_TUTO2_H

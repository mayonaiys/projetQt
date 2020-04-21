//
// Created by Théo on 21/04/2020.
//

#ifndef PROJETQT_TUTO3_H
#define PROJETQT_TUTO3_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

class tuto3 : public QMainWindow {
Q_OBJECT

public:
    tuto3(QWidget *parent = nullptr);

public slots:
    void pressMainMenu();
    void pressPrec();
};


#endif //PROJETQT_TUTO3_H

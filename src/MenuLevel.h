//
// Created by Théo on 19/04/2020.
//

#ifndef PROJETQT_MENULEVEL_H
#define PROJETQT_MENULEVEL_H

#include <QMainWindow>
#include <QPushButton>

class MenuLevel : public QMainWindow {
    Q_OBJECT

public:
    MenuLevel(QWidget *parent = nullptr);

public slots:
    void pressMainPage();
    void presslvl1();
    void presslvl2();
    void presslvl3();

};


#endif //PROJETQT_MENULEVEL_H

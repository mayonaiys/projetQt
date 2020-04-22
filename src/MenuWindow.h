//
// Created by Théo on 16/04/2020.
//

#ifndef PROJETQT_MENUWINDOW_H
#define PROJETQT_MENUWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <iostream>

#include "GameWindow1.h"
#include "GameWindow2.h"
#include "GameWindow3.h"


#include "MenuLevel.h"
#include "tuto1.h"
#include "TimerWindow.h"

using namespace std;


class MenuWindow : public QMainWindow {
 Q_OBJECT

public:
    MenuWindow(QWidget *parent = nullptr);

public slots:
    void pressbPLay();
    void pressbTimer();
    void pressbTuto();

};


#endif //PROJETQT_MENUWINDOW_H

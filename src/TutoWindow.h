//
// Created by Théo on 19/04/2020.
//

#ifndef PROJETQT_TUTOWINDOW_H
#define PROJETQT_TUTOWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

class TutoWindow : public QMainWindow {
Q_OBJECT

public:
    TutoWindow(QWidget *parent = nullptr);

public slots:
    void pressMainMenu();
};


#endif //PROJETQT_TUTOWINDOW_H

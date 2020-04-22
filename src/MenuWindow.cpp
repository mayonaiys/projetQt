//
// Created by Théo on 16/04/2020.
//

#include "MenuWindow.h"
MenuWindow::MenuWindow(QWidget *parent)
: QMainWindow(parent)
{

    this->setWindowTitle("Theo LOPEZ");
    this->setFixedSize(1920,1080);

    QWidget* window = new QWidget(this);
    window->setFixedSize(1920,1080);

    this->setCentralWidget(window);
    this->setCursor(Qt::CrossCursor);

    centralWidget()->setObjectName("window");
    centralWidget()->setStyleSheet("QWidget #window { background-image : url(../img/menu/MenuBackground.png);}");

    QPushButton* bPlay = new QPushButton(window);
    bPlay->setCursor(Qt::PointingHandCursor);
    bPlay->setFixedSize(730,100);
    bPlay->move(1034,615);
    bPlay->setIcon(QIcon("../img/Bouton/PlayBouton.png"));
    bPlay->setIconSize(QSize(730,100));

    QPushButton* bTimer = new QPushButton(window);
    bTimer->setCursor(Qt::PointingHandCursor);
    bTimer->setFixedSize(730,100);
    bTimer->move(1034,748);
    bTimer->setIcon(QIcon("../img/Bouton/TimerBouton.png"));
    bTimer->setIconSize(QSize(730,100));

    QPushButton* bTuto = new QPushButton(window);
    bTuto->setCursor(Qt::PointingHandCursor);
    bTuto->setFixedSize(730,100);
    bTuto->move(1034,881);
    bTuto->setIcon(QIcon("../img/Bouton/TutoBouton.png"));
    bTuto->setIconSize(QSize(730,100));

    connect(bPlay, SIGNAL(clicked()), this, SLOT(pressbPLay()));
    connect(bTimer, SIGNAL(clicked()), this, SLOT(pressbTimer()));
    connect(bTuto, SIGNAL(clicked()), this, SLOT(pressbTuto()));
}

void MenuWindow::pressbPLay() {
//    GameWindow1* game = new GameWindow1();
//    game->show();
    MenuLevel* menuLevel = new MenuLevel();
    menuLevel->show();
    this->close();
}

void MenuWindow::pressbTimer() {
    TimerWindow* timer = new TimerWindow();
    timer->show();
    this->close();
}

void MenuWindow::pressbTuto() {
    tuto1* tuto = new tuto1();
    tuto->show();
    this->close();
}

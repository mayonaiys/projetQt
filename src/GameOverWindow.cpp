//
// Created by Théo on 19/04/2020.
//

#include "GameOverWindow.h"
#include "GameWindow.h"
#include "MenuWindow.h"

GameOverWindow::GameOverWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Théo LOPEZ");
    this->setFixedSize(1920,1080);

    QWidget* window = new QWidget(this);
    window->setFixedSize(1920,1080);

    this->setCentralWidget(window);
    this->setCursor(Qt::CrossCursor);

    centralWidget()->setObjectName("window");
    centralWidget()->setStyleSheet("QWidget #window { background-image : url(../img/menu/GameOver.png);}");

    QPushButton* bMainMenu = new QPushButton(window);
    bMainMenu->setCursor(Qt::PointingHandCursor);
    bMainMenu->setFixedSize(162,142);
    bMainMenu->move(563,769);
    bMainMenu->setIcon(QIcon("../img/Bouton/MainPage.png"));
    bMainMenu->setIconSize(QSize(162,142));

    QPushButton* bRestart = new QPushButton(window);
    bRestart->setCursor(Qt::PointingHandCursor);
    bRestart->setFixedSize(162,142);
    bRestart->move(782,769);
    bRestart->setIcon(QIcon("../img/Bouton/Restart.png"));
    bRestart->setIconSize(QSize(162,142));

    QPushButton* bQuit = new QPushButton(window);
    bQuit->setCursor(Qt::PointingHandCursor);
    bQuit->setFixedSize(162,142);
    bQuit->move(991,769);
    bQuit->setIcon(QIcon("../img/Bouton/quit.png"));
    bQuit->setIconSize(QSize(162,142));


    connect(bQuit, SIGNAL(clicked()), this, SLOT(close()));
    connect(bRestart, SIGNAL(clicked()), this, SLOT(restart()));
    connect(bMainMenu, SIGNAL(clicked()), this, SLOT(pressMainPage()));
}

void GameOverWindow::restart() {
    GameWindow* game = new GameWindow();
    game->show();
    this->close();
}

void GameOverWindow::pressMainPage() {
    MenuWindow* menu = new MenuWindow();
    menu->show();
    this->close();
}

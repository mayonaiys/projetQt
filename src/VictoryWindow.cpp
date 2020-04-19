//
// Created by Théo on 19/04/2020.
//

#include "VictoryWindow.h"
#include "MenuWindow.h"
#include "MenuLevel.h"

VictoryWindow::VictoryWindow(QWidget *parent)
        : QMainWindow(parent)
{

    this->setWindowTitle("Theo LOPEZ");
    this->setFixedSize(1920,1080);

    QWidget* window = new QWidget(this);
    window->setFixedSize(1920,1080);

    this->setCentralWidget(window);
    this->setCursor(Qt::CrossCursor);

    centralWidget()->setObjectName("window");
    centralWidget()->setStyleSheet("QWidget #window { background-image : url(../img/menu/Victory.png);}");

    QPushButton* bMainMenu = new QPushButton(window);
    bMainMenu->setCursor(Qt::PointingHandCursor);
    bMainMenu->setFixedSize(162,142);
    bMainMenu->move(563,769);
    bMainMenu->setIcon(QIcon("../img/Bouton/MainPage.png"));
    bMainMenu->setIconSize(QSize(162,142));

    QPushButton* bNextGame = new QPushButton(window);
    bNextGame->setCursor(Qt::PointingHandCursor);
    bNextGame->setFixedSize(162,142);
    bNextGame->move(782,769);
    bNextGame->setIcon(QIcon("../img/Bouton/NextLevel.png"));
    bNextGame->setIconSize(QSize(162,142));

    QPushButton* bQuit = new QPushButton(window);
    bQuit->setCursor(Qt::PointingHandCursor);
    bQuit->setFixedSize(162,142);
    bQuit->move(991,769);
    bQuit->setIcon(QIcon("../img/Bouton/quit.png"));
    bQuit->setIconSize(QSize(162,142));


    connect(bQuit, SIGNAL(clicked()), this, SLOT(close()));
    connect(bNextGame, SIGNAL(clicked()), this, SLOT(pressNextLevel()));
    connect(bMainMenu, SIGNAL(clicked()), this, SLOT(pressMainPage()));
}

void VictoryWindow::pressNextLevel() {
    MenuLevel* menulevel = new MenuLevel();
    menulevel->show();
    this->close();
}

void VictoryWindow::pressMainPage() {
    MenuWindow* menu = new MenuWindow();
    menu->show();
    this->close();
}

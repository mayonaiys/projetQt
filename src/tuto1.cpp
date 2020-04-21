//
// Created by Théo on 21/04/2020.
//

#include "tuto1.h"
#include "MenuWindow.h"
#include "tuto2.h"

tuto1 :: tuto1(QWidget *parent )
        :QMainWindow(parent)
{
    this->setWindowTitle("Theo LOPEZ");
    this->setFixedSize(1920,1080);

    QWidget* window = new QWidget(this);
    window->setFixedSize(1920,1080);

    this->setCentralWidget(window);
    this->setCursor(Qt::CrossCursor);

    centralWidget()->setObjectName("window");
    centralWidget()->setStyleSheet("QWidget #window { background-image : url(../img/menu/Tuto13.png);}");

    QPushButton* bMainMenu = new QPushButton(window);
    bMainMenu->setCursor(Qt::PointingHandCursor);
    bMainMenu->setFixedSize(162,142);
    bMainMenu->move(55,60);
    bMainMenu->setIcon(QIcon("../img/Bouton/MainPage.png"));
    bMainMenu->setIconSize(QSize(162,142));

    QPushButton* nNext = new QPushButton(window);
    nNext->setCursor(Qt::PointingHandCursor);
    nNext->setFixedSize(162,142);
    nNext->move(1697,885);
    nNext->setIcon(QIcon("../img/Bouton/NextLevel.png"));
    nNext->setIconSize(QSize(162,142));

    connect(bMainMenu, SIGNAL(clicked()), this, SLOT(pressMainMenu()));
    connect(nNext, SIGNAL(clicked()), this, SLOT(pressNext()));
}

void tuto1::pressMainMenu() {
    MenuWindow* menu = new MenuWindow();
    menu->show();
    this->close();
}
void tuto1:: pressNext(){
    tuto2* tuto = new tuto2();
    tuto->show();
    this->close();
}

//
// Created by Théo on 21/04/2020.
//

#include "tuto2.h"
//
// Created by Théo on 21/04/2020.
//

#include "tuto1.h"
#include "tuto3.h"
#include "MenuWindow.h"

tuto2 :: tuto2(QWidget *parent )
        :QMainWindow(parent)
{
    this->setWindowTitle("Theo LOPEZ");
    this->setFixedSize(1920,1080);

    QWidget* window = new QWidget(this);
    window->setFixedSize(1920,1080);

    this->setCentralWidget(window);
    this->setCursor(Qt::CrossCursor);

    centralWidget()->setObjectName("window");
    centralWidget()->setStyleSheet("QWidget #window { background-image : url(../img/menu/Tuto23.png);}");

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

    QPushButton* nPrec = new QPushButton(window);
    nPrec->setCursor(Qt::PointingHandCursor);
    nPrec->setFixedSize(162,142);
    nPrec->move(52,885);
    nPrec->setIcon(QIcon("../img/Bouton/PrecLevel.png"));
    nPrec->setIconSize(QSize(162,142));

    connect(bMainMenu, SIGNAL(clicked()), this, SLOT(pressMainMenu()));
    connect(nNext, SIGNAL(clicked()), this, SLOT(pressNext()));
    connect(nPrec, SIGNAL(clicked()), this, SLOT(pressPrec()));
}

void tuto2::pressMainMenu() {
    MenuWindow* menu = new MenuWindow();
    menu->show();
    this->close();
}
void tuto2:: pressNext(){
    tuto3* tuto = new tuto3();
    tuto->show();
    this->close();
}
void tuto2::pressPrec() {
    tuto1* tuto = new tuto1();
    tuto->show();
    this->close();
}
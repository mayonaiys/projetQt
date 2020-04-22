//
// Created by Théo on 21/04/2020.
//

#include "Level2.h"
#include <QFile>
#include <QTextStream>
using namespace std;

Level2::Level2(){
    this->background.load("../img/level2/FondEspace.png");
    this->setSceneRect(0, 0, background.width(), background.height());

    this->player = new Player("player", "../img/level2/player.png", 2 , background.height() -144 -25 );
    this->addItem(player);//144 sur 100 player.png

//    Ground* floor1 = new Ground("floor", "../img/level2/testfloor.png",0,0);
    Ground* floor2 = new Ground("floor", "../img/level2/floor.png",0,0);
    Flammes* lava = new Flammes("lava","../img/level2/lava.png",0,0);
    FinalFlag* flag = new FinalFlag("flag", "../img/level2/FInalFlag.png",0,0);
    MovingGround* mfloor = new MovingGround("mfloor", "../img/level2/movingfloor.png",293,831);
    Piece* c1 = new Piece("c1", "../img/level1/Coins.png",218,997);
    Piece* c2 = new Piece("c2", "../img/level1/Coins.png",791,473);
    Piece* c3 = new Piece("c3", "../img/level1/Coins.png",1383,493);

//    this->addItem(floor1);
    this->addItem(floor2);
    this->addItem(lava);
    this->addItem(flag);
    this->addItem(mfloor);
    this->addItem(c1);
    this->addItem(c2);
    this->addItem(c3);

}
void Level2::writescore(float time, int score){
    QString filePath = "../resultat/timer-score2.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QString buff = file.readAll();//contenu du fichier
    QTextStream flux(&file);
    flux.setCodec("UTF-8");

    if(buff.length() > 0){
//        cout<<"le fichier n'est pas vide\n";
//        QString nombre = buff;
        QString nombre = buff.split(" sec - ")[0];
        if(nombre.toFloat() > time){
            file.resize(0);
            flux <<time<<" sec - "<<score<<" pts";
        }
    }else{
//        cout<<"le fichier est vide et j'ecris dedans \n";
        flux <<time<<" sec - "<<score<<" pts";
    }

    file.close();
}
void Level2::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}

void Level2::keyPressEvent(QKeyEvent* event){
    this->player->keyPressEvent(background, event);

}

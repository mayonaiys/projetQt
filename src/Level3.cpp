//
// Created by Théo on 21/04/2020.
//

#include "Level3.h"
#include <QFile>
#include <QTextStream>
using namespace std;

Level3::Level3(){
    this->background.load("../img/level3/fond.png");
    this->setSceneRect(0, 0, background.width(), background.height());

    this->player = new Player("player", "../img/level2/player.png", 2 , background.height() -144 -25 );
    this->addItem(player);//144 sur 100 player.png

    Ground* sol  = new Ground("sol", "../img/level3/sol.png",0,0);
    Wall* wall = new Wall("wall", "../img/level3/wall.png",0,0);
    JetPack* jet = new JetPack("jet", "../img/level3/JetPack.png",1357,957);
    FinalFlag* flag = new FinalFlag("flag", "../img/level3/arr.png",0,0);
    Piece* c1 = new Piece("c1", "../img/level1/Coins.png",429,958);
    Piece* c2 = new Piece("c2", "../img/level1/Coins.png",1393,660);
    Piece* c3 = new Piece("c3", "../img/level1/Coins.png",792,394);

    this->addItem(sol);
    this->addItem(wall);
    this->addItem(jet);
    this->addItem(flag);
    this->addItem(c1);
    this->addItem(c2);
    this->addItem(c3);

}
void Level3::writescore(float time, int score){
    QString filePath = "../resultat/timer-score3.txt";
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
void Level3::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}

void Level3::keyPressEvent(QKeyEvent* event){
    this->player->keyPressEvent(background, event);

}

//
// Created by Théo on 17/04/2020.
//

#include "Level1.h"
using namespace std;

Level1::Level1() {
    this->background.load("../img/level1/FondEspace.png");
    this->setSceneRect(0, 0, background.width(), background.height());

    this->player = new Player("player", "../img/level1/player.png", 2 , background.height() -144 -23);
    this->addItem(player);//144 sur 100 player.png

    Ground* floor1 = new Ground("1floor", "../img/level1/1floor.png", 0, 0);
    Ground* floor2 = new Ground("2floor", "../img/level1/2floor.png",0,0);
    Ground* moon = new Ground(  "moon", "../img/level1/moon.png",0,0);
    Wall* wall1 = new Wall("wall1", "../img/level1/wall.png",0,0);
    Ground* floor4wall = new Ground("f4w", "../img/level1/floor4wall.png",0,0);
    Wall* wall4floor = new Wall("w4f", "../img/level1/wall4floor.png",0,0);
    FinalFlag* arrive = new FinalFlag("arrive", "../img/level1/finalFlag.png",0,0);
    Flammes* flammes = new Flammes("flammes", "../img/level1/flammes.png",0,0);
    Piece* c1 = new Piece("c1", "../img/level1/Coins.png",508,998);
    Piece* c2 = new Piece("c2", "../img/level1/Coins.png",1665,763);
    Piece* c3 = new Piece("c3", "../img/level1/Coins.png",776,503);

    this->addItem(floor1);
    this->addItem(floor2);
    this->addItem(moon);
    this->addItem(wall1);
    this->addItem(floor4wall);
    this->addItem(wall4floor);
    this->addItem(arrive);
    this->addItem(flammes);
    this->addItem(c1);
    this->addItem(c2);
    this->addItem(c3);

}
void Level1::writescore(float time, int score){
    ofstream wfile("../resultat/timer-score1.txt");
    ifstream rfile("../resultat/timer-score1.txt");
    if(!rfile){
        cout << "Error : Can't open the file" << endl;
    } else {
        string mot;
        getline(rfile, mot);
        cout <<mot<<endl;
        if(mot.length() != 0 ){
            if(stoi(mot) < time){
                wfile <<time <<" - "<<score<<endl;
            }
        } else {
            wfile <<time <<" - "<<score<<endl;
        }
        wfile.close();
        rfile.close();
    }
}
void Level1::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}

void Level1::keyPressEvent(QKeyEvent* event){
    this->player->keyPressEvent(background, event);

}


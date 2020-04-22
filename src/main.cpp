#include "MenuWindow.h"
#include <QApplication>
#include <fstream>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuWindow menu;
    menu.show();
//    GameWindow2* gameWindow = new GameWindow2();
//    gameWindow->show();

    return app.exec();
}

#include "MenuWindow.h"
#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MenuWindow menu;
    menu.show();
//    GameWindow* game = new GameWindow;
//    game->show();

    return app.exec();
}

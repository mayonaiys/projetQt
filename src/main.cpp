#include "GameWindow.h"

#include <QApplication>
#include <QTime>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    GameWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

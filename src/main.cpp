#include "MainWindow.h"

#include <QApplication>
#include <QTime>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

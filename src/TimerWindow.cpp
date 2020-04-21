//
// Created by Théo on 20/04/2020.
//

#include "TimerWindow.h"
TimerWindow::TimerWindow(QWidget *parent)
    :QMainWindow(parent)
{
    this->setWindowTitle("Theo LOPEZ");
    this->setFixedSize(1920,1080);

    window = new QWidget(this);
    window->setFixedSize(1920,1080);

    this->setCentralWidget(window);
    this->setCursor(Qt::CrossCursor);

    centralWidget()->setObjectName("window");
    centralWidget()->setStyleSheet("QWidget #window { background-image : url(../img/menu/TimerWindow.png);}");

    QLabel* labelTitle = new QLabel(window);

    QString filePath = "../resultat/timer-score1.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QString buff = file.readAll();//contenu du fichier
//    file.resize(0);
    QTextStream flux(&file);
    flux.setCodec("UTF-8");

    QFont f( "Arial", 30, QFont::Bold );
    labelTitle->setObjectName("label");
    labelTitle->setStyleSheet("QWidget #label {color : white;}");
    labelTitle->setFont(f);
    labelTitle->setText(buff);
    labelTitle->move(356,502);
    file.close();

    QPushButton* bMainMenu = new QPushButton(window);
    bMainMenu->setCursor(Qt::PointingHandCursor);
    bMainMenu->setFixedSize(162,142);
    bMainMenu->move(55,60);
    bMainMenu->setIcon(QIcon("../img/Bouton/MainPage.png"));
    bMainMenu->setIconSize(QSize(162,142));

    QPushButton* bReset = new QPushButton(window);
    bReset->setCursor(Qt::PointingHandCursor);
    bReset->setFixedSize(513,83);
    bReset->move(1358,180);
    bReset->setIcon(QIcon("../img/Bouton/ResetTimeScore.png"));
    bReset->setIconSize(QSize(513,83));

    connect(bMainMenu, SIGNAL(clicked()), this, SLOT(pressMainMenu()));
    connect(bReset, SIGNAL(clicked()), this, SLOT(pressReset()));

}
void TimerWindow:: pressMainMenu() {
    MenuWindow* menu = new MenuWindow();
    menu->show();
    this->close();
}
void TimerWindow:: pressReset() {
    QString filePath = "../resultat/timer-score1.txt";
    QFile file(filePath);
    file.resize(0);
    TimerWindow* restart = new TimerWindow();
    restart->show();
    this->close();
}
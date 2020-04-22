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

    ////////////////////
    QLabel* label1 = new QLabel(window);
    QString filePath = "../resultat/timer-score1.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QString buff = file.readAll();//contenu du fichier
    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    QFont f( "Arial", 30, QFont::Bold );
    label1->setObjectName("label");
    label1->setStyleSheet("QWidget #label {color : white;}");
    label1->setFont(f);
    label1->setText(buff);
    label1->move(482,572);
    file.close();
    /////////////

    QLabel* label2 = new QLabel(window);
    QString filePath2 = "../resultat/timer-score2.txt";
    QFile file2(filePath2);
    if (!file2.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QString buff2 = file2.readAll();//contenu du fichier
    QTextStream flux2(&file2);
    flux2.setCodec("UTF-8");
    label2->setObjectName("label");
    label2->setStyleSheet("QWidget #label {color : white;}");
    label2->setFont(f);
    label2->setText(buff2);
    label2->move(482,727);
    file2.close();

    /////////////
    QLabel* label3 = new QLabel(window);
    QString filePath3 = "../resultat/timer-score3.txt";
    QFile file3(filePath3);
    if (!file3.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QString buff3 = file3.readAll();//contenu du fichier
    QTextStream flux3(&file3);
    flux3.setCodec("UTF-8");
    label3->setObjectName("label");
    label3->setStyleSheet("QWidget #label {color : white;}");
    label3->setFont(f);
    label3->setText(buff3);
    label3->move(482,883);
    file3.close();


    ///////////////BOUTONS
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

    QString filePath2 = "../resultat/timer-score2.txt";
    QFile file2(filePath2);
    file2.resize(0);

    QString filePath3 = "../resultat/timer-score3.txt";
    QFile file3(filePath3);
    file3.resize(0);

    TimerWindow* restart = new TimerWindow();
    restart->show();
    this->close();
}
#include <QApplication>
#include "gameenvironment.h"
#include <QSplashScreen>
#include <QTimer>



GameEnvironment * game; // game object was made global as many objects need access to this throughout the program

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    //Adding a splash screen before the game starts
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/Splash/IMG_515648.jpg"));
    splash->show();


    QTimer::singleShot(5000,splash,SLOT(close()));
    QTimer::singleShot(5000,game,SLOT(show()));
    game = new GameEnvironment();


    game->show();

    return a.exec();
}

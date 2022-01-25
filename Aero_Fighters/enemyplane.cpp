#include "enemyplane.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> //In order to use rand() function
#include "gameenvironment.h"

extern GameEnvironment * game; //Usage of the global variable game

EnemyPlane::EnemyPlane(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Setting the random x position
    int random_number = rand() % 1000;//this is less than the screen width of our game. The remainder 1200 will be generated from rand() so that the enemy planes will not b created and shown off the screen
    setPos(random_number,0);

    //Customizing the enemy planes and adding an image to be displayed as the enemy planes
    setPixmap(QPixmap(":/Enemy/Airplane_Five.png"));

    //Making the enemy plane rotate 180 degrees
    setTransformOriginPoint(50,50);
    setRotation(180);

    //Connecting a timer to PlaneMotion() function
    QTimer * clock = new QTimer(this);

    //QTimer will continue a timer and every 50 mili sec PlaneMotion() will be called
    connect(clock,SIGNAL(timeout()),this,SLOT(planeMotion()));

    //Starting the timer
    clock->start(50);
}

void EnemyPlane::planeMotion()
{
    //Setting the enemy plane movement downwards. The enemy planes must be slower than bullets so 5 is used here
    setPos(x()+1,y()+5);

    //Deleting the enemy plane from the memory as soon as it leaves the screen and also decreases the health(Game rule)
    if (pos().y() > 768)
    {
        //To decrease the health of the Player
        game->health->healthReduction();

        scene()->removeItem(this);
        delete this;
    }
}

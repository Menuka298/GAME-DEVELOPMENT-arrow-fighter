#include "missile.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemyplane.h"
#include "gameenvironment.h"
#include <typeinfo>

extern GameEnvironment * game; // calling the external global object called game available at the main

Missile::Missile(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Drawing and customizing the missile
    setPixmap(QPixmap(":/MissileImage/MissileFired.png"));


    //Connecting a timer to MissileMotion()
    QTimer * clock= new QTimer(this);

    //SIGNAL and SLOT connection.For every 50 mili secs the missile will move up
    connect(clock,SIGNAL(timeout()),this,SLOT(MissileMotion()));

    //Starting the timer
    clock->start(50);


    blastSound=new QMediaPlayer();

    //Setting missile launching sound
    blastSound->setMedia(QUrl("qrc:/Blast/Bomb-SoundBible.com-891110113.mp3"));
}

void Missile::MissileMotion()
{
    //Getting a list of te items colliding with the missile. Used "collidingItems()" (This will return set of pointers) member function availbale inside QGraphicsItems
    QList<QGraphicsItem *> Colliding_Items = collidingItems();//holds all the data about the colliding items by the missile

    //If the missile is colliding with an enemy plane, both the missile and the enemy plane will be destroyed
    for (int i = 0, n =  Colliding_Items.size(); i < n; ++i)
    {
        if (typeid(*( Colliding_Items[i])) == typeid(EnemyPlane)) //"typeid()" (available at <typeinfo>) will determine the type of the object colliding with the missile. Here if it is a enemy plane,the statement block will be executed down bellow
        {
            //Increasing the score
            game->score->ScoreIncrement(); //ScoreIncrement() will be clled to whenever after a collision with an enemy to increase the score by 1

            //Removing the colliding items from the gaming envirinment
            scene()->removeItem(Colliding_Items[i]);//Removing the enemy plane
            scene()->removeItem(this);//Removing the missile


            //Playing the sound when a missile destroys a enemy plane
            if(blastSound->state()==QMediaPlayer::PlayingState)//state() function is used to identify the sound clip's current state
            {
                blastSound->setPosition(0);
            }
            else if(blastSound->state()==QMediaPlayer::StoppedState)//The sound clip will be played again if it is at the stopped state
            {
                blastSound->play();
            }

            //Deleting both the above from memory completely to save memory
            delete  Colliding_Items[i];
            delete this;

            //Getting out of this member function
            return;
        }
    }

    //Moving the missile up if there is no collision with an enemy plane
    setPos(x(),y()-10);

    //Destroying the missile if it leaves the screen
    if (pos().y() < 0){
       scene()->removeItem(this);
        delete this;
    }
}

#include "playerplane.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "missile.h"
#include "enemyplane.h"

PlayerPlane::PlayerPlane(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    missileSound=new QMediaPlayer();

    //Setting missile launching sound
    missileSound->setMedia(QUrl("qrc:/Missile/Sound2.mp3"));

    //Setting the Player's plane and adding an image as the plane
    setPixmap(QPixmap(":/Player/Airplane_Four.png"));

}

void PlayerPlane::keyPressEvent(QKeyEvent * KeyEvent){

    //Moving the player's plane to left and to right, Used QKeyEvent for this manipulation
    if (KeyEvent->key() == Qt::Key_Left) //Moving the plane to left
    {
        if (pos().x() > 0)
        setPos(x()-10,y());
    }

    else if (KeyEvent->key() == Qt::Key_Right) //Moving the plane to right
    {
        if (pos().x() + 100 < 1300)
        setPos(x()+10,y());
    }

    //Shooting the enemy palnes by pressing the the spacebar. Used the features available in graphics QKeyEvent for this as well
    else if (KeyEvent->key() == Qt::Key_Space)
    {
        //Creating the firing missiles from the player's plane. For every key press, a missile will be launched
        Missile * missile1 = new Missile();
        Missile * missile2 = new Missile();

        //Setting the missilles' originating positions
        missile1->setPos(x()+15,y());
        missile2->setPos(x()+140,y());

        //Adding the created missiles to the gaming environment
        scene()->addItem(missile1);
        scene()->addItem(missile2);

        //Playing the sound right after the missiles' launching
        if(missileSound->state()==QMediaPlayer::PlayingState)//state() function is used to identify the sound clip's current state
        {
            missileSound->setPosition(0);
        }
        else if(missileSound->state()==QMediaPlayer::StoppedState)//The sound clip will be played again if it is at the stopped state
        {
            missileSound->play();
        }

    }
}

void PlayerPlane::SpawnEnemies()
{
    //Creating the enemy planes. Everytime the Slot is activated(After 1500 mili secs, this function will be called)
    EnemyPlane * enemyPlane = new EnemyPlane();
    connect(this, SIGNAL(destroyEnemies()), enemyPlane , SLOT(deleteLater()));
    //Adding the enemy planes to the gaming environment
    scene()->addItem(enemyPlane);
}

void PlayerPlane::gameIsover()
{
    emit destroyEnemies();
}


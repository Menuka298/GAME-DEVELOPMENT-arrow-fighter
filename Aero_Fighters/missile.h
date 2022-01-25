#ifndef MISSILE_H
#define MISSILE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>//To add images and other graphics to the gaming window

class Missile: public QObject,public QGraphicsPixmapItem
{
    //Q_Object is inserted to handle the SIGNAL SLOT connection
    Q_OBJECT
public:

    Missile(QGraphicsItem * parent=0);

public slots:

    //Member function to customize the missiles driven from player's plane
    //Contains SIGNAL timeout.The timeout will be called after each 50 mili secs. Then the SLOT haviing MissileMotion will be called making the bullet to move
    void MissileMotion();


private:

    //To add a sound to the missile when it is being fired
    QMediaPlayer * blastSound;
};

#endif // MISSILE_H

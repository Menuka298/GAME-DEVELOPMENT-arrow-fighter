#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QGraphicsPixmapItem>
#include <QObject>//For objects handle SIGNALS and SLOTS this must be inherited : Requirement 1
#include <QGraphicsItem>



class EnemyPlane: public QObject,public QGraphicsPixmapItem
{
    //QObject Macro is inserted as requirement 2 to handle SIGNAL and SLOTS
    Q_OBJECT
public:

    EnemyPlane(QGraphicsItem * parent=0);

public slots:

    //Manipulates the movement and the deletion of the enemy plane from memory. Also Connects to SIGNAL and SLOT function
    void planeMotion();
};

#endif // ENEMYPLANE_H

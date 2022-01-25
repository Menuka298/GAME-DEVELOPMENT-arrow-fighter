#ifndef PLAYERHEALTH_H
#define PLAYERHEALTH_H
#include <QGraphicsTextItem>

class PlayerHealth: public QGraphicsTextItem{
    Q_OBJECT
public:
    PlayerHealth(QGraphicsItem * parent=0);

    //To reduce the health after each collision with the enemy or enemy leaves the screen without being destroyed
    void healthReduction();

    //To return the current health
    int getHealth();

private:
    //To hold the player plane's health
    int health;
signals:
    void planeCrashed();
};

#endif // PLAYERHEALTH_H

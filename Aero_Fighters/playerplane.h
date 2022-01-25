#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class PlayerPlane:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PlayerPlane(QGraphicsItem * parent=0);

    //Member function to process key press events during the game
    void keyPressEvent(QKeyEvent * KeyEvent);

public slots:

    //This member function will be called every once in while and new enemy palnes will be created according to the Signal provided in GameEnvironment class
    void SpawnEnemies();
    void gameIsover();

private:

    //To add a sound to the missile when it is being fired
    QMediaPlayer * missileSound;
signals:
    void destroyEnemies();

};

#endif // PLAYERPLANE_H

#ifndef GAMEENVIRONMENT_H
#define GAMEENVIRONMENT_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "playerplane.h"
#include "playerscore.h"
#include "playerhealth.h"
#include <QGraphicsView>
#include "gameover.h"

class GameEnvironment: public QGraphicsView
{
    Q_OBJECT
public:
    GameEnvironment(QWidget * parent=0);
    QGraphicsScene *scene = new QGraphicsScene; //Creating the gaming background. The GameScene object is created and will be used everytime whenever an new object is added to the gaming background
    //pointer to each available class in the application. So that later itts member functions can be accessed whenever they are needed
    PlayerPlane * playerPlane;
    PlayerScore * score;
    PlayerHealth * health;
    GameOver *gameOverScene = new GameOver;
    QMediaPlayer * sound;
private:
    void destroyAll();
    QTimer * timer;
public slots:
    void gameOver();
private slots:
    void startNewGame();
signals:
    void gameIsOver();

};

#endif // GAMEENVIRONMENT_H

#include "gameenvironment.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemyplane.h"
#include <QMediaPlayer>



GameEnvironment::GameEnvironment(QWidget*)
{
    connect(gameOverScene, SIGNAL(startNew()), this, SLOT(startNewGame())); //connect start button click on game over scene with startNewGame function here

    //Spawning enemy aeroplanes every 2000 mili seconds. Used QTimer to continue a timer
    timer = new QTimer(this);
    timer->setInterval(1500);
    timer->start();
    this->startNewGame();
    //Showing the gaming window
    show();
}

void GameEnvironment::destroyAll()
{
    //Removing all the items from the memory and the screen

    //Deleting the player's plane from the game
    scene->removeItem(playerPlane);

    //Removing the player's plane from memory
    delete playerPlane;

    //Removing health
    scene->removeItem(health);

    //Resetting and deleting the score recorded from the memory
    score->reset();
    scene->removeItem(score);
    delete score;
    delete sound;
}

void GameEnvironment::gameOver()
{
    //Stopping everything including the sounds
    emit gameIsOver();
    timer->stop();
    this->items().clear();
    sound->stop();
    gameOverScene->setScore(score->getScore());
    this->destroyAll();
    this->setScene(gameOverScene);
}

void GameEnvironment::startNewGame()
{
    scene->items().clear();
    if(!timer->isActive())
        timer->start();
    //Made the gaming window 1366 x 768  instead of default(my PC's screen size)
    scene->setSceneRect(0,0,1300,700);
    scene->setBackgroundBrush(QBrush(QImage(":/BgImage/sky-wallpapers-background-For-Desktop-Wallpaper.jpg")));

    //Making the newly created Gamescene the scene to visualize the game to the user(as Game is a QGraphicsView Widget,It can be used to visualize scenes)
    setScene(scene);

    //Turning off the horizontal scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Turning off the vertical scroll bar
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Screen won't change after this. The screen will stay fixed at the given size
    setFixedSize(1300,700);

    //Creating the player
    playerPlane = new PlayerPlane();
    QObject::connect(timer,SIGNAL(timeout()),playerPlane,SLOT(SpawnEnemies()));// Signal is timeout(after every 1500 mili scs) an enemy will be created)
    QObject::connect(this, SIGNAL(gameIsOver()), playerPlane, SLOT(gameIsover()));
    //The palyer's initial position will always be in the middle bottom screen
    playerPlane->setPos(600,570);

    //Making the player plane focusable and set it to be the current focus
    playerPlane->setFlag(QGraphicsItem::ItemIsFocusable);
    playerPlane->setFocus();

    //Adding the Player's plane to the gaming environment
    scene->addItem(playerPlane);

    //Create the score
    score = new PlayerScore;
    score->setPos(score->x()+1100,score->y()+30);//The score display text will be displayed 30 pixels down from the top right corner of the screen
    scene->addItem(score);

    //Adding and positioning the Player's health on the game window
    health = new PlayerHealth();
    health->setPos(health->x()+30,health->y()+30);//The health will be displayed 30 pixels downward from the top left of the screen. Bellow the score display text.
    connect(health, SIGNAL(planeCrashed()), this, SLOT(gameOver())); //game is over if health reached 0
    scene->addItem(health);

    //Playing the background music
    sound = new QMediaPlayer();
    sound->setMedia(QUrl("qrc:/BGSound/Backg.mp3"));
    sound->play();
}


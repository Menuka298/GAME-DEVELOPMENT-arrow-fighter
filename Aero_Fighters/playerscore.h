#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H
#include <QGraphicsTextItem>

class PlayerScore: public QGraphicsTextItem{
public:
    PlayerScore(QGraphicsItem * parent=0);
    void ScoreIncrement();//To increase the current score
    int getScore();
    void reset();
private:
    //Memory variable to hold the current score of the player
    int score;
};
#endif // PLAYERSCORE_H

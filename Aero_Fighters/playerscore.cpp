#include "playerscore.h"
#include <QFont>//This class is used add and customize the display text of the score of the player

PlayerScore::PlayerScore(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //Making the score 0. So that it can be incremented accordingly
    score = 0;

    //Customizing the displaying text
    setPlainText(QString("Score   ") + QString::number(score)); //Initial score will be displayed as Score: 0

    //Setting the display text color to Black
    setDefaultTextColor(Qt::red);

    //Setting the font style and size respectively to given font style and size
     setFont(QFont("Helvetica",18,QFont::Bold));
}


void PlayerScore::ScoreIncrement()
{
    //The score will be incremented
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); //After the th first collision of a missile with an enemy plane the score will be - Score: 1
}

int PlayerScore::getScore()
{
    //Returning the curent score of the player
    return score;
}

void PlayerScore::reset()
{
    this->score = 0;
}

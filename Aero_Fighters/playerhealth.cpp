#include "playerhealth.h"
#include <QFont>//Used to customize the letters of the labels, font, font color and etc

PlayerHealth::PlayerHealth(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
   //Initializing the score to be 5 at first
   health = 5;

   //Customizing the display text on the screen
   setPlainText(QString("Player Health   ") + QString::number(health)); //The health will b displayed initially as "Player Health: 5"

   //Font color will be red
   setDefaultTextColor(Qt::red);

   //The font size will be 18 and font style will be Helvetica. And the text will be bold
   setFont(QFont("Helvetica",18,QFont::Bold));
}

void PlayerHealth::healthReduction()
{
   //Decrementing the health
   health--;
   if(this->getHealth() < 1){
       health = 5;
       emit this->planeCrashed();
   }
   else{
        setPlainText(QString("Player Health  ") + QString::number(health)); // After one collision health will be 4
   }
}

int PlayerHealth::getHealth()
{
   //Returning the current health amount
   return health;
}

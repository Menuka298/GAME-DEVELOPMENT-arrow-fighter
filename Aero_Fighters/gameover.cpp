#include "gameover.h"

GameOver::GameOver(QGraphicsView*)
{
    //Buttons representing start and quit options
    startGame = new QPushButton;
    exitGame = new QPushButton;

    //Customizing buttons
    startGame->setStyleSheet("font-weight:bold;font-size:16pt;");
    exitGame->setStyleSheet("font-weight:bold;font-size:16pt;");

    //Signal and slot connection to start and quit the game
    connect(startGame, SIGNAL(clicked(bool)), this, SLOT(startNewGame()));
    connect(exitGame, SIGNAL(clicked(bool)), this, SLOT(exitThisGame()));

    //Customizing the Start button
    startGame->setText("START NEW");
    startGame->setGeometry(650,290, 250, 100);
    this->addWidget(startGame);

    //Customizing the Quit button
    exitGame->setText("QUIT");
    exitGame->setGeometry(650,410, 250, 100);
    this->addWidget(exitGame);

    this->score = new QGraphicsTextItem;
    this->score->setPos(650, 160);
    this->addItem(this->score);
}

void GameOver::setScore(int score)
{
    //Adding scre label to the game over window
    this->score->setPlainText(QString("YOUR SCORE : ") + QString::number(score));

    this->score->setDefaultTextColor(Qt::black);

    this->score->setFont(QFont("Helvetica",18,QFont::Bold));
}

void GameOver::drawBackground(QPainter *painter, const QRectF &rect)
{
    //change game over background image here
    QPixmap backBg(":/BgImage/thumb-1920-343137.jpg");
    QRectF rectf = QRectF(backBg.rect());
    painter->drawPixmap(rect, backBg, rectf);
}

void GameOver::startNewGame()
{
    emit startNew();
}

void GameOver::exitThisGame()
{
    exit(0);
}


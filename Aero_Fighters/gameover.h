#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsTextItem>

class GameOver: public QGraphicsScene
{
    Q_OBJECT
public:
    GameOver(QGraphicsView * parent=0);
    void setScore(int score);
    QGraphicsTextItem *score;
    void drawBackground(QPainter *painter, const QRectF &rect);
private:
    QPushButton *startGame;
    QPushButton *exitGame;
signals:
    void startNew();
private slots:
    void startNewGame();
    void exitThisGame();
};

#endif // GAMEOVER_H

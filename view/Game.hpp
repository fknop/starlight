#ifndef GAME_HPP
#define GAME_HPP

#include <QWidget>
#include "model/level.h"

class GameView : public QWidget
{
    Q_OBJECT
public:
    explicit GameView(Level * level, QWidget *parent = 0);
    ~GameView();


private:
    void paintEvent(QPaintEvent *event);
    void drawSegment(QPainter *p, int x1, int y1, int x2, int y2);
    void drawRect(QPainter *p, int posX, int posY, int width, int height);
    void drawMirror(QPainter *p, int pivotX, int pivotY, int xpad, int len, double angle);
    void drawEllipse(QPainter *p, int x, int y, int rad);
    Level * level;

};

#endif // GAME_HPP

#include "Game.hpp"
#include <cmath>
#include <QPicture>
#include <QPainter>
#include <QPushButton>

GameView::GameView(Level * level, QWidget *parent) :
    QWidget(parent)
{
    this->level = level;
    this->setFixedSize(this->level->getWidth(), this->level->getHeight());
}

GameView::~GameView()
{
    delete level;
}



/**
 * @brief MainWindow::drawSource Dessine une source de rayon lumineux.
 * @param p le QPainter dans lequel placer la source.
 * @param posX abscisse de la position du coin supérieur gauche de la source.
 * @param posY ordonnée de la position du coin supérieur gauche de la source.
 * @param width longueur de la source.
 * @param height hauteur de la source.
 */
void GameView::drawRect(QPainter *p, int posX, int posY, int width, int height)
{
    QRect r(posX, posY, width, height);
    p->drawRect(r);

}

/**
 * @brief MainWindow::drawSegment Trace un segment de droite entre 2 points.
 * @param p le QPainter dans lequel placer le segment.
 * @param x1 abscisse du premier point.
 * @param y1 ordonnée du premier point.
 * @param x2 abscisse du deuxième point.
 * @param y2 ordonnée du deuxième point.
 */
void GameView::drawSegment(QPainter *p, int x1, int y1, int x2, int y2)
{
    p->drawLine(QPoint(x1, y1), QPoint(x2, y2));
}


void GameView::drawMirror(QPainter *p, int pivotX, int pivotY, int len, int xpad, double angle)
{
    //QPointF pivot(pivotX, pivotY);


    int gx = pivotX -  (xpad * cos(angle));
    int gy = pivotY - (xpad * sin(angle));
    int dx = pivotX + ((len-xpad) * cos(angle));
    int dy = pivotY + ((len-xpad) * sin(angle));


    QPoint bordGauche(gx, gy);
    QPoint bordDroit (dx, dy);


    p->drawLine(bordGauche, bordDroit);
}

void GameView::drawEllipse(QPainter *p, int x, int y, int rad)
{
    p->drawEllipse(QPoint(x, y), rad, rad);
}

void GameView::paintEvent(QPaintEvent *event)
{
    //create a QPainter and pass a pointer to the device.
    //A paint device can be a QWidget, a QPixmap or a QImage

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    Source s = level->getSource();
    Dest d = level->getDestination();



    drawRect(&painter, s.getPosition().getX(), s.getPosition().getY(), s.getEdge(), s.getEdge());
    drawRect(&painter, d.getPosition().getX(), d.getPosition().getY(), d.getEdge(), d.getEdge());


    for (auto &i : this->level->getMirrors())
    {
        double angle = i.getAngle();
        int xpad = i.getXPad();
        int pivotX = i.getPivot().getX();
        int pivotY = i.getPivot().getY();
        int len = i.getLength();

        drawMirror(&painter, pivotX, pivotY, len, xpad, angle);
    }


    for (auto &i : this->level->getWalls())
    {
        int x1, x2, y1, y2;
        x1 = i.getStart().getX();
        x2 = i.getEnd().getX();
        y1 = i.getStart().getY();
        y2 = i.getEnd().getY();

        drawSegment(&painter, x1, y1, x2, y2);
    }


    for (auto &i : this->level->getNukes())
    {
        drawEllipse(&painter, i.getLocation().getX(), i.getLocation().getY(), i.getRadius());
    }


    for (auto &i : this->level->getCrystals())
    {
        drawEllipse(&painter, i.getCenter().getX(), i.getCenter().getY(), i.getRadius());
    }


    for (auto &i : this->level->getLenses())
    {
        drawRect(&painter, i.getPosition().getX(), i.getPosition().getY(), i.getWidth(), i.getHeight());
    }
}

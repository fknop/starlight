//#include <iostream>

//#include "model/level.h"
//#include "MapReader.h"
//#include <typeinfo>
//#include "view/Game.hpp"
//#include <QApplication>

//using namespace std;


////int argc, char *argv[]
//int main(int argc, char * argv[])
//{
//    QApplication a(argc, argv);


//    Level * level = MapReader::getLevel("levels/level1.lvl");
//    level->computeRays();
//    GameView * game = new GameView(level);
//    game->show();
//    a.exec();

//    delete level;

//    return 0;

//}


//#include <QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class GraphicsLineItem : public QGraphicsLineItem
{
public:
    GraphicsLineItem()
    {
        rotation = 0;
        setFlags(flags() | QGraphicsItem::ItemIsSelectable);
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        initialPos = mapToScene(event->pos());
        QGraphicsItem::mousePressEvent(event);
    }

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
    {
        QPointF pos = mapToScene(event->pos());

        if (pos.y() > initialPos.y())
        {
            ++rotation;
        }
        else
        {
            --rotation;
        }

        //#if 1
        //    QTransform xform;
        //    xform.rotate(rotation);
        //    setTransform(xform);
        //#else
        setRotation(rotation);
        //#endif
        //    initialPos = pos;
    }
    QPointF initialPos;
    qreal rotation;

};


class GraphicsView : public QGraphicsView
{
public:
    GraphicsView()
    {
        QGraphicsScene *scene = new QGraphicsScene();
        setScene(scene);
        QRect rectangle(10, 20, 80, 60);
        QRect rectangle2(50, 80, 80, 60);


        GraphicsLineItem *item1 = new GraphicsLineItem();
        item1->setLine(-40, -30, 80, 60);
        //item1->setRect(-40, -30, 80, 60);
        scene->addItem(item1);
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    GraphicsView box;
    box.show();
    return app.exec();
}

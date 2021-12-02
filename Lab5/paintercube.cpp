#include "paintercube.h"
#include <QGraphicsView>

void  PainterCube::paint_first_cube(QGraphicsScene * scene, int x, int y, int width_cube, int height_cube)
{
    QPixmap w_cube(":/images/image/cube1.png");
    w_cube = w_cube.scaled(width_cube,height_cube);
    QPen pen;
    QGraphicsItem* g_item = scene->addPixmap(w_cube);
    g_item->setPos(x, y);
}

void  PainterCube::paint_second_cube(QGraphicsScene * scene, int x, int y, int width_cube, int height_cube)
{
    QPixmap h_cube(":/images/image/cube2.png");
    h_cube = h_cube.scaled(width_cube,height_cube);
    QPen pen;
    QGraphicsItem* g_item =  scene->addPixmap(h_cube);
    g_item->setPos(x, y);
}

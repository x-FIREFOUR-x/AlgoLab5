#ifndef PAINTERCUBE_H
#define PAINTERCUBE_H
#include <QBrush>
#include <QGraphicsItem>

class PainterCube
{
    public:
    // малює cube(територію) яку ставить перший гравець вертикальну(синю)
    static void paint_first_cube(QGraphicsScene * scene, int x, int y, int width_cube, int height_cube);

    // малює cube(територію) яку ставить другий гравець горизонтальну(червону)
    static void paint_second_cube(QGraphicsScene * scene, int x, int y, int width_cube, int height_cube);

};

#endif // PAINTERCUBE_H

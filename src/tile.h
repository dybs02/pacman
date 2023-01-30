#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>
#include "definitions.h"

class Tile : public QGraphicsRectItem
{
public:
    int x;
    int y;
    tileType type;
    void* item;

    Tile(int x, int y, tileType type);
};

#endif // TILE_H

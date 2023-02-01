#ifndef TILEMAP_H
#define TILEMAP_H

#include <cmath>
#include <QPoint>
#include "tile.h"
#include "definitions.h"

class TileMap
{
    Tile* tileMap[WIDTH][HEIGHT];

public:
    TileMap();
    ~TileMap();

    Tile* setTile(int x, int y, Tile* tile);
    Tile* tileAtIndex(int x, int y);
    Tile* tileAtIndex(QPoint indexes);
    float distance(int x1, int y1, int x2, int y2);
    float distance(QPoint indexes1, QPoint indexes2);
};

#endif // TILEMAP_H

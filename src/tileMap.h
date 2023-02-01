#ifndef TILEMAP_H
#define TILEMAP_H

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
};

#endif // TILEMAP_H

#include "tileMap.h"

TileMap::TileMap()
{

}

TileMap::~TileMap()
{
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            delete tileMap[x][y];
        }
    }

}

Tile* TileMap::setTile(int x, int y, Tile* tile)
{
    tileMap[x][y] = tile;

    return tileMap[x][y];
}

Tile* TileMap::tileAtIndex(int x, int y)
{
    return tileAtIndex(QPoint(x, y));
}

Tile* TileMap::tileAtIndex(QPoint indexes)
{
    return tileMap[indexes.x()][indexes.y()];
}

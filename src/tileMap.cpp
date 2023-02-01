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

float TileMap::distance(int x1, int y1, int x2, int y2)
{
    return distance(QPoint(x1, y1), QPoint(x2, y2));
}

float TileMap::distance(QPoint indexes1, QPoint indexes2)
{
    float xDelta = indexes1.x() - indexes2.x();
    float yDelta = indexes1.y() - indexes2.y();

    return sqrt(pow(xDelta, 2) + pow(yDelta, 2));
}

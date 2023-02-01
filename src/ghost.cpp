#include "ghost.h"
#include <QDebug>

Ghost::Ghost(int tileX, int tileY, TileMap* tileMap)
    : QGraphicsPixmapItem(), Entity(tileX, tileY, tileMap)
{
    setPixmap(objectsPixmap.copy(180, 30, TILE_SIZE, TILE_SIZE));
    currnetDirection = LEFT;

    targetX = 0;
    targetY = 0;
}

void Ghost::setTargetTile(int tileX, int tileY)
{
    targetX = tileX;
    targetY = tileY;
}

void Ghost::move()
{
    QPoint next = nextTile();

    Entity::moveTo(next.x(), next.y());
    setPos(posX, posY);
}

QPoint Ghost::nextTile()
{
    float minDist = MAXFLOAT;
    Tile* minDistTile = tileMap->tileAtIndex(tileX, tileY);
    direction newDirection = currnetDirection;

    // Up
    Tile* upTile = tileMap->tileAtIndex(tileX, tileY-1);
    float upTileDist = tileMap->distance(targetX, targetY, tileX, tileY-1);

    if (upTile->type != wall && currnetDirection != DOWN) {
        if (upTileDist <= minDist) {
            minDist = upTileDist;
            minDistTile = upTile;
            newDirection = UP;
        }
    }

    // Down
    Tile* downTile = tileMap->tileAtIndex(tileX, tileY+1);
    float downTileDist = tileMap->distance(targetX, targetY, tileX, tileY+1);

    if (downTile->type != wall && currnetDirection != UP) {
        if (downTileDist <= minDist) {
            minDist = downTileDist;
            minDistTile = downTile;
            newDirection = DOWN;
        }
    }

    // Left
    Tile* leftTile = tileMap->tileAtIndex(tileX-1, tileY);
    float leftTileDist = tileMap->distance(targetX, targetY, tileX-1, tileY);

    if (leftTile->type != wall && currnetDirection != RIGHT) {
        if (leftTileDist <= minDist) {
            minDist = leftTileDist;
            minDistTile = leftTile;
            newDirection = LEFT;
        }
    }

    // Right
    Tile* rightTile = tileMap->tileAtIndex(tileX+1, tileY);
    float rightTileDist = tileMap->distance(targetX, targetY, tileX+1, tileY);

    if (rightTile->type != wall && currnetDirection != LEFT) {
        if (rightTileDist <= minDist) {
            minDist = rightTileDist;
            minDistTile = rightTile;
            newDirection = RIGHT;
        }
    }

    qDebug() << "target: x=" << targetX << ", y="<< targetY;
    qDebug() << newDirection << ", x=" << minDistTile->x << ", y="<< minDistTile->y;

    // should not be updated here
    currnetDirection = newDirection;
    return QPoint(minDistTile->x, minDistTile->y);
}

#include "entity.h"


Entity::Entity(int tileX, int tileY, TileMap* tileMap) : tileX(tileX), tileY(tileY)
{
    posX = tileX * TILE_SIZE;
    posY = tileY * TILE_SIZE;

    currnetDirection = LEFT;
    objectsPixmap = QPixmap(OBJECTS_PIXMAP);

    this->tileMap = tileMap;
}

void Entity::moveBy(float x, float y)
{
    posX += x;
    posY += y;

    tileX = posX / TILE_SIZE;
    tileY = posY / TILE_SIZE;
}

void Entity::moveTo(int tileX, int tileY)
{
    this->tileX = tileX;
    this->tileY = tileY;

    posX = tileX * TILE_SIZE;
    posY = tileY * TILE_SIZE;
}

QPoint Entity::nextTile()
{
    switch (currnetDirection) {
    case UP:
        return QPoint(tileX, tileY-1);
    case DOWN:
        return QPoint(tileX, tileY+1);
    case LEFT:
        return QPoint(tileX-1, tileY);
    case RIGHT:
        return QPoint(tileX+1, tileY);
    case NONE:
        return QPoint(tileX, tileY);
    }
}

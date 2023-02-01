#ifndef ENTITY_H
#define ENTITY_H

#include <QPixmap>

#include "tileMap.h"
#include "tile.h"
#include "definitions.h"

class Entity
{
public:
    float posX;
    float posY;
    int tileX;
    int tileY;
    direction currnetDirection;
    QPixmap objectsPixmap;
    TileMap* tileMap;

    Entity(int tileX, int tileY, TileMap* tileMap);

    void moveBy(float x, float y);
    void moveTo(int tileX, int tileY);
    virtual QPoint nextTile() = 0;
    virtual void move() = 0;
};

#endif // ENTITY_H

#ifndef ENTITY_H
#define ENTITY_H

#include <QPixmap>

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
    Tile* (*tileMap)[WIDTH][HEIGHT];

    Entity(int tileX, int tileY, Tile* (&tileMap)[WIDTH][HEIGHT]);

    void moveBy(float x, float y);
    void moveTo(int tileX, int tileY);
    QPoint nextTile();
    Tile* tileAtIndex(QPoint indexes);
};

#endif // ENTITY_H

#include "inky.h"

Inky::Inky(TileMap* tileMap)
    : Ghost(GHOST_SPAWN_X+2, GHOST_SPAWN_Y, tileMap)
{
    setPixmap(objectsPixmap.copy(30, 90, OBJECT_SIZE, OBJECT_SIZE).scaled(TILE_SIZE, TILE_SIZE));
    currnetDirection = LEFT;

    scatterX = 1;
    scatterY = HEIGHT;
    setModeScatter();
}


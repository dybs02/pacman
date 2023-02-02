#include "pinky.h"

Pinky::Pinky(TileMap* tileMap)
    : Ghost(GHOST_SPAWN_X+1, GHOST_SPAWN_X, tileMap)
{
    setPixmap(objectsPixmap.copy(30, 60, OBJECT_SIZE, OBJECT_SIZE).scaled(TILE_SIZE, TILE_SIZE));
    currnetDirection = LEFT;

    scatterX = 1;
    scatterY = 1;
    setModeScatter();
}

#include "blinky.h"

Blinky::Blinky(TileMap* tileMap)
    : Ghost(GHOST_SPAWN_X, GHOST_SPAWN_Y, tileMap)
{
    setPixmap(objectsPixmap.copy(30, 30, OBJECT_SIZE, OBJECT_SIZE).scaled(TILE_SIZE, TILE_SIZE));
    currnetDirection = LEFT;

    scatterX = WIDTH-1;
    scatterY = 1;
    setModeScatter();
}

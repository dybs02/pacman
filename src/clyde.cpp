#include "clyde.h"

Clyde::Clyde(TileMap* tileMap)
    : Ghost(GHOST_SPAWN_X+3, GHOST_SPAWN_Y, tileMap)
{
    setPixmap(objectsPixmap.copy(30, 120, OBJECT_SIZE, OBJECT_SIZE).scaled(TILE_SIZE, TILE_SIZE));
    currnetDirection = LEFT;

    scatterX = WIDTH-1;
    scatterY = HEIGHT-1;
    setModeScatter();
}


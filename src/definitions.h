#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define TILE_SIZE 20
#define OBJECT_SIZE 30
#define WIDTH 28
#define HEIGHT 36

#define GHOST_SPAWN_X 14
#define GHOST_SPAWN_Y 17

#define MOVE_SPPED 0.5f
#define FPS 60

#define OBJECTS_PIXMAP ":/resources/sprites/objects.png"

enum tileType {
    empty,
    wall,
    boost,
    coin,
    pacman
};


enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

#endif // DEFINITIONS_H

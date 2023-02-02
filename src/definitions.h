#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define TILE_SIZE 20
#define OBJECT_SIZE 30
#define WIDTH 28
#define HEIGHT 36

#define GHOST_SPAWN_X 13
#define GHOST_SPAWN_Y 18
#define MODE_DELAY 10000

#define MOVE_SPPED 0.5f
#define FPS 4

#define OBJECTS_PIXMAP ":/resources/sprites/objects.png"
#define PATH_TO_FONT ":/resources/fonts/arcadepi.ttf"

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

enum ghostMode {
    CHASE,
    SCATTER
};

#endif // DEFINITIONS_H

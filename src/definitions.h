#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define TILE_SIZE 20
#define WIDTH 28
#define HEIGHT 36

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

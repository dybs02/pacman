#include "tile.h"

Tile::Tile(int x, int y, tileType type) : QGraphicsRectItem(), x(x), y(y), type(type)
{
    setRect(0, 0, TILE_SIZE, TILE_SIZE);
    setPos(x * TILE_SIZE, y * TILE_SIZE);

    if(type == wall) {
        item = nullptr;
        setBrush(QBrush(Qt::black));
        setPen(QPen(Qt::blue, 2));
    }
    if(type == boost) {
        item = nullptr;
//        setBrush(QBrush(Qt::red));
        setBrush(QBrush(Qt::black));
        setPen(QPen(Qt::red, 2));
    }
    if(type == coin) {
        item = nullptr;
//        setBrush(QBrush(Qt::yellow));
        setBrush(QBrush(Qt::black));
        setPen(QPen(Qt::yellow, 2));
    }
}

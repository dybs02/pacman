#include "game.h"

Game::Game() : QGraphicsView()
{
    // Scene methods
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    // View methods
    setScene(scene);
    setSceneRect(0, 0, WIDTH*TILE_SIZE, HEIGHT*TILE_SIZE);
    setFixedSize(WIDTH*TILE_SIZE, HEIGHT*TILE_SIZE);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameStyle(QFrame::NoFrame);

    // Tiles
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            scene->addItem(new Tile(x, y, (tileType)tiles[y][x]));
        }
    }
}

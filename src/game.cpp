#include "game.h"
#include <QDebug>

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
            Tile* tile = new Tile(x, y, (tileType)tiles[y][x]);

            tileMap[x][y] = tile;
            scene->addItem(tile);
        }
    }

    // Pacman
    pacman = new Pacman(tileMap);
    pacman->setFocus();
    pacman->setPos((WIDTH/2)*TILE_SIZE, (HEIGHT/2)*TILE_SIZE);
    scene->addItem(pacman);

    // Timer
    connect(&timer, &QTimer::timeout, this, &Game::loop);
    timer.start(1000/4);
}

Game::~Game()
{
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            delete tileMap[x][y];
        }
    }

    delete pacman;
}

Tile* Game::tileAtIndex(QPoint indexes)
{
    return tileMap[indexes.x()][indexes.y()];
}

void Game::loop()
{
    pacman->move();
}


























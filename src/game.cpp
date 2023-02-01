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
    tileMap = new TileMap();
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            Tile* tile = new Tile(x, y, (tileType)tiles[y][x]);
            scene->addItem(tileMap->setTile(x, y, tile));
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

    blinky = new Blinky(tileMap);

    scene->addItem(blinky);
}

Game::~Game()
{
    delete tileMap;
    delete pacman;
}

void Game::loop()
{
    blinky->setTargetTile(pacman->tileX, pacman->tileY);

    pacman->move();
    blinky->move();
}


























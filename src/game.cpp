#include "game.h"
#include <QDebug>

Game::Game() : QGraphicsView()
{
    // Variables
    score = 0;
    remainingCoins = 0;

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
            tileType type = (tileType)tiles[y][x];
            Tile* tile = new Tile(x, y, type);
            scene->addItem(tileMap->setTile(x, y, tile));

            if (type == coin) {
                remainingCoins++;
            }
        }
    }

    // Score Text
    int id = QFontDatabase::addApplicationFont(PATH_TO_FONT);
    QFont font = QFont(QFontDatabase::applicationFontFamilies(id).at(0), 22, 0);
    scoreText = new QGraphicsSimpleTextItem();
    scoreText->setBrush(QBrush(Qt::white));
    scoreText->setPen(QPen(Qt::white));
    scoreText->setPos(1, 1);
    scoreText->setFont(font);
    scoreText->setText("Score: 0");
    scene->addItem(scoreText);

    // Pacman
    pacman = new Pacman(tileMap);
    pacman->setFocus();
    pacman->setPos((WIDTH/2)*TILE_SIZE, (HEIGHT/2)*TILE_SIZE);
    scene->addItem(pacman);

    // Blinky
    blinky = new Blinky(tileMap);
    scene->addItem(blinky);

    // Pinky
    pinky = new Pinky(tileMap);
    scene->addItem(pinky);

    // Timer
    connect(&timer, &QTimer::timeout, this, &Game::loop);
    timer.start(1000/FPS);
    connect(&ghostModeTimer, &QTimer::timeout, blinky, &Ghost::changeMode);
    connect(&ghostModeTimer, &QTimer::timeout, pinky, &Ghost::changeMode);
    ghostModeTimer.start(MODE_DELAY);
}

Game::~Game()
{
    delete tileMap;
    delete pacman;
    delete blinky;
    delete pinky;
}

void Game::gameOver()
{
    QApplication::quit();
}

void Game::gameWon()
{
    QApplication::quit();
}

void Game::checkCollisions()
{
    if (pacman->collides(blinky)) {
        gameOver();
    }
    if (pacman->collides(pinky)) {
        gameOver();
    }
}

void Game::checkCoins()
{
    Tile* pacmanTile = tileMap->tileAtIndex(pacman->tileX, pacman->tileY);
    if (pacmanTile->type == coin) {
        remainingCoins--;
        score += 100;
        pacmanTile->type = empty;
        pacmanTile->setBrush(QBrush(Qt::black));
        pacmanTile->setPen(QPen(Qt::black, 2));
        scoreText->setText("Score: " + QString::number(score));
    }

    if (remainingCoins == 0) {
        gameWon();
    }
}


void Game::loop()
{
    blinky->setChaseTile(pacman->tileX, pacman->tileY);

    QPoint pinkyTarget = pacman->tileInfront(4);
    pinky->setChaseTile(pinkyTarget.x(), pinkyTarget.y());

    pacman->move();
    blinky->move();
    pinky->move();

    checkCollisions();
    checkCoins();
}


























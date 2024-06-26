#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QApplication>
#include <QFontDatabase>
#include <QGraphicsSimpleTextItem>

#include "definitions.h"
#include "mapdata.h"
#include "tile.h"
#include "tileMap.h"
#include "pacman.h"
#include "ghost.h"
#include "blinky.h"
#include "pinky.h"
#include "inky.h"
#include "clyde.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    QGraphicsScene * scene;

    Game();
    ~Game();
    void checkCollisions();
    void checkCoins();

private:
    TileMap* tileMap;
    Pacman* pacman;
    QTimer timer;
    QTimer ghostModeTimer;
    Ghost* ghosts[4];
    Ghost* blinky;
    Ghost* pinky;
    Ghost* inky;
    Ghost* clyde;
    int remainingCoins;
    int score;
    QGraphicsSimpleTextItem* scoreText;

    void gameOver();
    void gameWon();

private slots:
    void loop();
};

#endif // GAME_H

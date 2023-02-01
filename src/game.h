#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "definitions.h"
#include "mapdata.h"
#include "tile.h"
#include "tileMap.h"
#include "pacman.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    QGraphicsScene * scene;

    Game();
    ~Game();

private:
    TileMap* tileMap;
    Pacman* pacman;
    QTimer timer;

private slots:
    void loop();
};

#endif // GAME_H

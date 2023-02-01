#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

#include "definitions.h"
#include "mapdata.h"
#include "tile.h"
#include "pacman.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    QGraphicsScene * scene;

    Game();
    ~Game();

private:
    Tile* tileMap[WIDTH][HEIGHT];
    Pacman* pacman;
    QTimer timer;

    Tile* tileAtIndex(QPoint indexes);

private slots:
    void loop();
};

#endif // GAME_H

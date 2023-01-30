#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "definitions.h"
#include "tile.h"
#include "mapdata.h"

class Game : public QGraphicsView
{
public:
    QGraphicsScene * scene;

    Game();
};

#endif // GAME_H

#ifndef GHOST_H
#define GHOST_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include "definitions.h"
#include "entity.h"

class Ghost : public QObject, public QGraphicsPixmapItem, public Entity
{
    Q_OBJECT
public:
    Ghost(int tileX, int tileY, TileMap* tileMap);

    void setTargetTile(int tileX, int tileY);
    void move() override;
    QPoint nextTile() override;

private:
    int targetX;
    int targetY;
};

#endif // GHOST_H

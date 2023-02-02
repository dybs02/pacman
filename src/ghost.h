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

    void setChaseTile(int tileX, int tileY);
    void move() override;
    QPoint nextTile() override;
    void setModeChase();
    void setModeScatter();

private:
    int targetX;
    int targetY;
    int chaseX;
    int chaseY;
    int scatterX;
    int scatterY;
    ghostMode mode;

public slots:
    void changeMode();
};

#endif // GHOST_H

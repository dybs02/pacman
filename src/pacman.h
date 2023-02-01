#ifndef PACMAN_H
#define PACMAN_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include "definitions.h"
#include "entity.h"

class Pacman : public QObject, public QGraphicsPixmapItem, public Entity
{
    Q_OBJECT
public:
    Pacman(Tile* (&tileMap)[WIDTH][HEIGHT]);
    void move();
    void changeDirection();
    QPoint nextDirectionTile();

private:
    QPixmap leftPixmap;
    direction nextDirection;

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // PACMAN_H

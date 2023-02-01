#include "pacman.h"
#include <QDebug>

Pacman::Pacman(TileMap* tileMap)
    : QGraphicsPixmapItem(), Entity(13, 26, tileMap)
{
    leftPixmap = objectsPixmap.copy(210, 0, OBJECT_SIZE, OBJECT_SIZE).scaled(TILE_SIZE, TILE_SIZE);
    setPixmap(leftPixmap);

    setFlag(QGraphicsItem::ItemIsFocusable);

    currnetDirection = LEFT;
    nextDirection = NONE;
}

void Pacman::move()
{
    if (tileMap->tileAtIndex(nextDirectionTile())->type != wall) {
        changeDirection();
    }

    if (tileMap->tileAtIndex(nextTile())->type != wall) {
        Entity::moveTo(nextTile().x(), nextTile().y());
        setPos(posX, posY);
    }
}

QPoint Pacman::nextTile()
{
    switch (currnetDirection) {
    case UP:
        return QPoint(tileX, tileY-1);
    case DOWN:
        return QPoint(tileX, tileY+1);
    case LEFT:
        return QPoint(tileX-1, tileY);
    case RIGHT:
        return QPoint(tileX+1, tileY);
    case NONE:
        return QPoint(tileX, tileY);
    }
}

void Pacman::changeDirection()
{
    currnetDirection = nextDirection;
    nextDirection = NONE;
}

QPoint Pacman::nextDirectionTile()
{
    switch (nextDirection) {
    case UP:
        return QPoint(tileX, tileY-1);
    case DOWN:
        return QPoint(tileX, tileY+1);
    case LEFT:
        return QPoint(tileX-1, tileY);
    case RIGHT:
        return QPoint(tileX+1, tileY);
    case NONE:
        return QPoint(3, 3); // wall index
    }
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "key event";

    switch (event->key()) {
    case Qt::Key_Up:
        nextDirection = UP;
        break;
    case Qt::Key_Down:
        nextDirection = DOWN;
        break;
    case Qt::Key_Left:
        nextDirection = LEFT;
        break;
    case Qt::Key_Right:
        nextDirection = RIGHT;
        break;
    }

    QGraphicsPixmapItem::keyPressEvent(event);
}

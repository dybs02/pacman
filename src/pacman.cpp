#include "pacman.h"
#include <QDebug>

Pacman::Pacman(Tile* (&tileMap)[WIDTH][HEIGHT])
    : QGraphicsPixmapItem(), Entity(13, 26, tileMap)
{
    leftPixmap = objectsPixmap.copy(180, 0, TILE_SIZE, TILE_SIZE);
    setPixmap(leftPixmap);

    setFlag(QGraphicsItem::ItemIsFocusable);

    currnetDirection = LEFT;
    nextDirection = NONE;
}

void Pacman::move()
{
    if (tileAtIndex(nextDirectionTile())->type != wall) {
        changeDirection();
    }

    if (tileAtIndex(nextTile())->type != wall) {
        Entity::moveTo(nextTile().x(), nextTile().y());
        setPos(posX, posY);
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

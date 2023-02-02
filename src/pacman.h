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
    Pacman(TileMap* tileMap);
    void move() override;
    QPoint nextTile() override;
    void changeDirection();
    QPoint nextDirectionTile();
    QPoint tileInfront(int n);

private:
    QPixmap leftPixmap;
    direction nextDirection;

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};

#endif // PACMAN_H

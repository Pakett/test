#include "platform.h"
#include <QDebug>

Platform::Platform(qreal x, qreal y, int idx)
{
    setPixmap(QPixmap(":/imgs/platfrom.png"));
    setPos(x, y);
    current_speed.x = 0;
    current_speed.y = -5;
    this->idx = idx;
}

void Platform::collided()
{
    current_speed.y = 20;
}

float Platform::getCurrentSpeedY()
{
    return current_speed.y;
}

void Platform::setNewIdx(int idx)
{
    this->idx = idx;
}

void Platform::update()
{
    setPos(x(), y() + current_speed.y);
    if (current_speed.y > -10)
    {
        current_speed.y -= 1;
    }

    if(pos().y() > 600)
    {
        emit(should_be_destoryed(idx));
    }

}


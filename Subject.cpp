#include "Subject.h"

size_t SubjectLabyrinth::posX() const
{
    return m_posX;
}

size_t SubjectLabyrinth::posY() const
{
    return m_posY;
}

void SubjectLabyrinth::setRoute(const std::queue<Movement> &route)
{

}

void SubjectLabyrinth::setVisibleArea(const VisibleArea &area)
{
  m_visibleArea = area;
}

void SubjectLabyrinth::setX(size_t x)
{
  m_posX = x;
}

void SubjectLabyrinth::setY(size_t y)
{
  m_posY = y;
}


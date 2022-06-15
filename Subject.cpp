#include "Subject.h"

size_t SubjectLabyrinth::posX() const
{
    return m_posX;
}

size_t SubjectLabyrinth::posY() const
{
    return m_posY;
}

void SubjectLabyrinth::setRoute(const std::queue<Movement> &route) // установка маршрута
{
 m_route = route;
}

void SubjectLabyrinth::setMoveOptions(const MoveOptions &moveOptions) //установка возможных ходов
{
  m_moveOptions = moveOptions;
}

void SubjectLabyrinth::setX(size_t x)
{
  m_posX = x;
}

void SubjectLabyrinth::setY(size_t y)
{
  m_posY = y;
}


int MoveOptions::numberPaths() const // подсчитать кол-во возможных ходов
{
  int result = 0;

  if(up)
    result++;
  if(down)
    result++;
  if(right)
    result++;
  if(left)
    result++;


  return result;
}

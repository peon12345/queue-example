#include "mouse.h"
#include <iostream>

bool Mouse::move() // перемещение по лабиринту
{
  if(m_route.empty()){ //если очередь маршрутов пуста, возвращаем 0
      return false;
    }

  if(m_moveOptions.numberPaths() >= 3){ //если появился новый путь движения
      m_route.pop();                    //чтобы узнать в какую сторону идти
    }                                   //переходим к следующему элементу в очереди

  while (!m_route.empty()) {

      Movement directionMovement = m_route.front(); // получаем направление движения

      switch (directionMovement) {                 //в зависимости от направления движения

        case Movement::DOWN:                       //меняем позицию у объекта
          if(m_moveOptions.down){
              m_posY++;
              return true;
            }
          break;

        case Movement::UP:
          if(m_moveOptions.up){
              m_posY--;
              return true;
            }
          break;
        case Movement::RIGHT:
          if(m_moveOptions.right){
              m_posX++;
              return true;
            }
          break;
        case Movement::LEFT:
          if(m_moveOptions.left){
              m_posX--;
              return true;
            }
          break;
        }

      m_route.pop(); // возможных ходов нет, переходим к следующему элементу
    }

  return false;
}

char Mouse::getSym() const // возвращаем символ, как рисовать объект на экране
{
  return MOUSE_SYM;
}


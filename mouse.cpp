#include "mouse.h"

Mouse::Mouse()
{

}

bool Mouse::move()
{
  if(!m_route.empty()){
  return false;
  }


  Movement directionMovement = m_route.front();

  switch (directionMovement) {

  case Movement::UP:
      if(m_visibleArea.up){
       m_posX += m_visibleArea.up;
       return true;
      }
      break;
  case Movement::DOWN:
      break;
  case Movement::RIGHT:
      break;
  case Movement::LEFT:
      break;


  }

}


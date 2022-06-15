#include "mouse.h"


bool Mouse::move()
{
  if(!m_route.empty()){
  return false;
  }


  Movement directionMovement = m_route.front();

  switch (directionMovement) {

  case Movement::UP:
      if(m_visibleArea.up){

       m_visibleArea.up--;
       m_posX++;
       return true;
      }
      break;

  case Movement::DOWN:
      if(m_visibleArea.down){
      m_visibleArea.down--;
      m_posX++;

      return true;
      }
      break;
  case Movement::RIGHT:
      if(m_visibleArea.right){
      m_visibleArea.right--;
      m_posX++;
      return true;
        }
      break;
  case Movement::LEFT:
      if(m_visibleArea.left){
      m_visibleArea.left--;
      m_posX++;
      return true;
      }
      break;
  }

  return false;
}

char Mouse::getSym() const
{
 return MOUSE_SYM;
}


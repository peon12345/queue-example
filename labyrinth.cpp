#include "labyrinth.h"
#include <queue>
#include <functional>
#include <algorithm>
#include <stdlib.h>

Labyrinth::Labyrinth()
{
  initWalls();
}

bool Labyrinth::startTest(SubjectLabyrinth& subject)
{
  subject.setX(startX);
  subject.setY(startY);

  show(&subject);

  while(subject.move()){
      subject.setVisibleArea(visibleArea(subject.posX(),subject.posY()));
      show(&subject);
    }

  // поз меняется
  // лабиринт смотрит
  // лабиринт говорит давай другой моемент
}

void Labyrinth::show(const SubjectLabyrinth* subject)
{

  system ("CLS");
  for(size_t i = 0 ; i < m_walls.size(); ++i){

      if(subject){
      if(subject->posY() == i)
        std::replace(m_walls.at(i).begin()+subject->posX(),m_walls.at(i).begin()+subject->posX() + 1, ' ' , subject->getSym() );
        }

      std::cout << m_walls.at(i);
      std::cout << std::endl;

    }

}

void Labyrinth::initWalls()
{
  startX = 3;
  startY = 0;

  addWall(3,3);
  addWall(3,3);
  addWall(3,3);
  addWall(3,3);
  addWall(3,3);
  addWall(3,45);
  addWall(25,3);
  addWall(25,3);
  addWall(25,3);
  addWall(25,3);
  addWall(3,25);
  addWall(3,3);
  addWall(3,3);
  addWall(3,3);
  addWall(3,3);
  addWall(3,3);
  addWall(3,35);
  addWall(35,3);
  addWall(35,3);

  finishX = 35;
  finishY = 18;

  setTrap(43,5);

}

void Labyrinth::addWall(int posHole, int lenghtHole)
{
  static std::string wall(WALL_LENGHT,WALL_SYM);

  std::replace(wall.begin()+posHole, wall.begin()+posHole+lenghtHole, '#', ' ');
  m_walls.push_back(wall);
  std::replace(wall.begin()+posHole, wall.begin()+posHole+lenghtHole, ' ', '#');
}

bool Labyrinth::isValidPos(size_t x, size_t y)
{
  return ((x > 0 && y > 0 )  &&
          (x < m_walls.size() && y < WALL_LENGHT ));

}

VisibleArea Labyrinth::visibleArea(size_t x, size_t y)
{

  isValidPos(x,y);

  size_t visibleUp = 0;
  size_t visibleDown = 0;

  bool visibleUpCount = true;
  bool visibleDownCount = true;

  for(size_t i = 0; i < m_walls.size(); ++i){

      if(visibleUpCount){
          if(m_walls.size() > (y + visibleUp +1)){
              std::string line = m_walls.at(y+ visibleUp + 1 );
              if(line.at(x) == ' '){
                  visibleUp++;
                }else{
                  visibleUpCount = false;
                }
            }
        }

      if(visibleDownCount){
          if(0 >= (y - visibleDown -1)){
              std::string line = m_walls.at(y - visibleDown - 1 );
              if(line.at(x) == ' '){
                  visibleDown++;
                }else{
                  visibleDownCount = false;
                }
            }
        }

    }

  size_t visibleRight = 0;
  size_t visibleLeft = 0;

  std::string line = m_walls.at(y);
  if(x < line.length() ) {


      for(size_t i = x-1; i >= 0 ; --i){

          if(line.at(i) == ' '){
              visibleLeft++;
            }else{
              break;
            }
        }
    }


  for(size_t i = x+1; i < line.length() ; ++i){

      if(line.at(i) == ' '){
          visibleRight++;
        }else{
          break;
        }
    }


  return VisibleArea{visibleUp,visibleDown,visibleRight,visibleLeft};

}

void Labyrinth::setTrap(size_t x, size_t y)
{
  if(y < m_walls.size() && x < WALL_LENGHT){
     std::replace( m_walls.at(y).begin()+x , m_walls.at(y).begin()+x+1, ' ', '&');
    }
}







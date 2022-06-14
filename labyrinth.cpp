#include "labyrinth.h"
#include <queue>


Labyrinth::Labyrinth()
{
  initWalls();
}

bool Labyrinth::startTest(SubjectLabyrinth& subject)
{
  while(subject.move()){
      subject.setVisibleArea(visibleArea(subject.posX(),subject.posY()));
    }



  // поз меняется
  // лабиринт смотрит
  // лабиринт говорит давай другой моемент
}

void Labyrinth::initWalls()
{
  std::string wall(WALL_LENGHT,WALL_SYM);

  m_walls.push_back(wall.replace(3,1," "));
  m_walls.push_back(wall.replace(3,4," "));
  m_walls.push_back(wall.replace(3,1," "));
  m_walls.push_back(wall.replace(3,7," "));
  m_walls.push_back(wall.replace(7,2," "));
  m_walls.push_back(wall.replace(9,1," "));
}

VisibleArea Labyrinth::visibleArea(int x, int y)
{
  int visibleUp = 0;
  int visibleDown = 0;
  int visibleRight = 0;
  int visibleLeft = 0;

  for(size_t i = 0; i < m_walls.size(); ++i){

      std::string line = m_walls.at(y+1);

      if(line.at(x) == ' '){
          visibleUp++;
        }



    }

}







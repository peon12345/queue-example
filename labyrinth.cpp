#include "labyrinth.h"
#include <queue>


Labyrinth::Labyrinth()
{
    initWalls();
}

bool Labyrinth::startTest(SubjectLabyrinth& subject)
{
  while(subject.move()){
  subject.setVisibleArea();

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

  std::string line = m_walls.at(y+1);
  if(line.at(x) == ' '){

  }

}







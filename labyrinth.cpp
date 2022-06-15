#include "labyrinth.h"
#include <queue>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <windows.h>

Labyrinth::Labyrinth() : oldPosSubjectX(0), oldPosSubjectY(0)
{
  initWalls();       //строим стены лабиринта
  setTrap(43,5);     //рисуем ловушку
}

void Labyrinth::start(SubjectLabyrinth& subject)
{
  subject.setX(startX); //устанавливаем в стартовую позицию объект
  subject.setY(startY);

  do{
      show(&subject); //рисуем объект с лабиринтом на экране
      subject.setMoveOptions(getMoveOptions(subject.posX(),subject.posY())); // передаем возможные ходы в лабиринте
                                                                             // исходя из текущей позиции объекта
      Sleep(500);                                                            // ждем пол секунды, для наглядности отображения перемещения

    }while(subject.move());                                                 // перемещаем объект, пока объект не вернет статус ошибки

}

void Labyrinth::show(const SubjectLabyrinth* subject)
{
  system ("CLS");
  for(size_t i = 0 ; i < m_walls.size(); ++i){

      if(subject){


          //очистка объекта с экрана, чтобы нарисовать его в новой позиции
          if(  oldPosSubjectX || oldPosSubjectY ){
             std::replace(m_walls.at(oldPosSubjectY).begin()+oldPosSubjectX,m_walls.at(oldPosSubjectY).begin()+oldPosSubjectX + 1, subject->getSym() , ' ' );
            }

          //рисуем объект в лабиринте и сохраняем его позицию
          //чтобы удалить его при следующем перемещении объекта
          if(subject->posY() == i){

            oldPosSubjectX = subject->posX();
            oldPosSubjectY = subject->posY();

            std::replace(m_walls.at(i).begin()+subject->posX(),m_walls.at(i).begin()+subject->posX() + 1, ' ' , subject->getSym() );
            }
        }

      std::cout << m_walls.at(i); //рисуем стену лабиринта
      std::cout << std::endl;

    }

}

void Labyrinth::initWalls() //строим стены и запоминаем позиции старта и финиша
{
  startX = 3;
  startY = 0;

  addWall(3,1);
  addWall(3,1);
  addWall(3,1);
  addWall(3,1);
  addWall(3,1);
  addWall(3,45);
  addWall(25,1);
  addWall(25,1);
  addWall(25,1);
  addWall(25,1);
  addWall(3,23);
  addWall(3,1);
  addWall(3,1);
  addWall(3,1);
  addWall(3,1);
  addWall(3,1);
  addWall(3,33);
  addWall(35,1);
  addWall(35,1);

  finishX = 35;
  finishY = 18;

}

void Labyrinth::addWall(int posHole, int lenghtHole) //добавление стены
{
  static std::string wall(WALL_LENGHT,WALL_SYM);

  std::replace(wall.begin()+posHole, wall.begin()+posHole+lenghtHole, '#', ' ');
  m_walls.push_back(wall);
  std::replace(wall.begin()+posHole, wall.begin()+posHole+lenghtHole, ' ', '#');
}

bool Labyrinth::isValidPos(size_t x, size_t y) //проверка на корректность позиции объекта
{
  return (x < m_walls.size() && y < WALL_LENGHT  );


}

MoveOptions Labyrinth::getMoveOptions(int x, int y) // получаем возможные ходы в лабиринте
{                                                   // исходя из позиции в лабиринте

  isValidPos(x,y);

  bool up;
  bool down;
  bool right;
  bool left;

  if(y+1 < m_walls.size()){
      if( m_walls.at(y+1).at(x) == ' ')
        down = true;
      else
        down = false;
    }else{
      down = false;
    }


  if(y - 1 >= 0) {
      if( m_walls.at(y-1).at(x) == ' ')
        up = true;
      else
        up = false;
    }else{
      up = false;
    }

  if( WALL_LENGHT > x + 1 ){

      if(m_walls.at(y).at(x+1) == ' ')
        right = true;
      else
        right = false;
    }else{
      right = false;
    }

  if(x -1 >= 0){
      if(m_walls.at(y).at(x-1) == ' ')
        left = true;
      else
        left = false;

    }else{
      left = false;
    }

  return MoveOptions{up,down,right,left};
}



void Labyrinth::setTrap(size_t x, size_t y) //рисуем ловушку в лабиринте
{
  if(y < m_walls.size() && x < WALL_LENGHT){
      std::replace( m_walls.at(y).begin()+x , m_walls.at(y).begin()+x+1, ' ', '&');
    }
}







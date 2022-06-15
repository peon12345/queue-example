#include <QCoreApplication>

#include "labyrinth.h"
#include "mouse.h"
#include <queue>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Labyrinth labyrinth;
  Mouse mouse;

  labyrinth.show();

  std::cout << "Enter rout" << std::endl;
  std::cout << "u - up" << std::endl;
  std::cout << "d - down" << std::endl;
  std::cout << "r - right" << std::endl;
  std::cout << "l - left" << std::endl;
  std::cout << "If the mouse encounters a dead end, it will stop!"  << std::endl;
  std::cout << "Example: drd " << "The mouse moves down, then left, then down."  << std::endl;


  std::string command;
  std::cin >> command; // Пользователь вводит маршрут

  //Заполняется очередь из заданного маршрута.
  std::queue<Movement> route;
  Movement b = route.front();

  for(size_t i = 0; i < command.length(); ++i){

      switch (command.at(i)) {

        case 'u':
          route.push(Movement::UP);
          break;
        case 'd':
          route.push(Movement::DOWN);
          break;
        case 'r':
          route.push(Movement::RIGHT);
          break;
        case 'l':
          route.push(Movement::LEFT);
          break;
        }
    }

  //проверка на пустую очередь
  if(!route.empty()){
      mouse.setRoute(route);
      labyrinth.start(mouse);
    }

  return a.exec();
}

//Правильный маршрут
//    route.push(Movement::DOWN);
//    route.push(Movement::RIGHT);
//    route.push(Movement::DOWN);
//    route.push(Movement::LEFT);
//    route.push(Movement::DOWN);
//    route.push(Movement::RIGHT);
//    route.push(Movement::DOWN);

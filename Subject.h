#ifndef ISUBJECT_H
#define ISUBJECT_H

#include <queue>
enum class Movement { // направление движения
  UP,
  DOWN,
  RIGHT,
  LEFT
};

struct MoveOptions{ // возможные ходы в лабиринте
  bool up;
  bool down;
  bool right;
  bool left;

  int numberPaths() const; // кол-во возможных ходов
};

class SubjectLabyrinth {
public:
  virtual bool move() = 0; // как передвигаться по лабиринту
  virtual char getSym() const = 0; //как рисовать объект в лабиринте

  void setRoute(const std::queue<Movement>& route); // установить маршрут движения
  void setMoveOptions(const MoveOptions& moveOptions); //установить возможные ходы

  void setX(size_t x); //геттеры и сеттеры для позиции в лабиринте
  void setY(size_t y);
  size_t posX() const;
  size_t posY() const;

  virtual ~SubjectLabyrinth() = default;
protected:
  std::queue<Movement> m_route; //маршрут движения
  MoveOptions m_moveOptions; // возможные ходы в лабиринте
  size_t m_posX;
  size_t m_posY; // позиция в лабиринте, y - строка , x - позиция в строке
};

#endif // ISUBJECT_H

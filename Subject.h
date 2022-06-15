#ifndef ISUBJECT_H
#define ISUBJECT_H

#include <queue>
enum class Movement {
  UP,
  DOWN,
  RIGHT,
  LEFT
};

struct VisibleArea{
  size_t up;
  size_t down;
  size_t right;
  size_t left;
};

class SubjectLabyrinth {
public:
  virtual bool move() = 0;
  virtual char getSym() const = 0;

  void setRoute(const std::queue<Movement>& route);
  void setVisibleArea(const VisibleArea& area);
  bool isRun();


  void setX(size_t x);
  void setY(size_t y);
  size_t posX() const;
  size_t posY() const;

  virtual ~SubjectLabyrinth() = default;
protected:
  std::queue<Movement> m_route;
  VisibleArea m_visibleArea;
  size_t m_posX;
  size_t m_posY;
};

#endif // ISUBJECT_H

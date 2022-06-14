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
int up;
int down;
int right;
int left;
};

class SubjectLabyrinth {
public:
 virtual bool move() = 0;

 void setRoute(const std::queue<Movement>& route);
 void setVisibleArea(const VisibleArea& area);
 bool isRun();

 int posX() const;
 int posY() const;

 virtual ~SubjectLabyrinth();
protected:
  std::queue<Movement> m_route;
  VisibleArea m_visibleArea;
  int m_posX;
  int m_posY;
};

#endif // ISUBJECT_H

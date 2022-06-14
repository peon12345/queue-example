#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <vector>
#include <string>
#include "mouse.h"

class Labyrinth {
public:
Labyrinth();
bool startTest(SubjectLabyrinth &subject);
private:
std::vector<std::string> m_walls;

static constexpr int WALL_LENGHT = 10;
static constexpr char WALL_SYM = '#';

private:
void initWalls();
VisibleArea visibleArea(int x,int y);
};

#endif // LABYRINTH_H

#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <vector>
#include <string>
#include "mouse.h"
#include <iostream>

class Labyrinth {
public:
Labyrinth();
bool startTest(SubjectLabyrinth &subject);
void show(const SubjectLabyrinth* subject = nullptr);
private:
std::vector<std::string> m_walls;

static constexpr int WALL_LENGHT = 60;
static const char WALL_SYM = '#';

size_t startX;
size_t startY;

size_t finishX;
size_t finishY;

private:
void initWalls();
void addWall(int posHole , int lenghtHole);
bool isValidPos(size_t x,size_t y);
VisibleArea visibleArea(size_t x, size_t y);
void setTrap(size_t x , size_t y);
};

#endif // LABYRINTH_H

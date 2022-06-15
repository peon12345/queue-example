#ifndef LABYRINTH_H
#define LABYRINTH_H
#include <vector>
#include <string>
#include "mouse.h"
#include <iostream>

class Labyrinth {
public:
Labyrinth();
void start(SubjectLabyrinth &subject); // старт движения в лабиринте
void show(const SubjectLabyrinth* subject = nullptr); // показать лабиринт, если указать объект, рисует его
private:
std::vector<std::string> m_walls; //стены лабиринта

static constexpr int WALL_LENGHT = 60; // длина стен лабиринта
static const char WALL_SYM = '#'; //символ для рисования лабиринта

size_t startX; //позиция начала лабиринта
size_t startY;

size_t finishX; // позиция конца лабиринта
size_t finishY;

size_t oldPosSubjectX; //прошлая позиция мыши
size_t oldPosSubjectY;

private:
void initWalls(); // инициализация лабиринта
void addWall(int posHole , int lenghtHole); // добавление стены лабиринта, с отверстиями
bool isValidPos(size_t x,size_t y); // проверка на корректность позиции
MoveOptions getMoveOptions(int x, int y); //получить возможные ходы из текущей позиции лабиринта
void setTrap(size_t x , size_t y); // нарисовать ловушку
};

#endif // LABYRINTH_H

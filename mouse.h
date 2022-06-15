#ifndef MOUSE_H
#define MOUSE_H
#include "Subject.h"

class Mouse : public SubjectLabyrinth
{
public:
    Mouse() = default;
    ~Mouse() = default;
    bool move() override; // переопределенная функция передвижения по лабиринту
    char getSym() const override; //символ как рисовать мышь

private:
   static constexpr char MOUSE_SYM = 'M'; // сам символ рисования
};

#endif // MOUSE_H

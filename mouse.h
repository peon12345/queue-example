#ifndef MOUSE_H
#define MOUSE_H
#include "Subject.h"

class Mouse : public SubjectLabyrinth
{
public:
    Mouse();
    bool move() override;

private:
   static constexpr char MOUSE_SYM = 'M';
};

#endif // MOUSE_H

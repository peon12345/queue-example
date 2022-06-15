#ifndef MOUSE_H
#define MOUSE_H
#include "Subject.h"

class Mouse : public SubjectLabyrinth
{
public:
    Mouse() = default;
    ~Mouse() = default;
    bool move() override;
    char getSym() const override;

private:
   static constexpr char MOUSE_SYM = 'M';
};

#endif // MOUSE_H

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

    std::queue<Movement> route;
    route.push(Movement::UP);
    route.push(Movement::RIGHT);
    route.push(Movement::DOWN);
    route.push(Movement::LEFT);
    route.push(Movement::DOWN);
    route.push(Movement::RIGHT);
    route.push(Movement::DOWN);


    return a.exec();
}

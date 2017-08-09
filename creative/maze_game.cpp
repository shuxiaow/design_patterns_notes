#include "maze_game.h"

using namespace mymaze;

Maze* MazeGame::createMaze()
{
    Maze* pMaze = new Maze();
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* d = new Door(r1, r2);

    pMaze->addRoom(r1);
    pMaze->addRoom(r2);

    r1->setSide(North, new Wall());
    r1->setSide(South, d);
    r1->setSide(East, new Wall());
    r1->setSide(West, new Wall());
    r2->setSide(North, new Wall());
    r2->setSide(South, new Wall());
    r2->setSide(East, new Wall());
    r2->setSide(West, d);

    return pMaze;
}

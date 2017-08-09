#pragma once

#include <map>

namespace mymaze {

enum Direction { North, South, East, West };

class MapSite {
public:
    virtual void Enter() = 0;
};

class Room : public MapSite {
public:
    Room(int roomNo);
    MapSite* getSide(Direction drct) const;
    void setSide(Direction drct, MapSite* site);

    virtual void Enter();

private:
    MapSite* m_sides[4];
    int m_roomNo;
};

class Wall : public MapSite {
public:
    Wall();

    virtual void Enter();
};

class Door : public MapSite {
public:
    Door(Room* r1 = NULL, Room* r2 = NULL);

    virtual void Enter();
    Room* getOtherSideRoom(Room* r);

private:
    Room* m_room1;
    Room* m_room2;
    bool m_bOpen;
};

class Maze {
public:
    Maze();

    void addRoom(Room* r);
    Room* getRoom(int roomNo) const;

private:
    std::map<int,Room*> m_rooms;
};

}

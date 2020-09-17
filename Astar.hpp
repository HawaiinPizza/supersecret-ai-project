#ifndef ASTAR
#define ASTAR
#include "Head.hpp"
#include <iostream>

struct point{
     int x; int y;
     point();
     point(int x, int y);
     bool operator==(const point& rhs);
     bool operator!=(const point& rhs);
     point operator+(const point& rhs);
     point operator+=(const point& rhs);
     point operator-(const point& rhs);
     point operator-=(const point& rhs);
     friend std::ostream &operator<<(std::ostream &os, const point& p);
};
extern point _end_pos;
extern point _start_pos;

int dist(point start, point end=_end_pos);
int dist(std::pair<int,int> start, std::pair<int,int> end=end_pos);

struct node{
     point pos;
     int past;
     int pred;
     int path;
     
     node(point _pos, dir _dir, int _label);
     node(point _pos);

     friend std::ostream &operator<<(std::ostream &os, const node& n);

     bool operator==(const node& rhs);
     bool operator!=(const node& rhs);
     bool operator<(const node& rhs);
     bool operator>(const node& rhs);
     
};

#endif

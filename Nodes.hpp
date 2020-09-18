#ifndef NODES
#define NODES
#include "Head.hpp"
#include <iostream>


struct point {
    int x;
    int y;
    point();
    point(int x, int y);
    bool operator==(const point &rhs) const;
    bool operator!=(const point &rhs) const;
    point operator+(const point &rhs) const;
    point operator+=(const point &rhs);
    point operator-(const point &rhs) const;
    point operator-=(const point &rhs);
    friend std::ostream &operator<<(std::ostream &os, const point &p);
};
extern point _end_pos;
extern point _start_pos;
extern int label;

int dist(point start, point end = _end_pos);
int dir_dist(dir _dir);

struct node {
    point pos;
    int past;
    int pred;
    int path;
    point past_pos;
    int label;
    dir par_dir;
    const node *par;

    node();
    node(point _pos, const node *par_node, dir _dir, int _label);
    node(point _pos);


    friend std::ostream &operator<<(std::ostream &os, const node &n);

    bool operator==(const node &rhs);
    bool operator!=(const node &rhs);
    bool operator>(const node &rhs);
    bool operator<(const node &rhs);
};
typedef std::vector<node> vect;
grid getTile(int x, int y);

#endif

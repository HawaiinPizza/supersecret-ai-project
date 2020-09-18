#include "Nodes.hpp"
#include <algorithm>
#include <climits>
#include <cmath>
#include <stdexcept>
// Global variable. Increases all the bloddy time
// NOTE May need to change
int label = 1;

point::point() {
    x = 0;
    y = 0;
}
point::point(int _x, int _y) {
    x = _x;
    y = _y;
}
bool point::operator==(const point &rhs) const {
    return (this->x == rhs.x && this->y == rhs.y);
}
bool point::operator!=(const point &rhs) const {
    return (this->x != rhs.x || this->y != rhs.y);
}
point point::operator+(const point &rhs) const {
    point tmp(rhs.x + this->x, rhs.y + this->y);
    return tmp;
}
point point::operator+=(const point &rhs) {
    point tmp(rhs.x + this->x, rhs.y + this->y);
    this->x = tmp.x;
    this->y = tmp.y;
    return *this;
    ;
}
point point::operator-(const point &rhs) const {
    point tmp(rhs.x - this->x, rhs.y - this->y);
    return tmp;
}
point point::operator-=(const point &rhs) {
    point tmp(rhs.x - this->x, rhs.y - this->y);
    this->x = tmp.x;
    this->y = tmp.y;
    return *this;
    ;
}
point _end_pos(2, 2);
point _start_pos(3, 0);
std::ostream &operator<<(std::ostream &os, const point &p) {
    os << p.x << ':' << p.y;
    return os;
}
int dist(point start, point end) {
    point tmp = end - start;
    // north movement
    if (tmp.x > 0) {
        tmp.x = abs(tmp.x);
        tmp.y = abs(tmp.y);
        return tmp.x * 3 + tmp.y * 2;
    }
    // Southern movement
    else {
        tmp.x = abs(tmp.x);
        tmp.y = abs(tmp.y);
        return tmp.x + tmp.y * 2;
    }
}


int dir_dist(dir _dir) {
    switch (_dir) {
    case LEFT:
        return 2;
        break;
    case RIGHT:
        return 2;
        break;
    case UP:
        return 3;
        break;
    case DOWN:
        return 1;
        break;
    default:
        std::cout << ("Dir is invalid");
        throw("Dir is invalid");
        break;
    };
}


node::node(point _pos, const node *par_node, dir _dir, int _label) {
    pos = _pos;
    past = par_node->past + dir_dist(_dir);
    pred = dist(pos, _end_pos);
    path = past + pred;
    past_pos = par_node->pos;
    label = _label;
    par_dir = _dir;
    par = par_node;
}



node::node(point _pos) {
    pos = _pos;
    past = 0;
    pred = dist(pos, _end_pos);
    path = pred;
    past_pos = _pos;
    label = 0;
    par_dir = NONE;
    par = NULL;
}

node::node() {
    pos = point(0, 0);
    past = 0;
    pred = INT_MAX;
    path = pred;
    past_pos = point(0, 0);
    label = -1;
    par_dir = NONE;
    par = NULL;
}

std::ostream &operator<<(std::ostream &os, const node &n) {
    std::string dir;
    switch (n.par_dir) {
    case LEFT:
        dir = "LEFT";
        break;
    case RIGHT:
        dir = "RIGHT";
        break;
    case UP:
        dir = "UP";
        break;
    case DOWN:
        dir = "DOWN";
        break;
    case NONE:
        dir = "START";
        break;
    };
    os << n.label << "\t-> pos:    " << n.pos << "        path:    " << n.past << '+' << n.pred << '=' << n.path << "     \tpast_pos:    " << n.past_pos << "\tdirection:    " << dir;
    return os;
}

bool node::operator==(const node &rhs) {
    return rhs.pos == this->pos;
}

bool node::operator!=(const node &rhs) {
    return rhs.label != this->label;
}

bool node::operator>(const node &rhs) {
    return rhs.path > this->path;
}
bool node::operator<(const node &rhs) {
    return rhs.path < this->path;
}


grid getTile(int x, int y) {
    if (x < 0 || x >= map.size()) {
        return BLOCK;
    }
    if (y < 0 || y >= map[0].size()) {
        return BLOCK;
    }

    return map[x][y];
}

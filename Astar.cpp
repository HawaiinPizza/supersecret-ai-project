#include "Astar.hpp"
#include <algorithm>
#include <stdlib.h>

vect get_neighers(const node *node) {
    std::vector<struct node> neigherbors;
    point pos = node->pos;
    // LEFT
    if (getTile(pos.x, pos.y - 1) == FREE) {
        struct node tmp(point(pos.x, pos.y - 1), node, LEFT, label++);
        neigherbors.push_back(tmp);
    }

    // UP
    if (getTile(pos.x - 1, pos.y) == FREE) {
        struct node tmp(point(pos.x - 1, pos.y), node, UP, label++);
        neigherbors.push_back(tmp);
    }

    // RIGHT
    if (getTile(pos.x, pos.y + 1) == FREE) {

        struct node tmp(point(pos.x, pos.y + 1), node, RIGHT, label++);
        neigherbors.push_back(tmp);
    }

    // DOWN
    if (getTile(pos.x + 1, pos.y) == FREE) {
        struct node tmp(point(pos.x + 1, pos.y), node, DOWN, label++);
        neigherbors.push_back(tmp);
    }

    return neigherbors;
}


// For each neighering node, check it in the epxlore set
vect should_check(vect neighs, vect explore) {
    vect sol;
    // NOTE This assumes node's equilvent oeprators compare label,
    // And it's greater then/less than compare path
    // NOTE if this hcanges it will not work.
    // NOTE Zaki i'm looking at you you freaking degerante
    for (node tmp : neighs) {
        auto it = find(explore.begin(), explore.end(), tmp);
        // tmp is in explroe set
        if (it != explore.end()) {
            // tmp is less then it
            if (*it < tmp) {
                sol.push_back(tmp);
            }
        } else {
            sol.push_back(tmp);
        }
    }
    return sol;
}
vect get_path(const node *start, const point *end) {
    vect sol;
    const node *tmp = start;
    while (tmp->pos != *end || tmp == NULL) {
        sol.push_back(*tmp);
        if (tmp->par == NULL) {
            std::cout << ("Path wasn't found, even though it should. OOPS");
            throw("Path wasn't found, even though it should. OOPS");
        }
        tmp = tmp->par;
    }
    sol.push_back(*tmp);
    return sol;
}


vect astar(const node *start, const point end) {
    vect sol;
    frontQueue front;
    front.push(*start);
    vect explore;
    while (!front.empty()) {
        node *cur = new node;
        *cur = front.top();
        front.pop();
        explore.push_back(*cur);
        if (cur->pos == end) {
            // return sol;
            // for(auto tmp: explore){
            // 	    std::cout << tmp << std::endl;
            // }
            return get_path(cur, &start->pos);
        }
        vect neighers = get_neighers(cur);
        vect check_these = should_check(neighers, explore);
        for (auto n : check_these) {
            front.push(n);
        }
    }
    std::cout << ("God damn it it didn't get a path");
    throw("God damn it it didn't get a path");
}

#ifndef IDS
#define IDS
#include <iostream>
#include <string>

enum grid_IDS {
    FREE,
    BLOCK,
    START,
    GOAL
};

struct node_IDS {
    std::string number = "  ";
    bool isVisited = false;
    grid_IDS status = FREE;
};

node_IDS nodeGrid[6][5];

#endif
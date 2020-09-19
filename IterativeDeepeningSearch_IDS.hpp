#ifndef IDS
#define IDS
#include <iostream>
#include <string>

enum grid_IDS {
    FRE,
    NOTFRE,
    BLOK,
    STRT,
    GOL
};

struct node_IDS {
    std::string number = "  ";
    bool isVisited = false;
    grid_IDS status = grid_IDS::FRE;
};

void setMap(node_IDS nodeGrid[6][5]);
void itterativeDFS();
void printMap(node_IDS nodeGrid[6][5]);

#endif
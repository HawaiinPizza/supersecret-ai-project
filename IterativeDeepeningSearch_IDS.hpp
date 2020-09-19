#ifndef IDS
#define IDS
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

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

int exploredNumber = 0;

std::stack<node_IDS> frontierSet;
std::unordered_map<node_IDS, std::string> exploredSet;

void setMap(node_IDS nodeGrid[6][5]);
void iterativeDeepeningDFS(node_IDS nodeGrid[6][5]);
void depthFirstSearch();
void printMap(node_IDS nodeGrid[6][5]);

#endif
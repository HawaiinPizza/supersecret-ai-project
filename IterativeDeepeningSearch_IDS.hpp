#ifndef IDS
#define IDS
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>

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
    std::pair<int, int> position;
    grid_IDS status = grid_IDS::FRE;
};

node_IDS nodeGrid[6][5];

int exploredNumber;

std::stack<node_IDS> frontierSet;
std::unordered_map<std::string, node_IDS> exploredSet;

void setMap();
void iterativeDeepeningDFS();
void depthFirstSearch();
void printMap();

#endif
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

extern int exploredNumber;

extern std::stack<node_IDS> frontierSet;
extern std::unordered_map<std::pair<int, int>, std::string> exploredSet;

void setMap(node_IDS nodeGrid[6][5]);
void iterativeDeepeningDFS(node_IDS nodeGrid[6][5]);
void depthFirstSearch();
void printMap(node_IDS nodeGrid[6][5]);

#endif
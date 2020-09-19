#ifndef IDS
#define IDS
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>

const short MAP_WIDTH = 5;
const short MAP_HEIGHT = 6;

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

node_IDS nodeIDSGrid[6][5];

// Current number to increment and assign to the
// number of a node_IDS
int exploredNodeNumber;

std::stack<node_IDS> frontierNodeSet;
std::unordered_map<std::string, node_IDS> exploredNodeSet;

void setMap();
void iterativeDeepeningDFS();
void depthFirstSearch();
void printMap();

grid_IDS getNodeStatus(int x, int y);

#endif
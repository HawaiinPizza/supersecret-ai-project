#ifndef IDS
#define IDS
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

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

node_IDS nodeGrid[MAP_HEIGHT][MAP_WIDTH];

// Current number to increment and assign to the
// number of a node_IDS
int exploredNumber;

std::stack<node_IDS> frontierSet;
std::unordered_map<std::string, node_IDS> exploredSet;

void setMap();
void iterativeDeepeningDFS();
void depthFirstSearch();
void printMap();

grid_IDS getNodeStatus(int nodeRow, int nodeColumn);

std::vector<node_IDS> getNodeNeighbors(std::pair<int, int> nodePosition);
std::vector<node_IDS> checkExploredSet(std::vector<node_IDS> neighbors);

#endif
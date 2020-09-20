#ifndef IDS
#define IDS
#include <ctime>
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

extern node_IDS nodeGrid[][MAP_WIDTH];

// Current number to increment and assign to the
// number of a node_IDS
extern int exploredNumber;
extern int currentDepth;

extern std::stack<node_IDS> frontierSet;
extern std::unordered_map<std::string, node_IDS> exploredSet;

void setMapAndSets();
void iterativeDeepeningDFS();
void printMap();
void addNodesToGrid(std::vector<node_IDS> nodeList);

bool depthFirstSearch(node_IDS currentNode, short depthLimit);

std::string assignNodeNumber();

grid_IDS getNodeStatus(int nodeRow, int nodeColumn);

std::vector<node_IDS> getNodeNeighbors(const std::pair<int, int> nodePosition);
std::vector<node_IDS> checkExploredSet(const std::vector<node_IDS> neighbors);

#endif
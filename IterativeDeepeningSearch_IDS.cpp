#include "IterativeDeepeningSearch_IDS.hpp"

void setMap() {

    // Set Entire Board
    for (short x = 0; x < 6; x++) {
        for (short y = 0; y < 5; y++) {
            nodeGrid[x][y].number = "  ";
            nodeGrid[x][y].isVisited = false;
            nodeGrid[x][y].status = grid_IDS::FRE;
            nodeGrid[x][y].position = std::make_pair(x, y);
        }
    }

    // Set Block Location
    for (short z = 1; z < 5; z++) {
        nodeGrid[z][1].number = "##";
        nodeGrid[z][1].isVisited = false;
        nodeGrid[z][1].status = grid_IDS::BLOK;
    }

    nodeGrid[1][2].number = "##";
    nodeGrid[1][2].isVisited = false;
    nodeGrid[1][2].status = grid_IDS::BLOK;

    nodeGrid[3][2].number = "##";
    nodeGrid[3][2].isVisited = false;
    nodeGrid[3][2].status = grid_IDS::BLOK;

    // Set Start Location
    nodeGrid[3][0].number = "00";
    nodeGrid[3][0].isVisited = true;
    nodeGrid[3][0].status = grid_IDS::STRT;

    // Set End Location
    nodeGrid[2][2].number = "  ";
    nodeGrid[2][2].isVisited = false;
    nodeGrid[2][2].status = grid_IDS::GOL;

    exploredNumber = 0;
}

void iterativeDeepeningDFS() {
    setMap();
    // While the explored set does not contain the goal
    // Run the DFS
    // Print the map after every loop
    printMap();
}

bool depthFirstSearch() {

    // Keep track of current depth
    // Increment depth until it matches given depth limit

    return false;
}

void printMap() {
    std::cout << "------------------\n";
    for (short x = 0; x < 6; x++) {
        for (short y = 0; y < 5; y++) {
            std::cout << nodeGrid[x][y].number << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "------------------\n";
}

std::vector<node_IDS> getNodeNeighbors(std::pair<int, int> nodePosition) {

    std::vector<node_IDS> neighbors{};
    grid_IDS nodeStatus;

    nodeStatus = getNodeStatus(nodePosition.first, nodePosition.second - 1);
    if (nodeStatus == FRE || nodeStatus == GOL) {
        neighbors.push_back(
            nodeGrid[nodePosition.first][nodePosition.second - 1]);
    }

    nodeStatus = getNodeStatus(nodePosition.first - 1, nodePosition.second);
    if (nodeStatus == FRE || nodeStatus == GOL) {
        neighbors.push_back(
            nodeGrid[nodePosition.first - 1][nodePosition.second]);
    }

    nodeStatus = getNodeStatus(nodePosition.first, nodePosition.second + 1);
    if (nodeStatus == FRE || nodeStatus == GOL) {
        neighbors.push_back(
            nodeGrid[nodePosition.first][nodePosition.second + 1]);
    }

    nodeStatus = getNodeStatus(nodePosition.first + 1, nodePosition.second);
    if (nodeStatus == FRE || nodeStatus == GOL) {
        neighbors.push_back(
            nodeGrid[nodePosition.first + 1][nodePosition.second]);
    }

    return neighbors;
}

std::vector<node_IDS> checkExploredSet(std::vector<node_IDS> neighbors) {
    std::vector<node_IDS> filteredNeighbors{};

    for (node_IDS temp : neighbors) {
        std::unordered_map<std::string, node_IDS>::const_iterator got = exploredSet.find(temp.number);

        if (got == exploredSet.end() && temp.status != BLOK)
            filteredNeighbors.push_back(temp);
    }

    return filteredNeighbors;
}

grid_IDS getNodeStatus(int nodeRow, int nodeColumn) {
    if (nodeRow < 0 || nodeRow >= MAP_WIDTH) {
        return BLOK;
    }

    if (nodeColumn < 0 || nodeColumn >= MAP_HEIGHT) {
        return BLOK;
    }

    return nodeGrid[nodeRow][nodeColumn].status;
}

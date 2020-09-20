#include "IterativeDeepeningSearch_IDS.hpp"

void setMapAndSets() {

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
    exploredSet.clear();

    while (!frontierSet.empty()) {
        frontierSet.pop();
    }
}

void iterativeDeepeningDFS() {
    short depthLimit = 1;
    short currentDepth = 0;

    // Set the map
    setMapAndSets();

    // Set start point of maze
    frontierSet.push(nodeGrid[3][0]);

    // While the explored set does not contain the goal
    // Run the DFS
    while (!depthFirstSearch(nodeGrid[3][0], currentDepth, depthLimit)) {
        printMap();       // Print the map after every loop
        setMapAndSets();  // Reset the map and frontier and explored set
        depthLimit++;     // Increase the depth limit
        currentDepth = 0; // Reset the current depth
        frontierSet.push(nodeGrid[3][0]);
    }

    // Print the map after final Success
    printMap();
}

bool depthFirstSearch(node_IDS currentNode, short &currentDepth, short depthLimit) {

    // 1. Increment the current depth (except if we are at root)
    if (currentNode.status != STRT)
        currentDepth++;

    //   2. Mark current node as visited
    // 2-1. Add node to the explored set (.number, node_IDS)
    exploredSet.emplace(currentNode.number, currentNode);

    // 2-2. Pop node off of frontier set
    frontierSet.pop();

    // 2-3. If node is available, mark it as visited
    //      if it is instead the final goal, then the search is done
    if (currentNode.status == FRE)
        currentNode.status = NOTFRE;
    else if (currentNode.status == GOL)
        return true;

    // 2-4. If we reached the depth limit
    //      we have failed the search in this branch
    if (currentDepth == depthLimit) {
        currentDepth--;
        return false;
    }

    //   3. Get neighbors of node
    // 3-1. Get all available childen of node
    // 3-1. Filter them to get only unexplored nodes
    //      by checking if they are in exploredSet
    std::vector<node_IDS> thisNodeNeighbors = checkExploredSet(getNodeNeighbors(currentNode.position));

    //   4. If the neighbors list is empty then
    //      this branch is a dead end
    if (thisNodeNeighbors.empty()) {
        currentDepth--;
        return false;
    }

    //   5. Assign a number to all of the neighboring nodes
    //      so that they can be printed later on
    //      and also be added to the explored list
    std::vector<node_IDS>::reverse_iterator rit = thisNodeNeighbors.rbegin();
    for (; rit != thisNodeNeighbors.rend(); ++rit)
        rit->number = assignNodeNumber();

    return false;
}

std::string assignNodeNumber() {

    exploredNumber++;
    if (exploredNumber < 10) {

        return " " + std::to_string(exploredNumber);
    }
    return std::to_string(exploredNumber);
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

std::vector<node_IDS> getNodeNeighbors(const std::pair<int, int> nodePosition) {

    std::vector<node_IDS> neighbors{};
    grid_IDS nodeStatus;

    // Down
    nodeStatus = getNodeStatus(nodePosition.first + 1, nodePosition.second);
    if (nodeStatus == FRE || nodeStatus == GOL) {
        neighbors.push_back(
            nodeGrid[nodePosition.first + 1][nodePosition.second]);
    }

    // Right
    nodeStatus = getNodeStatus(nodePosition.first, nodePosition.second + 1);
    if (nodeStatus == FRE || nodeStatus == GOL) {
        neighbors.push_back(
            nodeGrid[nodePosition.first][nodePosition.second + 1]);
    }

    // Up
    nodeStatus = getNodeStatus(nodePosition.first - 1, nodePosition.second);
    if (nodeStatus == FRE || nodeStatus == GOL) {
        neighbors.push_back(
            nodeGrid[nodePosition.first - 1][nodePosition.second]);
    }

    // Left
    nodeStatus = getNodeStatus(nodePosition.first, nodePosition.second - 1);
    if (nodeStatus == FRE || nodeStatus == GOL) {
        neighbors.push_back(
            nodeGrid[nodePosition.first][nodePosition.second - 1]);
    }

    return neighbors;
}

std::vector<node_IDS> checkExploredSet(const std::vector<node_IDS> neighbors) {
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

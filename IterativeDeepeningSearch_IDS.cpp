#include "IterativeDeepeningSearch_IDS.hpp"

void setMapAndSets() {

    // Set Entire Board
    for (short x = 0; x < 6; x++) {
        for (short y = 0; y < 5; y++) {
            nodeDFSGrid[x][y].number = "  ";
            nodeDFSGrid[x][y].isVisited = false;
            nodeDFSGrid[x][y].status = grid_IDS::FRE;
            nodeDFSGrid[x][y].position = std::make_pair(x, y);
        }
    }

    // Set Block Location
    for (short z = 1; z < 5; z++) {
        nodeDFSGrid[z][1].number = "##";
        nodeDFSGrid[z][1].isVisited = false;
        nodeDFSGrid[z][1].status = grid_IDS::BLOK;
    }

    nodeDFSGrid[1][2].number = "##";
    nodeDFSGrid[1][2].isVisited = false;
    nodeDFSGrid[1][2].status = grid_IDS::BLOK;

    nodeDFSGrid[3][2].number = "##";
    nodeDFSGrid[3][2].isVisited = false;
    nodeDFSGrid[3][2].status = grid_IDS::BLOK;

    // Set Start Location
    nodeDFSGrid[3][0].number = "00";
    nodeDFSGrid[3][0].isVisited = true;
    nodeDFSGrid[3][0].status = grid_IDS::STRT;

    // Set End Location
    nodeDFSGrid[2][2].number = "  ";
    nodeDFSGrid[2][2].isVisited = false;
    nodeDFSGrid[2][2].status = grid_IDS::GOL;

    exploredDFSNumber = 0;
    exploredDFSSet.clear();

    while (!frontierDFSSet.empty()) {
        frontierDFSSet.pop();
    }
}

void iterativeDeepeningDFS() {
    short depthLimit = 0;
    currentDFSDepth = 0;

    // Set the map
    setMapAndSets();

    // Set start point of maze
    frontierDFSSet.push(nodeDFSGrid[3][0]);

    // While the explored set does not contain the goal
    // Run the DFS
    while (!depthFirstSearch(nodeDFSGrid[3][0], depthLimit)) {
        printMap();          // Print the map after every loop
        setMapAndSets();     // Reset the map and frontier and explored set
        depthLimit++;        // Increase the depth limit
        currentDFSDepth = 0; // Reset the current depth
        frontierDFSSet.push(nodeDFSGrid[3][0]);
    }

    // Print the map after final Success
    printMap();
}

void printMap() {
    std::cout << "------------------\n";
    for (short x = 0; x < 6; x++) {
        for (short y = 0; y < 5; y++) {
            std::cout << nodeDFSGrid[x][y].number << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "------------------\n";
}

void addNodesToGrid(std::vector<node_IDS> nodeList) {
    for (short w = 0; w < nodeList.size(); w++)
        nodeDFSGrid[nodeList[w].position.first][nodeList[w].position.second] = nodeList[w];
}

bool depthFirstSearch(node_IDS currentNode, short depthLimit) {

    std::cout << "Current Node: " << currentNode.number << std::endl;

    // 1. Increment the current depth (except if we are at root)
    if (currentNode.status != STRT &&
        (currentNode.status == FRE ||
         currentNode.status == GOL))
        currentDFSDepth++;

    //   2. Mark current node as visited
    // 2-1. Add node to the explored set (.number, node_IDS)
    exploredDFSSet.emplace(currentNode.number, currentNode);

    // 2-2. Pop node off of frontier set
    frontierDFSSet.pop();

    // 2-3. If node is available, mark it as visited
    //      if it is instead the final goal, then the search is done
    if (currentNode.status == FRE) {
        currentNode.status = NOTFRE;
        currentNode.isVisited = true;
    } else if (currentNode.status == GOL) {
        currentNode.isVisited = true;
        currentDFSDepth--;
        return true;
    }

    // 2-4. If we reached the depth limit
    //      we have failed the search in this branch
    if (currentDFSDepth == depthLimit) {
        currentDFSDepth--;
        std::cout << "Current depth after hitting depth limit: " << currentDFSDepth << std::endl;
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
        currentDFSDepth--;
        return false;
    }

    //   5. Assign a number to all of the neighboring nodes
    //      so that they can be printed later on
    //      and also be added to the explored list
    for (short y = 0; y < thisNodeNeighbors.size(); y++) {
        thisNodeNeighbors[y].number = assignNodeNumber();
        thisNodeNeighbors[y].isVisited = true;
    }


    std::cout << "\nCurrent Neighbors: ";
    for (short i = 0; i < thisNodeNeighbors.size(); i++) {
        std::cout << " " << thisNodeNeighbors[i].number;
    }
    std::cout << std::endl;

    //   6 Add nodes to node grid so they can be displayed
    //     later on with the print map function
    addNodesToGrid(thisNodeNeighbors);

    //   7. Push the neighbors onto the frontier stack
    //      so we can explore them
    std::vector<node_IDS>::iterator it = thisNodeNeighbors.begin();
    for (; it != thisNodeNeighbors.end(); it++) {
        frontierDFSSet.push(*it);
    }

    //   8. If the frontier stack is emty then we have failed the search
    if (frontierDFSSet.empty()) {
        currentDFSDepth--;
        return false;
    }

    std::cout << "Current frontier set top value: " << frontierDFSSet.top().number << std::endl;
    std::cout << "Current Depth: " << currentDFSDepth << std::endl;
    //   9. For the amount of neighbors of the current node
    //      run the search to explore all if the options
    //      until we fund the GOAL, and if that doesnt happen
    //      then we fail
    for (short z = 0; z < thisNodeNeighbors.size(); z++) {
        if (depthFirstSearch(frontierDFSSet.top(), depthLimit)) {
            currentDFSDepth--;
            return true;
        }
    }

    currentDFSDepth--;
    return false;
}

std::string assignNodeNumber() {

    exploredDFSNumber++;
    if (exploredDFSNumber < 10) {

        return "0" + std::to_string(exploredDFSNumber);
    }
    return std::to_string(exploredDFSNumber);
}

std::vector<node_IDS> getNodeNeighbors(const std::pair<int, int> nodePosition) {

    std::vector<node_IDS> neighbors{};
    grid_IDS nodeStatus;

    // Left
    nodeStatus = getNodeStatus(nodePosition.first, nodePosition.second - 1);
    if ((nodeStatus == FRE || nodeStatus == GOL) && !nodeDFSGrid[nodePosition.first][nodePosition.second - 1].isVisited) {
        neighbors.push_back(
            nodeDFSGrid[nodePosition.first][nodePosition.second - 1]);
    }

    // Up
    nodeStatus = getNodeStatus(nodePosition.first - 1, nodePosition.second);
    if ((nodeStatus == FRE || nodeStatus == GOL) && !nodeDFSGrid[nodePosition.first - 1][nodePosition.second].isVisited) {
        neighbors.push_back(
            nodeDFSGrid[nodePosition.first - 1][nodePosition.second]);
    }

    // Right
    nodeStatus = getNodeStatus(nodePosition.first, nodePosition.second + 1);
    if ((nodeStatus == FRE || nodeStatus == GOL) && !nodeDFSGrid[nodePosition.first][nodePosition.second + 1].isVisited) {
        neighbors.push_back(
            nodeDFSGrid[nodePosition.first][nodePosition.second + 1]);
    }

    // Down
    nodeStatus = getNodeStatus(nodePosition.first + 1, nodePosition.second);
    if ((nodeStatus == FRE || nodeStatus == GOL) && !nodeDFSGrid[nodePosition.first + 1][nodePosition.second].isVisited) {
        neighbors.push_back(
            nodeDFSGrid[nodePosition.first + 1][nodePosition.second]);
    }

    return neighbors;
}

std::vector<node_IDS> checkExploredSet(const std::vector<node_IDS> neighbors) {
    std::vector<node_IDS> filteredNeighbors{};

    for (node_IDS temp : neighbors) {
        std::unordered_map<std::string, node_IDS>::const_iterator got = exploredDFSSet.find(temp.number);

        if (got == exploredDFSSet.end())
            filteredNeighbors.push_back(temp);
    }

    return filteredNeighbors;
}

grid_IDS getNodeStatus(int nodeRow, int nodeColumn) {
    if (nodeColumn < 0 || nodeColumn >= MAP_WIDTH) {
        return BLOK;
    }

    if (nodeRow < 0 || nodeRow >= MAP_HEIGHT) {
        return BLOK;
    }

    return nodeDFSGrid[nodeRow][nodeColumn].status;
}

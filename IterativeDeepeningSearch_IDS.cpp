#include "IterativeDeepeningSearch_IDS.hpp"

void setMap() {

    // Set Entire Board
    for (short x = 0; x < 6; x++) {
        for (short y = 0; y < 5; y++) {
            nodeIDSGrid[x][y].number = "  ";
            nodeIDSGrid[x][y].isVisited = false;
            nodeIDSGrid[x][y].status = grid_IDS::FRE;
            nodeIDSGrid[x][y].position = std::make_pair(x, y);
        }
    }

    // Set Block Location
    for (short z = 1; z < 5; z++) {
        nodeIDSGrid[z][1].number = "##";
        nodeIDSGrid[z][1].isVisited = false;
        nodeIDSGrid[z][1].status = grid_IDS::BLOK;
    }

    nodeIDSGrid[1][2].number = "##";
    nodeIDSGrid[1][2].isVisited = false;
    nodeIDSGrid[1][2].status = grid_IDS::BLOK;

    nodeIDSGrid[3][2].number = "##";
    nodeIDSGrid[3][2].isVisited = false;
    nodeIDSGrid[3][2].status = grid_IDS::BLOK;

    // Set Start Location
    nodeIDSGrid[3][0].number = "00";
    nodeIDSGrid[3][0].isVisited = true;
    nodeIDSGrid[3][0].status = grid_IDS::STRT;

    // Set End Location
    nodeIDSGrid[2][2].number = "  ";
    nodeIDSGrid[2][2].isVisited = false;
    nodeIDSGrid[2][2].status = grid_IDS::GOL;

    exploredNodeNumber = 0;
}

void iterativeDeepeningDFS() {

    // While the explored set does not contain the goal
    // Run the DFS
    // Print the map after every loop
    printMap();
}

void depthFirstSearch(int depthLimit) {

    // Keep track of current depth
    // Increment depth until it matches given depth limit
}

grid_IDS getNodeStatus(int x, int y) {
    if (x < 0 || x >= MAP_WIDTH) {
        return BLOK;
    }

    if (y < 0 || y >= MAP_HEIGHT) {
        return BLOK;
    }

    return nodeIDSGrid[x][y].status;
}

void printMap() {
    std::cout << "------------------\n";
    for (short x = 0; x < 6; x++) {
        for (short y = 0; y < 5; y++) {
            std::cout << nodeIDSGrid[x][y].number << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "------------------\n";
}
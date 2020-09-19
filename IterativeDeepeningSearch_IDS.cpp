#include "IterativeDeepeningSearch_IDS.hpp"

void setMap(node_IDS nodeGrid[6][5]) {

    // Set Entire Board
    for (short x = 0; x < 6; x++) {
        for (short y = 0; y < 5; y++) {
            nodeGrid[x][y].number = "  ";
            nodeGrid[x][y].isVisited = false;
            nodeGrid[x][y].status = grid_IDS::FRE;
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

void iterativeDeepeningDFS(node_IDS nodeGrid[6][5]) {



    printMap(nodeGrid);
}

void depthFirstSearch() {
}

void printMap(node_IDS nodeGrid[6][5]) {
    std::cout << "------------------\n";
    for (short x = 0; x < 6; x++) {
        for (short y = 0; y < 5; y++) {
            std::cout << nodeGrid[x][y].number << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "------------------\n";
}
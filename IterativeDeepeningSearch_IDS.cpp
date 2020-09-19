#include "IterativeDeepeningSearch_IDS.hpp"

void setMap() {

    // Set Entire Board
    for (short i = 0; i < 6; i++) {
        for (short j = 0; j < 5; j++) {
            nodeGrid[i][j].number = "  ";
            nodeGrid[i][j].isVisited = false;
            nodeGrid[i][j].status = FREE;
        }
    }

    // Set Block Location
    for (short i = 1; i < 5; i++) {
        nodeGrid[i][1].number = "  ";
        nodeGrid[i][1].isVisited = false;
        nodeGrid[i][1].status = BLOCK;
    }

    nodeGrid[1][2].number = "  ";
    nodeGrid[1][2].isVisited = false;
    nodeGrid[1][2].status = BLOCK;

    nodeGrid[3][2].number = "  ";
    nodeGrid[3][2].isVisited = false;
    nodeGrid[3][2].status = BLOCK;

    // Set Start Location
    nodeGrid[3][0].number = "00";
    nodeGrid[3][0].isVisited = true;
    nodeGrid[3][0].status = START;

    // Set End Location
    nodeGrid[2][2].number = "  ";
    nodeGrid[2][2].isVisited = false;
    nodeGrid[2][2].status = GOAL;
}
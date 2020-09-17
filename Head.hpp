#ifndef HEAD
#define HEAD
#include <vector>
#include <math.h>

// Enum of the directions agent can go
enum dir{
     LEFT, RIGHT, UP, DOWN, NONE
};


// Enum of the type of elements a map has
enum grid{
     FREE, BLOCK, START, GOAL
};

// The actual map
extern std::vector<std::vector<grid>> map;
extern std::pair<int, int> start_pos;
extern std::pair<int, int> end_pos;
#endif

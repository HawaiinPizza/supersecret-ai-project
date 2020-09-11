#ifndef HEAD
#define HEAD
#include <vector>

// Enum of the directions agent can go
enum class dir{
     LEFT=2, RIGHT=2, UP=3, DOWN=1
};

// Enum of the type of elements a map has
enum class grid{
     FREE, BLOCK, START, GOAL
};

// The actual map
extern std::vector<std::vector<grid>> map;

namespace search{
// Interactive depth search for the map
     std::vector<dir> ids(std::vector<std::vector<grid>> );

// A star search
     std::vector<dir> astar(std::vector<std::vector<grid>> );
     int wow();
}



#endif

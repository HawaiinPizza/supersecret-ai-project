#include "Head.hpp"
// The actual map
std::vector<std::vector<grid>> map={
     {grid::FREE,	grid::FREE,	  grid::FREE,	 grid::FREE,	grid::FREE},
     {grid::FREE,	grid::BLOCK,	grid::BLOCK,	grid::FREE,	grid::FREE},
     {grid::FREE,	grid::BLOCK,	grid::GOAL,	grid::FREE,	grid::FREE},
     // This posistion, [3,0], is starting
     {grid::FREE,	grid::BLOCK,	grid::BLOCK,	grid::FREE,	grid::FREE},
     {grid::FREE,	grid::BLOCK,	grid::FREE,	grid::FREE,	grid::FREE},
     {grid::FREE,	grid::FREE,	grid::FREE,	grid::FREE,	grid::FREE},
};
std::pair<int, int> startpos={3,0};
std::pair<int, int> endpos={2,2};



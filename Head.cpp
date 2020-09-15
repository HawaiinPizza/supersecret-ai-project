#include "Head.hpp"
<<<<<<< HEAD
#include <queue>
#include <iostream>
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
=======
#include <stack>

// The actual map
std::vector<std::vector<grid>> map={
     {grid::FREE,  grid::FREE,  grid::FREE} 
};

namespace search{
// Interactive depth search for the map
     std::vector<dir> ids(std::vector<std::vector<grid>> _map, std::pair<int, int> _startPosition){
	  std::vector<dir> solution;
	  std::stack<grid> front; // I can't spell frontier. #ADD brain in #ASS body
	  std::vector<grid> explored;
	  front.push( _map[_startPosition.first][_startPosition.second]);
	  while( ! front.empty()){
	       // set the current_node from front's first element
	       // get all leaf nodes on current frontier
	       // 
	  }
	  



	  return solution;
     }
// A star search
     std::vector<dir> astar(std::vector<std::vector<grid>> _map=map){
	  std::vector<dir> solution;
	  return solution;
     }
}
>>>>>>> 14d86be... first start

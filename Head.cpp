#include "Head.hpp"
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

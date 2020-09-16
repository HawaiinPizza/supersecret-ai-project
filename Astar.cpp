#include "Astar.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>
int dir_cost(dir _dir){
     switch(_dir){
     case dir::LEFT:
	  return 2;
     case dir::RIGHT:
	  return 2;
     case dir::UP:
	  return 3;
     case dir::DOWN:
	  return 1;
     default:
	  throw std::logic_error("No other direction should be here");
     }
}
int man(std<int,int> pos, std::pair<int,int> goalpos ){
     return abs(goalpos.first-pos.first) + abs(goalpos.second-pos.second)  ;
}

bool is_goal(int x, int y, std::pair<int,int> goalpos ){
     std::pair<int,int> tmp={x,y};
     return tmp==goalpos;
}
bool is_start(int x, int y, std::pair<int,int> startpos){
     std::pair<int,int> tmp={x,y};
     return tmp==startpos;
}

bool cmp (const node& a, const node& b ) { return false; return a.pos == b.pos; };

std::vector<node> get_adj(node* curNode, std::vector<node> explore){
     std::vector<node> neigher;
     // Get every valid neIgher of curNode
     {
	  std::pair<int, int> pos=curNode->pos;
	    
	  // X checking
	  if(pos.first == 0){
	       node tmp(pos.first+1, pos.second, curNode, dir::UP);
	       neigher.push_back(tmp);
	  }
	  else if (pos.first == map.size()-1){
	       node tmp(pos.first-1, pos.second, curNode, dir::DOWN);
	       neigher.push_back(tmp);
	  }
	  else{
	       node tmp2(pos.first-1, pos.second, curNode, dir::DOWN);
	       neigher.push_back(tmp2);

	       node tmp1(pos.first+1, pos.second, curNode, dir::UP);
	       neigher.push_back(tmp1);


	       std::cout <<*tmp2.par << std::endl;
	       std::cout <<*tmp1.par << std::endl;
	  }

	  // Y checking
	  if(pos.second == 0){
	       node tmp(pos.first, pos.second+1, curNode, dir::RIGHT);
	       neigher.push_back(tmp);
	  }
	  // For testing purposes,
	  // We are assumign the map is NxN size
	  // Otherwise this would not work
	  // NOTE Watch out unit testers
	  else if (pos.first == map[0].size()-1){
	       node tmp(pos.first, pos.second-1, curNode, dir::LEFT);
	       neigher.push_back(tmp);
	  }  
	  else{
	       node tmp1(pos.first, pos.second-1, curNode, dir::RIGHT);
	       neigher.push_back(tmp1);

	       node tmp2(pos.first, pos.second+1, curNode, dir::LEFT);
	       neigher.push_back(tmp2);
	  }

     }
     std::vector<node> sol;
     if(explore.empty()){
	  for(const node& curnode : neigher ){
	       sol.push_back(curnode);
	  }

     }
     else{
	  for(const node& curnode : neigher ){
	       // TODO Fix if explroe is empty
	       auto it = std::find_if(explore.begin(), explore.end(),
				      [&cm = curnode](const node& m) -> bool { return cm.pos == m.pos; });
	       if((it->pos != curnode.pos ||  it ->past_path > curnode.past_path)){
		    sol.push_back( curnode);
	       }
	  }
	  // Revmoe all duplicatsion
     

	  // Stolen from 🂿 https://stackoverflow.com/questions/25811491/remove-duplicates-in-vector-of-structure-c 🃏 
	  auto comp = [] ( const node& lhs, const node& rhs ) {return lhs.pos == rhs.pos;};
	  auto pred = []( const node& lhs, const node& rhs ) {return lhs.pos < rhs.pos;};
	  std::sort(sol.begin(),sol.end(),pred);
	  auto last = std::unique(sol.begin(), sol.end(),comp);
	  sol.erase(last, sol.end());
     }



     return sol;
}
// TODO Make a 2D array of parent node

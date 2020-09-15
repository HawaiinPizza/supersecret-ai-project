#ifndef ASTAR
#define ASTAR
#include <vector>
#include <queue>
#include <math.h>
#include "Head.hpp"

int dir_cost(dir _dir);
int man(std::pair<int,int> pos, std::pair<int,int> goalpos = end_pos);
bool is_goal(int x, int y, std::pair<int,int> goalpos = end_pos);
bool is_start(int x, int y, std::pair<int,int> startpos = start_pos);

struct node{
     std::pair<int, int> pos;
     int past_path;
     int pred_path;
     int path;
     const node* par;
     std::pair<int, int> parent_pos;
     node(int x, int y, const node* par, dir parent_dir){
	  pos={x,y};
	  past_path=par->past_path+dir_cost(parent_dir);
	  pred_path=man(pos);
	  path=pred_path+past_path;
     }
     node(int x, int y){
	  pos={x,y};
	  pred_path=man(pos);
	  past_path=0;
	  path=pred_path+past_path;
	  par=nullptr;
     }
     
     bool operator==(node rhs) const{
	  return pos == rhs.pos;
     }

};

struct astarCompare{
     bool operator()(const node& lhs, const node& rhs){
	  if(lhs.path == rhs.path){
	       return lhs.past_path < rhs.past_path;
	  }
	  return lhs.path < rhs.path;
     }
};

typedef std::priority_queue<node, std::vector<node>, astarCompare> aqueue;

// Get all the adjacent nodes of the current node
std::vector<node> get_adj(const node* curNode, const std::vector<node> explore, std::vector<node> test);

std::vector<node> get_path(std::vector<node>);


#endif

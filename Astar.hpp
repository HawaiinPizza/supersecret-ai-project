#ifndef ASTAR
#define ASTAR
#include <vector>
#include <math.h>
#include "Head.hpp"

int dir_cost(dir _dir);

struct node{
     std::pair<int, int> pos;
     int past_path;
     int pred_path;
     int path;
     std::pair<int, int> parent_pos;
     node(int x, int y, node* par, dir parent_dir){
	  pos={x,y};
	  past_path=par->past_path+dir_cost(parent_dir);
	  
	  
     }
};




#endif

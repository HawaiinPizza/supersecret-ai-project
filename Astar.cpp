#include "Astar.hpp"

vect get_neighers(const node* node){
     std::vector<struct node> neigherbors;
     point pos = node->pos;
     {// X checking
	  if( pos.x <= 0 ){

	       struct node tmp(point(pos.x+1, pos.y), node, DOWN, label++);
	       neigherbors.push_back(tmp);
	       
	  }
	  else if (pos.x >= map.size()){
	       struct node tmp(point(pos.x-1, pos.y), node,UP, label++);
	       neigherbors.push_back(tmp);
	  }
	  else{
	       struct node tmp1(point(pos.x+1, pos.y), node,DOWN, label++);
	       neigherbors.push_back(tmp1);

	       struct node tmp2(point(pos.x-1, pos.y), node,UP, label++);
	       neigherbors.push_back(tmp2);
	  }
     }
     {//Y checking
	  if( pos.y <= 0 ){

	       struct node tmp(point(pos.x, pos.y+1), node,  RIGHT, label++);
	       neigherbors.push_back(tmp);
	       
	  }
	  else if (pos.y >= map[0].size()){
	       struct node tmp(point(pos.x, pos.y-1), node, LEFT, label++);
	       neigherbors.push_back(tmp);
	  }
	  else{
	       struct node tmp1(point(pos.x, pos.y+1), node, RIGHT, label++);
	       neigherbors.push_back(tmp1);

	       struct node tmp2(point(pos.x, pos.y+1), node, LEFT, label++);
	       neigherbors.push_back(tmp2);
	  }
     }
     return neigherbors;
}

#include "Astar.hpp"
#include <algorithm>

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


// For each neighering node, check it in the epxlore set
vect should_check( vect neighs, vect explore ){
     vect sol;
     // NOTE This assumes node's equilvent oeprators compare label,
     // And it's greater then/less than compare path
     // NOTE if this hcanges it will not work.
     // NOTE Zaki i'm looking at you you freaking degerante
     for(node tmp: neighs){
	  auto it=find(explore.begin(), explore.end(), tmp);
	  // tmp is in explroe set
	  if(it != explore.end()){
	       // tmp is less then it
	       if(*it < tmp){
		    sol.push_back(tmp);
		    explore.erase(it);
	       }
	  }
	  else{
	       sol.push_back(tmp);
	  }
	  
     }
     return sol;

}
vect get_path(const node* start, const point* end ){
     vect sol;
     const node* tmp=start;
     while(tmp->pos != *end || tmp == NULL){
	  sol.push_back(*tmp);
	  std::cout << *tmp << std::endl;
	  if(tmp->par ==NULL){
	       throw("Path wasn't found, even though it should. OOPS");
	  }
	  tmp=tmp->par;
     }
     std::cout << *tmp << std::endl;
     return sol;
}


vect astar(const node* start, const point end){
     vect sol;
     frontQueue front;
     front.push(*start);
     vect explore;
     while(!front.empty()){
	  node cur = front.top();
	  front.pop();
	  explore.push_back(cur);
	  if(cur.pos == end){
	       std::cout << cur << std::endl;
	       return sol;
	       // return get_path(&cur, &start->pos);
	  }
	  vect neighers = get_neighers(&cur);
	  vect check_these = should_check(neighers, explore);
	  for(auto n: check_these){
	       front.push(n);
	  }

     }
     throw("God damn it it didn't get a path");
     
}

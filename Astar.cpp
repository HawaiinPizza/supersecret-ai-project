#include "Astar.hpp"
#include <algorithm>
#include <stdlib.h>


vect get_neighers(const node *node) {
    std::vector<struct node> neigherbors;
    point pos = node->pos;
    // LEFT
    if (getTile(pos.x, pos.y - 1) == FREE) {
        struct node tmp(point(pos.x, pos.y - 1), node, LEFT, label++);
        neigherbors.push_back(tmp);
    }

    // UP
    if (getTile(pos.x - 1, pos.y) == FREE) {
        struct node tmp(point(pos.x - 1, pos.y), node, UP, label++);
        neigherbors.push_back(tmp);
    }
    // RIGHT
    if (getTile(pos.x, pos.y + 1) == FREE) {
	  struct node tmp(point(pos.x, pos.y+1), node,  RIGHT);
	  neigherbors.push_back(tmp);   
     }

     // DOWN
     if( getTile(pos.x+1,pos.y) == FREE){
	  struct node tmp(point(pos.x+1, pos.y), node, DOWN);
	  neigherbors.push_back(tmp);
     }
     
     return neigherbors;
}


// For each neighering node, check it in the epxlore set
vect should_check( vect neighs, std::vector<vect>* explore, int& label ){
     vect sol;
     // NOTE This assumes node's equilvent oeprators compare label,
     // And it's greater then/less than compare path
     // NOTE if this hcanges it will not work.
     // NOTE Zaki i'm looking at you you freaking degerante
     for(node tmp: neighs){
	  point pos=tmp.pos;
	  // tmp is not in explore set
	  if( (*explore)[pos.x][pos.y].null() ){
	       tmp.label=label;
	       label++;
	       (*explore)[pos.x][pos.y] = tmp;
	       sol.push_back(tmp);
	  }
	  // // tmp in explored but has less path cost then what's currenlty in
	  else if( (*explore)[pos.x][pos.y] > tmp){
	       tmp.label = (*explore)[pos.x][pos.y].label;
	       (*explore)[pos.x][pos.y] = tmp;
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
	  if(tmp->par ==NULL){
	       std::cerr << ("Path wasn't found, even though it should. OOPS");
	  }
	  tmp=tmp->par;
     }
     sol.push_back(*tmp);
     return sol;
}


std::vector<vect> astar(const node* start, const point end){
     std::vector<vect> sol;
     frontQueue front;
     front.push(*start);
     std::vector<vect> explore;
     explore.resize(map.size());
     for(int i=0; i<map.size(); i++){
	  explore[i].resize(map[i].size());
     }
     int label = 1;
     explore[start->pos.x][start->pos.y]=*start;
     while(!front.empty()){
	  node* cur = new node;
	  *cur = front.top();
	  front.pop();
	  if(cur->pos == end){
	       return explore;
	  }
	  vect neighers = get_neighers(cur);
	  vect check_these = should_check(neighers, &explore, label);
	  for(auto n: check_these){
	       front.push(n);
	  }
     }
     return sol;

}

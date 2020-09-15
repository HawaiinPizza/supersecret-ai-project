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

// Using manhaten distance because why not?  It's easy and quick to do
int man(std::pair<int,int> pos, std::pair<int,int> goalpos ){
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

#include <iostream>
using namespace std;
std::vector<node> get_adj(const node* curNode, std::vector<node> explore, std::vector<node> test){
     std::vector<node> neigher=test;
     // Get every valid neigher of curNode
     /*
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
    node tmp1(pos.first+1, pos.second, curNode, dir::UP);
    neigher.push_back(tmp1);

    node tmp2(pos.first-1, pos.second, curNode, dir::DOWN);
    neigher.push_back(tmp2);
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

		node tmp2(pos.first, pos.second, curNode, dir::LEFT);
		neigher.push_back(tmp2);
	    }

	    }
     */
     std::pair<int,int> kiss = {2,3};
     std::vector<node> sol;
     for(int i=0; i<neigher.size(); i++){
	       cout << i << "  "<< neigher[i].pos.first << ":" << neigher[i].pos.second  << " index\n";
	  for( node &explored : explore){
	       cout <<  explored.pos.first << ":" << explored.pos.second  << " explore\t|\t";
	       if(explored.pos == neigher[i].pos){
		    if(explored.pos == kiss)
			 cout << "PAY ATTENTION\t|";

		    if(explored.past_path <= neigher[i].past_path){
			 cout << "node already exist and is smaller";
		    }
		    else{
			 sol.push_back(neigher[i]);
			 cout  << "has smaller past path" ;
		    }
	       }
	       else{

		    sol.push_back(neigher[i]);
		    cout  << "nodes are different" ;
	       }
	       cout << endl;
	  }
     }
     return sol;
}

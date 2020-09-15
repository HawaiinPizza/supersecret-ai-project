#include<iostream>
using namespace std;
#include <vector>
#include <queue>
enum tile{
     START, OPEN, CLOSE, GOAL
};
vector<vector<tile>> map{
     {OPEN,	OPEN,	OPEN,	OPEN,	OPEN},
     {OPEN,	CLOSE,	CLOSE,	OPEN,	OPEN},
     {OPEN,	CLOSE,	GOAL,	OPEN,	OPEN},
     {OPEN,	CLOSE,	CLOSE,	OPEN,	OPEN},
     {OPEN,	CLOSE,	OPEN,	OPEN,	OPEN},
     {OPEN,	OPEN,	OPEN,	OPEN,	OPEN},
     
};

struct node{
     int x; int y;
     node* parent = nullptr;
     int past; int cur; int total;
     vector<node> adj;

     
};


node newnode(int x, int y){
     node tmp;
     tmp.x=x;
     tmp.y=y;
     return tmp;

}

struct CustomComp{
     bool operator()(const node& lhs, const node& rhs){
	  if(lhs.total == rhs.total){
	       return lhs.cur > rhs.cur;
	  }
	  return lhs.total > rhs.total;
	  
	  
     }
};



void getAdj(const node* _node){
     queue<node> sol;
     int x=_node->x;
     int y=_node->y;
     // cout << "X is in ";
     if(x >= 0 && x < map.size()){
	  // X is too big then
	  if(x==0){
	       sol.push(newnode(x+1,y));
	       // cout << "X is at bottom edge" << endl;
	  }
	  else if (x==map.size()-1){
	       sol.push(newnode(x-1,y));
	       // cout << "X is at top edge" << endl;
	  }
	  else{
	       sol.push(newnode(x-1,y));
	       sol.push(newnode(x+1,y));
	       // cout << "X is valid up and down" << endl;
	  }
	  
     }
     // else
     // 	  cout << "Not in x range" << endl;
     
     // cout << "Y is in ";
     if(y >= 0 && y < map[0].size()){
	  if(y==0){
	       sol.push(newnode(x,y+1));
	       // cout << "Y is at left edge" << endl;
	  }
	  else if (y==map[0].size()-1){
	       sol.push(newnode(x,y-1));
	       // cout << "Y is at right edge" << endl;
	  }
	  else{
	       sol.push(newnode(x,y+1));
	       sol.push(newnode(x,y-1));
	       // cout << "Y is valid left and right" << endl;
	  }
     }
     // else
     // 	  cout << "Not in y range" << endl;
     // cout << endl;
     return sol;
	  
}

void appendVect(queue<node>* lhs, const queue<node>* rhs){
     for(node x : *rhs){
	  lhs->push(x);
     }
}

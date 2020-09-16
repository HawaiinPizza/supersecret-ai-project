#include "Astar.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main(){
     vector<node> explore;
     vector<node> test;
     node start=node(2,3);
     node left=node(2,2, &start, dir::DOWN);
     node right=node(2,4, &start, dir::DOWN);

     node down=node(3,3, &start, dir::DOWN);
     node up=node(1,3, &start, dir::DOWN);

     explore.push_back(left);
     explore.push_back(right);
     explore.push_back(down);
     explore.push_back(up);


     auto a =get_adj(&start, explore );

     cout << "insdie explore set we have" << endl;
     
     for(auto x : explore){
	  cout << x.pos.first << ':' << x.pos.second << "\t" << x.past_path <<endl;
     }
     cout << endl;

     {
	  const node* temp;
	  temp = &up;
	  cout << *temp << endl;
	  while(temp->pos != start.pos ){
	       temp=temp->par;
	  }
	  
     }

     


}


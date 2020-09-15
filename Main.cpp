#include "Astar.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main(){
     vector<node> explore;
     vector<node> test;
     node start=node(2,3);
     node a1=node(2,1, &start, dir::RIGHT);
     node a2=node(2,2, &start, dir::LEFT);
     node a3=node(2,3, &start, dir::UP);
     node a4=node(2,3, &start, dir::DOWN);

     explore.push_back(a1);
     explore.push_back(a2);
     explore.push_back(a3);

     test.push_back(a1);
     test.push_back(a2);

     test.push_back(a4);
     test.push_back(a4);
     test.push_back(a4);
     test.push_back(a4);

     auto a =get_adj(&start, explore, test);

     for(auto x : a){
	  cout << x.pos.first << ':' << x.pos.second << "\t" << x.past_path <<endl;
     }
     


}

#include "Astar.hpp"
#include <vector>
#include <iostream>
#include <cassert>
#include <queue>
#include <algorithm>
using namespace std;

int distChecking(){
     point pointstay(5,5);
     // North east 
     point p(3,7);
     assert(dist(pointstay, p)  == 10);

     // North
     p=point(3,5);
     assert(dist(pointstay, p)  == 6);
     
     // Norht west
     p=point(3,3);
     assert(dist(pointstay, p)  == 10);
     
     // East
     p=point(5,7);
     assert(dist(pointstay, p)  == 4);

     // Sotuh East
     p=point(7,7);
     assert(dist(pointstay, p)  == 6);

     // South
     p=point(7,5);
     assert(dist(pointstay, p)  == 2);

     // South west
     p=point(7,3);
     assert(dist(pointstay, p)  == 6);

     // West
     p=point(5,3);
     assert(dist(pointstay, p)  == 4);

     return 0;
     


}


void nodeCheck(){
     // cout << "Ending posistion " << _end_pos << endl;
     // cout<< dist(point(3,1), _end_pos) << endl;
     // node n1(point(3,1)); cout << n1 << endl;

     node n1(point(3,1));

     node n2(point(3, 2), &n1, RIGHT, 1);
     node n7(point(2, 2), &n2, UP,6 );

     node n3(point(3, 0), &n1, LEFT, 2);
     node n4(point(4, 1), &n1, DOWN, 3);
     node n5(point(2, 1), &n1, UP,4 );
     node n6(point(3, 3), &n2, RIGHT, 5);

     assert(5==n1.path);
     assert(5==n2.path);
     assert(5==n7.path);

     assert(9==n3.path);
     assert(9==n4.path);
     assert(5==n5.path);
     assert(9==n6.path);



}

void neigherCheck(){
     auto check = [](int x, int y, int count){
	  node tmp(point(x,y));
	  vector<node> list = get_neighers(&tmp);
	  assert(list.size() == count);
     };
     // Middle Middle 4
     check(3,3, 4);
     // Top left 2
     check(0,0, 2);
     // Top right 2
     check(0,0, 2);
     // Bottom left 2
     check(map.size(),0, 2);
     // Bottom right 2
     check(map.size(),map[0].size(), 2);
     // Top Middle 3
     check(0, 3, 3);
     // Bottom Middle 3
     check(map.size(), 3, 3);
     // Middle Left 3
     check(3, 0, 3);
     // Middle Right 3
     check(3, map[0].size(), 3);
}

void explroeCheck(){

     { // Checking if you can search thorugh the list
	  node n1(point(3,1));
	  node n2(point(3, 2), &n1, RIGHT, 1);
	  node n7(point(2, 2), &n2, UP,6 );

	  node n3(point(3, 0), &n1, LEFT, 2);
	  node n6(point(3, 3), &n2, RIGHT, 5);
	  node n4(point(4, 1), &n1, DOWN, 3);
	  node n5(point(2, 1), &n1, UP,4 );
	  vect test={n1,n2,n3};

	  auto it=find(test.begin(), test.end(), n1);
	  assert(it != test.end());
	  it=find(test.begin(), test.end(), n4);
	  assert(it == test.end());

     }
     { // Now check explore 
	  node n(point(3,3));
	  node nl(point(3,2), &n, LEFT, 1);
	  node nr(point(3,4), &n, RIGHT, 2);
	  node nu(point(2,3), &n, UP, 3);
	  node nd(point(4,3), &n, DOWN, 4);
	  // DONE if neighers are all already in explored
	  vect test={nl,nr, nu, nd};
	  assert(should_check(test, test).size()==0 );
	  vect tmp=test;
	  // DONE if neighers are have shorter path then put it in sol
	  test[0].path=99;
	  test[1].path=99;
	  assert(should_check(tmp, test).size()==2 );
	  // DONE if neighers are not in explored
	  test.erase(find(test.begin(), test.end(), nl));
	  test.erase(find(test.begin(), test.end(), nr));
	  assert(should_check(tmp, test).size()==2 );
     }
}

void getPath(){
     { // real path
	  node n1(point(3,1));
	  node n2(point(3, 2), &n1, RIGHT, label++);
	  node n3(point(4, 2), &n2, DOWN, label++);
	  node n4(point(4, 1), &n3, LEFT, label++);
	  node n5(point(2, 1), &n4, DOWN, label++);
	  point tmp=point(3,1);
	  vect path=get_path(&n5, &tmp);
	  for(int i=0; i<path.size(); i++){
	       string dir;
	       switch ( path[i].par_dir){
	       case LEFT:
		    dir="LEFT";
		    break;
	       case RIGHT:
		    dir="RIGHT";
		    break;
	       case UP:
		    dir="UP";
		    break;
	       case DOWN:
		    dir="DOWN";
		    break;
	       case NONE:
		    dir="START";
		    break;
	       };
	       cout << path[i].label << ':' << dir << endl;
	  }

     }
}


void fronttest(){
     std::priority_queue<struct node, std::vector<node>, compare> test;
     node n1(point(3,1));
     node n2(point(3, 2), &n1, RIGHT, label++);
     node n3(point(4, 2), &n2, DOWN, label++);
     node n4(point(4, 1), &n3, LEFT, label++);
     node n5(point(2, 1), &n4, DOWN, label++);
     test.push(n1);
     test.push(n2);
     test.push(n3);
     test.push(n4);
     test.push(n5);
     int tmp = test.top().path;
     while(!test.empty()){
	  cout << test.top() << endl;
	  test.pop();
     }
}

void aastar(){
     node start(point(3,0));
     point end(2,2);
     vect test=astar(&start, end);
     for(auto x: test){
	  cout << x << endl;
     }
}
int main(){
     aastar();
     // getPath();
     // fronttest();
     distChecking();
     nodeCheck();
     neigherCheck();
     explroeCheck();

}

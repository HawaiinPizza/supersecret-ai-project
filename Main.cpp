#include "Astar.hpp"
#include <vector>
#include <iostream>
#include <cassert>
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

     node n2(point(3, 2), n1, RIGHT, 1); cout << n2 << endl;
     node n7(point(2, 2), n2, UP,6 ); cout << n7 << endl;

     node n3(point(3, 0), n1, LEFT, 2); cout << n3 << endl;
     node n6(point(3, 3), n2, RIGHT, 5); cout << n6 << endl;
     node n4(point(4, 1), n1, DOWN, 3); cout << n4 << endl;
     node n5(point(2, 1), n1, UP,4 ); cout << n5 << endl;


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

int main(){
     distChecking();
     // nodeCheck();
     neigherCheck();
}

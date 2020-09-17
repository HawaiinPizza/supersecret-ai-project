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


int main(){
     distChecking();
}

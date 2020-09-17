#include "Astar.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>
point::point(){
     x=0;
     y=0;
}
point::point(int _y, int _x){
     x=_x;
     y=_y;
}
bool point::operator==(const point& rhs){
     return (this->x == rhs.x &&  this->y == rhs.y );
}
bool point::operator!=(const point& rhs){
     return (this->x != rhs.x &&  this->y != rhs.y );
}
point point::operator+(const point& rhs){
     point tmp(rhs.x+this->x, rhs.y+this->y);
     return tmp;
}
point point::operator+=(const point& rhs){
     point tmp(rhs.x+this->x, rhs.y+this->y);
     this->x = tmp.x;
     this->y = tmp.y;
     return *this;;
}
point point::operator-(const point& rhs){
     point tmp(rhs.x-this->x, rhs.y-this->y);
     return tmp;
}
point point::operator-=(const point& rhs){
     point tmp(rhs.x-this->x, rhs.y-this->y);
     this->x = tmp.x;
     this->y = tmp.y;
     return *this;;
}

std::ostream &operator<<(std::ostream &os, const point& p){
     os << p.x << ':' << p.y;
     return os;
}
int dist(point start, point end){
     point tmp=end-start;
     // north movement
     if(tmp.x > 0){
	  tmp.x=abs(tmp.x);
	  tmp.y=abs(tmp.y);
	  return tmp.x*3 + tmp.y*2;
     }
     // Southern movement
     else{
	  tmp.x=abs(tmp.x);
	  tmp.y=abs(tmp.y);
	  return tmp.x + tmp.y*2;
     }
}

// int dist(std::pair<int,int> start, std::pair<int,int> end){
//      // std::pair<int,int> tmp={end.first-start.first, end.second-start.first };
//      std::pair<int,int> tmp={end.first-start.first, end.second-start.first };
//      // north movement
//      if(tmp.first > 0){
// 	  tmp.first=abs(tmp.first);
// 	  tmp.second=abs(tmp.second);
// 	  return tmp.second*3 + tmp.first*2;
//      }
//      // Southern movement
//      else{
// 	  tmp.first=abs(tmp.first);
// 	  tmp.second=abs(tmp.second);
// 	  return tmp.second + tmp.first*2;
//      }
// }

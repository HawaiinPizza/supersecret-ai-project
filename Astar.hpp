#ifndef ASTAR
#define ASTAR
#include "Nodes.hpp"
#include <queue>


vect get_neighers(const node* node);
vect should_check(vect neighs, vect explore );
vect get_path(const node* start, const point* end );
vect astar(const node* start, const point end);

struct compare{
    bool operator()(const node& p1, const node& p2) {
	 if(p1.path == p2.path)
	      return p1.label > p2.label;
	 return p1.path > p2.path;
    }
};
typedef std::priority_queue<struct node, std::vector<node>, compare> frontQueue;

#endif

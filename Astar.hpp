#ifndef ASTAR
#define ASTAR
#include "Nodes.hpp"


vect get_neighers(const node* node);
vect check_neighers(vect nodes);
vect get_path(const point* start, const point* end );
vect astar(point start, point end);


#endif

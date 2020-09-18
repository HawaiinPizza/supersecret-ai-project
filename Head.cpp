#include "Head.hpp"
// The actual map
std::vector<std::vector<grid>> map={
     {FREE,	FREE,	FREE,	FREE,	FREE,	FREE},
     {FREE,	BLOCK,	BLOCK,	FREE,	FREE,	FREE},
     {FREE,	BLOCK,	FREE,	FREE,	FREE,	FREE},
     {FREE,	BLOCK,	BLOCK,	FREE,	FREE,	FREE},
     {FREE,	BLOCK,	FREE,	FREE,	FREE,	FREE},
     {FREE,	FREE,	FREE,	FREE,	FREE,	FREE},
};
// std::vector<std::vector<grid>> map={
//      {FREE,	FREE,	  FREE,	 FREE,	FREE},
//      {FREE,	BLOCK,	BLOCK,	FREE,	FREE},
//      {FREE,	BLOCK,	FREE,	FREE,	FREE},
//      // This posistion, [3,0], is starting
//      {FREE,	BLOCK,	BLOCK,	FREE,	FREE},
//      {FREE,	BLOCK,	FREE,	FREE,	FREE},
//      {FREE,	FREE,	FREE,	FREE,	FREE},
// };
std::pair<int, int> start_pos={3,0};
std::pair<int, int> end_pos={2,2};



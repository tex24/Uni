#include "trinary-tree.h"
#include <string>

using namespace std;

std::string leavesToString(const triTree& tr){
  if(!tr)
    return "";
  if(!tr->child1 && !tr->child2 && !tr->child3)
    return to_string(tr->el) + " ";
  return leavesToString(tr->child1) + leavesToString(tr->child2) + leavesToString(tr->child3);
}


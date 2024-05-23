#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
public:
  // Constructor
  Node(std::string k) : key(k), height(1), right(nullptr), left(nullptr), size(1), min(k), max(k) {}

  // Members
  std::string key;
  int height;
  Node *right;
  Node *left;
  int size;
  std::string min;
  std::string max;
};

#endif
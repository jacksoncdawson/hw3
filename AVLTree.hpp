#ifndef AVLTREE_H
#define AVLTREE_H

#include "node.hpp"
#include <string>

class AVLTree
{
public:
  AVLTree() : root(nullptr) {} // Constructor

  void insert(std::string key);                      // interface insert function
  int get_range(std::string start, std::string end); // interface range function
  void destroy(); // interface destroy function

private:
  Node *root;

  int get_range(Node *node, std::string start, std::string end, int &range); 
  Node* update_minmax(Node* node);
  Node *insert(Node *node, std::string key);                                 // recursive insert function
  int size(Node *node);                                                      // gets size of subtree at node
  Node *rotate_right(Node *node);
  Node *rotate_left(Node *node);
  int height(Node *node);      // get height of node
  int get_balance(Node *node); // get balance of node
  void destroy(Node* node);
};

#endif
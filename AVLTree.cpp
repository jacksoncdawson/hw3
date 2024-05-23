#include "AVLTree.hpp"
#include <algorithm>
#include <string>
#include <string.h>
#include <iostream>

int AVLTree::get_range(Node *node, std::string start, std::string end, int &range)
{
  if (!node)
    return 0;

  if (node->max < start || node->min > end)
  {
    return 0; // out of range, skip
  }

  if (node->min >= start && node->max <= end)
  {
    range += node->size;
    return range;
  }
  if (start <= node->key && node->key <= end)
  {
    range++;
  }

  if (node->key > start)
  {
    get_range(node->left, start, end, range);
  }
  if (node->key < end)
  {
    get_range(node->right, start, end, range);
  }

  return range;
}

int AVLTree::get_range(std::string start, std::string end)
{
  int range = 0;
  return get_range(root, start, end, range);
}

Node *AVLTree::update_minmax(Node *node)
{
  if (!node)
    return node;

  node->min = node->left ? std::min(node->key, node->left->min) : node->key;
  node->max = node->right ? std::max(node->key, node->right->max) : node->key;

  return node;
}

int AVLTree::height(Node *node)
{
  return node ? node->height : 0;
}

int AVLTree::get_balance(Node *node)
{
  return node ? height(node->left) - height(node->right) : 0;
}

int AVLTree::size(Node *node)
{
  return node ? node->size : 0;
}

Node *AVLTree::rotate_left(Node *node)
{
  Node *new_root = node->right;
  Node *straggler = new_root->left;

  new_root->left = node;
  node->right = straggler;

  node->height = std::max(height(node->left), height(node->right)) + 1;
  new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;

  node->size = 1 + size(node->left) + size(node->right);
  new_root->size = 1 + size(new_root->left) + size(new_root->right);

  node = update_minmax(node);
  new_root = update_minmax(new_root);

  return new_root;
}

Node *AVLTree::rotate_right(Node *node)
{
  Node *new_root = node->left;
  Node *straggler = new_root->right;

  new_root->right = node;
  node->left = straggler;

  node->height = std::max(height(node->left), height(node->right)) + 1;
  new_root->height = std::max(height(new_root->left), height(new_root->right)) + 1;

  node->size = 1 + size(node->left) + size(node->right);
  new_root->size = 1 + size(new_root->left) + size(new_root->right);

  node = update_minmax(node);
  new_root = update_minmax(new_root);

  return new_root;
}

Node *AVLTree::insert(Node *node, std::string key)
{
  if (node == nullptr)
  {
    return new Node(key); // base case to add new node
  }

  // recursive step
  if (key < node->key)
  {
    node->left = insert(node->left, key);
  }
  else if (key > node->key)
  {
    node->right = insert(node->right, key);
  }
  else
  {
    return node; // no duplicates
  }

  node->height = 1 + std::max(height(node->left), height(node->right)); // update height for each recursed node

  int balance = get_balance(node);

  // check for left-left imbalance
  if (balance > 1 && key < node->left->key)
  {
    return rotate_right(node);
  }
  // check for left-right imbalance
  if (balance > 1 && key > node->left->key)
  {
    node->left = rotate_left(node->left);
    return rotate_right(node);
  }
  // check for right-right imbalance
  if (balance < -1 && key > node->right->key)
  {
    return rotate_left(node);
  }
  // check for right-left imbalance
  if (balance < -1 && key < node->right->key)
  {
    node->right = rotate_right(node->right);
    return rotate_left(node);
  }

  node->size = 1 + size(node->left) + size(node->right);
  node = update_minmax(node);
  return node;
}

void AVLTree::insert(std::string key)
{
  root = insert(root, key);
  root = update_minmax(root);
}

void AVLTree::destroy()
{
  destroy(root);
  root = nullptr;
}

void AVLTree::destroy(Node *node)
{
  if (node)
  {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

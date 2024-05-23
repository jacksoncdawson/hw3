# HW3: Life is all about balance

## Description

wordrange is a program used to build an avl tree consisting of strings given an input file, and then fulfill range queries on the tree to determine how many words are lexicographically placed between two given words in the tree. The program will then print the result of the range query to the output file.

### wordrange.cpp (and wordrange.hpp)

The main entry point and functionality of the application. Contains the main() function.

### AVLTree.cpp and AVLTree.hpp

Defines the AVLTree class. The AVLTree is the core data structure for this program, featuring public functions  'insert', 'get_range', and 'destroy'.
These functions are powered by the private methods, such as those for rotations, getting the height of a node, or getting the balance of a node's subtree.

### node.cpp and node.hpp

Defines the Node class. Node contains elements 'key', 'height', 'right', 'left', 'size', 'min', and 'max'. 
Height, key, right and left support basic AVL functionality, while size, min and max are purposeful additions to maximize efficiencty for range queries.

### Makefile

Used to build the project. Phony targets include `all`, and `clean`.

## Usage

### To Build

To build the project, use the provided Makefile:

```
make
```

### To Run

To run the project, you must provide a formatted input file, and an output file.

For example:

```
./wordrange <input-file> <output-file>
```

## Resources

I consulted the following resources to help inform my programming choices:

- https://www.geeksforgeeks.org/insertion-in-an-avl-tree/#

- https://youtu.be/vRwi_UcZGjU?si=S0K2u1pSQB711NrJ

- https://youtu.be/jDM6_TnYIqE?si=NAKTapbLCJgdd6Qb

- https://youtu.be/zP2xbKerIds?si=S8X58COkpgfh5nzc

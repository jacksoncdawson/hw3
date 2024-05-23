#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "AVLTree.hpp"
#include "node.hpp"

int main(int argc, char *argv[]) 
{
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
    return 1;
  }

  // open input and output files
  std::ifstream input_file(argv[1]);
  std::ofstream output_file(argv[2]);
  if (!input_file.is_open() || !output_file.is_open()) {
    std::cerr << "Error opening files!" << std::endl;
    return 1;
  }

  AVLTree tree;

  // for each line...
  std::string line;
  while (getline(input_file, line)) {
    std::istringstream iss(line);
    std::string command;
    std::string val, start, end;
    
    iss >> command;

    if (command == "r") {
      iss >> start >> end;
      int range = tree.get_range(start, end);
      output_file << range << std::endl;
    }
    else {
      iss >> val;
      tree.insert(val);
    }
  }

  input_file.close();
  output_file.close();

  tree.destroy();

  return 0;
}


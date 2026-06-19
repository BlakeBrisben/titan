#include "lexer.h"
#include "parser.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc == 2) {
    std::string filename = argv[1];
    std::cout << "Filename: " << filename << std::endl;
  }
}

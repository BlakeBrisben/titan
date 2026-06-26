#include "lexer.h"
#include "parser.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        string filename = argv[1];
        cout << "Filename: " << filename << std::endl;

        vector<string> lines;
        string line;

        ifstream file(filename);

        while (getline(file, line)) {
            cout << line << "\n";
            lines.push_back(line);
        }

        file.close();

        cout << "Number of lines: " << lines.size() << "\n";
    }
}

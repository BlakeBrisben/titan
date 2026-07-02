#include "lexer.h"
#include "parser.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        string filename = argv[1];
        cout << "Filename: " << filename << std::endl;
        vector<string> lines = lx::reader(filename);
        for (auto it = lines.begin(); it != lines.end(); ++it) {
            cout << *it << '\n';
        }
        cout << "Number of lines: " << lines.size() << "\n";

        lx::Lexer lexer = lx::init(filename);

        cout << lexer.lines.at(lexer.lineNum) << '\n';

        while(lexer.lineNum < lexer.lines.size()){
            lx::readNext(lexer);
        }
    }
}

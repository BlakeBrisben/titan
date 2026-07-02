#include <cctype>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

enum TokenType {
    NUM,
    STRING,
    BOOL,
    IDENT,
    DOUBLE_EQUAL,
    NOT_EQUAL,
    EQUAL,
    PLUS,
    MINUS,
    SLASH,
    ASTER,
    BANG,
    NONE
};

struct Token {
    TokenType type;
    size_t pos;
    size_t lineNum;
    std::string value;
};

Token createToken(TokenType t, int p, int ln, std::string v) {
    Token retTok;
    retTok.type = t;
    retTok.pos = p;
    retTok.lineNum = ln;
    retTok.value = v;

    return retTok;
}

namespace lx {

struct Lexer {
    std::vector<std::string> lines;
    size_t lineNum;
    size_t pos;
};

std::vector<std::string> reader(std::string filename) {
    std::vector<std::string> lines;
    std::string line;

    std::ifstream file(filename);

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

    return lines;
}

Lexer init(std::string filename) {
    std::vector<std::string> lines = reader(filename);

    if (lines.size() == 0) {
        perror("File not found or empty");
    }

    Lexer lexer;
    lexer.lines = lines;
    lexer.lineNum = 0;
    lexer.pos = 0;

    return lexer;
}

Token readNext(Lexer l) {
    std::string currLine = l.lines.at(l.lineNum);
    Token retTok = createToken(NONE, -1, -1, "");

    char cur = currLine.at(l.pos);
    char next = '\0';
    if (l.pos != currLine.size()) {
        next = currLine.at(l.pos);
    }
    switch (cur) {
    case ' ':
    case '\t':
        break;
    case '=':
        if (next != '\0') {
            if (next == '=') {
                retTok = createToken(DOUBLE_EQUAL, l.pos, l.lineNum, "");
                l.pos += 1;
            } else {
                retTok = createToken(EQUAL, l.pos, l.lineNum, "");
            }
        }
        break;
    case '!':;
        if (next != '\0') {
            if (next == '=') {
                retTok = createToken(NOT_EQUAL, l.pos, l.lineNum, "");
                l.pos += 1;
            } else {
                retTok = createToken(BANG, l.pos, l.lineNum, "");
            }
        }
        break;
    default:
        if (std::isalpha(cur)) {
            std::string ident = "";
            ident.push_back(cur);
            while (std::isalnum(next)) {
                ident.push_back(next);
                l.pos++;
                if (l.pos + 1 < currLine.size()) {
                    next = currLine.at(l.pos + 1);
                } else {
                    next = '\0';
                }
            }
            std::cout << ident << '\n';
        }
        break;
    }

    if (l.pos == currLine.size()) {
        l.lineNum++;
        l.pos = 0;
    } else {
        l.pos++;
    }

    return retTok;
}

} // namespace lx

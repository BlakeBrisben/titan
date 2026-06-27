#include <string>
#include <vector>

enum TokenType {
    NUM,
    STRING,
    IDENT,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    PLUS,
    MINUS,
    SLASH,
    ASTER,
    COLON,
    SEMI
};

struct Token {
    TokenType type;
    int lineNum;
    int col;
    std::string value;
};

namespace lx {
struct Lexer {
    std::vector<std::string> lines;
    int lineNum;
    int position;
};

std::vector<std::string> reader(std::string filename);

Lexer init(std::string filename);
} // namespace lx

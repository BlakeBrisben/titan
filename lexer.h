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
    size_t lineNum;
    size_t col;
    std::string value;
};

namespace lx {
struct Lexer {
    std::vector<std::string> lines;
    size_t lineNum;
    size_t position;
};

std::vector<std::string> reader(std::string filename);

Lexer init(std::string filename);

Token readNext(Lexer l);
} // namespace lx

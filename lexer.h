#include <string>

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
    std::string input;
    int lineNum;
    int position;
};
} // namespace lx

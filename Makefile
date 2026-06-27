make: main.cpp
	clang++ -Wall -Wextra -Werror main.cpp lexer.cpp parser.cpp token.cpp -o titan

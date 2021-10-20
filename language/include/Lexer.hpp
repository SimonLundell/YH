#ifndef LANG_LEXER_H
#define LANG_LEXER_H
#include <Token.hpp>

class Lexer
{
    public:
        Lexer(char* src);

        void advance();
        void skip_whitespace();

        Token* parse_string();
        Token* parse_number();
        Token* parse_id();
        Token* get_next_token();
        Token* token_current_char(TokenType type);

    private:
        char* src;
        unsigned int i;
        unsigned int length;
        char c;
        
};

#endif
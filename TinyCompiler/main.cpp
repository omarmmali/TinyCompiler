#include <iostream>

#include "Tokenizer.h"
#include "Parser.h"

int main() {
    //freopen("input.txt", "r", stdin);
    Tokenizer t;
    Parser p;
    std::string in;
    while(std::getline(std::cin, in)) {
        std::vector<Token> tokens = t.tokenize(in);
        p.parse(tokens);
        for(int i = 0; i < p.parse_tree.size(); i++) {
            if(p.parse_tree[i].empty()) {
                continue;
            }
            std::cout << Token::token_name((TokenType)(i + 1)) << std::endl;
            for(int j = 0; j < p.parse_tree[i].size(); j++) {
                std::cout << Token::token_name(p.parse_tree[i][j].rule_name) << std::endl;
            }
        }
    }
    return 0;
}
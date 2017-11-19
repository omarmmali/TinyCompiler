#include <iostream>

#include "Tokenizer.h"

int main() {
    //freopen("input.txt", "r", stdin);
    Tokenizer t;
    std::string in;
    while(std::getline(std::cin, in)) {
        auto tokens = t.tokenize(in);
        std::cout << "-----------------\n";
        for(auto i : tokens) {
            std::cout << i.lexeme << ' ' << Token::token_name(i.token_type) << std::endl;
        }
    }
    return 0;
}
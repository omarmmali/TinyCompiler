#include "Parser.h"

void add_terminals() {
    CFG[TokenType::INTEGER] = Node(1, TokenType::INTEGER);
    CFG[TokenType::DOUBLE] = Node(1, TokenType::DOUBLE);
    CFG[TokenType::STRING] = Node(1, TokenType::STRING);
    CFG[TokenType::COMMENT] = Node(1, TokenType::COMMENT);
    CFG[TokenType::IDENTIFIER] = Node(1, TokenType::IDENTIFIER);
    CFG[TokenType::PARAN_OPEN] = Node(1, TokenType::PARAN_OPEN);
    CFG[TokenType::PARAN_CLOSE] = Node(1, TokenType::PARAN_CLOSE);
    CFG[TokenType::OPERATOR_PLUS] = Node(1, TokenType::OPERATOR_PLUS);
    CFG[TokenType::OPERATOR_MINUS] = Node(1, TokenType::OPERATOR_MINUS);
    CFG[TokenType::OPERATOR_TIMES] = Node(1, TokenType::OPERATOR_TIMES);
    CFG[TokenType::OPERATOR_DIVISION] = Node(1, TokenType::OPERATOR_DIVISION);
    CFG[TokenType::OPERATOR_ASSIGNMENT] = Node(1, TokenType::OPERATOR_ASSIGNMENT);
    CFG[TokenType::SEMICOLON] = Node(1, TokenType::SEMICOLON);
    CFG[TokenType::COMMA] = Node(1, TokenType::COMMA);
    CFG[TokenType::EQUAL_OPERATOR] = Node(1, TokenType::EQUAL_OPERATOR);
    CFG[TokenType::LESS_THAN_OPERATOR] = Node(1, TokenType::LESS_THAN_OPERATOR);
    CFG[TokenType::GREATER_THAN_OPERATOR] = Node(1, TokenType::GREATER_THAN_OPERATOR);
    CFG[TokenType::NOT_EQUAL_OPERATOR] = Node(1, TokenType::NOT_EQUAL_OPERATOR);
    CFG[TokenType::LOGIC_AND_OPERATOR] = Node(1, TokenType::LOGIC_AND_OPERATOR);
    CFG[TokenType::LOGIC_OR_OPERATOR] = Node(1, TokenType::LOGIC_OR_OPERATOR);
    CFG[TokenType::AND_OPERATOR] = Node(1, TokenType::AND_OPERATOR);
    CFG[TokenType::OR_OPERATOR] = Node(1, TokenType::OR_OPERATOR);
}

void Parser::add_datatype() {
    Node cur;
    
    cur.terminal = true;


    cur.production.push_back(std::vector<Token>() = {Token(TokenType::INTEGER, "int")});
    cur.production.push_back(std::vector<Token>() = {Token(TokenType::DOUBLE, "double")});
    cur.production.push_back(std::vector<Token>() = {Token(TokenType::STRING, "string")});

    cur.rule_name = TokenType::DATATYPE;

    CFG[TokenType::DATATYPE] = cur;
}

Parser::Parser() {
    CFG.resize(1000);
    add_terminals();
    add_datatype();
}

std::pair<bool, Node> Parser::match(Node cur) {
    std::pair<bool, Node> ret;
    bool ok = 0;
    for(int i = 0; i < cur.production.size() && !ok; i++) {
        for(int j = 0; j < cur.production[i].size() && !ok; j++) {
            if(stream[stream_pointer].lexeme == cur.production[i][j].lexeme) {
                stream_pointer++;
                if(CFG[cur.production[i][j].token_type].terminal) {
                    ret = std::make_pair(true, cur);
                    ok = 1;
                }
                else {
                    ret = match(CFG[cur.production[i][j].token_type]);
                    if(ret.first) {
                        ok = 1;
                    }
                }         
            }
        }
    }
    if(ret.first) {
        parse_tree[cur.rule_name].push_back(ret.second);
    }
    return ret;
}

void Parser::parse(std::vector<Token> in) {
    stream = in;
    bool ok = 0;
    match(CFG[14]);
    // for(int i = 1; i < CFG.size(); i++) {
    //     stream_pointer = 0;
    //     parse_tree.clear();
    //     parse_tree.resize(1000);
    //     if(match(CFG[i]).first) {
    //         break;
    //     }
    // }
}
Parser::~Parser() {

}
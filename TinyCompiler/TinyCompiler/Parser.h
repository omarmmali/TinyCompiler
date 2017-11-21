#include "TokenType.h"

struct Node {
    bool terminal;

    TokenType rule_name;

    std::vector<std::vector<Token> > production;

    Node() { 
        terminal = 0;
    }
    Node(bool t, TokenType rn) {
        terminal = t;
        rule_name = rn;
    }
};

class Parser {
private:
    std::vector<Node> CFG;
    std::vector<Token> stream;
    int stream_pointer;

    void add_datatype();
    void add_terminals();
public:
    std::vector<std::vector<Node> > parse_tree;

    Parser();

    std::pair<bool, Node> match(Node);
    void parse(std::vector<Token>);
    
    ~Parser();
};
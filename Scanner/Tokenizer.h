#include "DFA.h"
#include "TokenType.h"

class Tokenizer {
private:
  DFA dfa;
public:
  Tokenizer();
  vector <Token> tokenize(); 
};
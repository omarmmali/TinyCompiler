#include "DFA.h"
#include "TokenType.h"

class Tokenizer {
private:
  DFA dfa;
  void add_symbols();
  void add_identifier();
  void add_integer();
  void add_double();
  void add_string();
public:
  Tokenizer();
  std::vector <Token> tokenize(std::string); 

};
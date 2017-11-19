#include "DFA.h"
#include "TokenType.h"

class Tokenizer {
private:
  DFA<char> dfa;
  void add_symbol();
  void add_identifier();
  void add_integer();
  void add_double();
  void add_string();
  void add_reserved_keywords();
  void add_comment();
public:
  Tokenizer();
  std::vector <Token> tokenize(std::string); 
};
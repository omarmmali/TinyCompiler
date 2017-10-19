#include "Tokenizer.h"

Tokenizer::Tokenizer() {
  int intermediate_number = 1;
  for(int i = 1; i <= 999; i++) {
    dfa.add_state(i, false);
  }
  //Implement DFAs
  // IDENTIFIER DFA
  dfa.add_state(TokenType::IDENTIFIER, true);
  for(char i = 'a'; i <= 'z'; i++) {
    dfa.add_transition(0,i,TokenType::IDENTIFIER);
    dfa.add_transition(TokenType::IDENTIFIER, i, TokenType::IDENTIFIER);
  }
  for(int i = 'A'; i<='Z'; i++) {
    dfa.add_transition(0,i,TokenType::IDENTIFIER);
    dfa.add_transition(TokenType::IDENTIFIER, i, TokenType::IDENTIFIER);
  }
  for(int i = '0'; i<='9'; i++) {
    dfa.add_transition(TokenType::IDENTIFIER, i, TokenType::IDENTIFIER);
  }
  // NUMBER DFA
  dfa.add_state(TokenType::NUMBER, true);
  for(int i = '0'; i<='9'; i++) {
    dfa.add_transition(0,i,TokenType::NUMBER);
    dfa.add_transition(TokenType::NUMBER, i, TokenType::NUMBER);
  }
  dfa.add_transition(TokenType::NUMBER, '.', TokenType::NUMBER);
  // STRING DFA
  dfa.add_state(TokenType::STRING, true);
  dfa.add_transition(0,'"',intermediate_number);
  for(char i = 'a'; i <= 'z'; i++) {
    dfa.add_transition(intermediate_number, i, intermediate_number + 1);
    dfa.add_transition(intermediate_number + 1, i, intermediate_number + 1);
  }
  for(int i = 'A'; i<='Z'; i++) {
    dfa.add_transition(intermediate_number, i, intermediate_number + 1);
    dfa.add_transition(intermediate_number + 1, i, intermediate_number + 1);
  }
  dfa.add_transition(intermediate_number + 1,'"',TokenType::STRING);
  // COMMENT DFA
  intermediate_number = 3;
  dfa.add_state(TokenType::COMMENT, true);
  dfa.add_transition(0, '/', intermediate_number);
  dfa.add_transition(intermediate_number, '*', intermediate_number + 1);
  for(char i = 'a'; i <= 'z'; i++) {
    dfa.add_transition(intermediate_number, i, intermediate_number + 1);
    dfa.add_transition(intermediate_number + 1, i, intermediate_number + 1);
  }
  for(int i = 'A'; i<='Z'; i++) {
    dfa.add_transition(intermediate_number, i, intermediate_number + 1);
    dfa.add_transition(intermediate_number + 1, i, intermediate_number + 1);
  }
  for(int i = '0'; i<='9'; i++) {
    dfa.add_transition(intermediate_number, i, intermediate_number + 1);
    dfa.add_transition(intermediate_number + 1, i, intermediate_number + 1);
  }
  dfa.add_transition(intermediate_number + 1, '*', intermediate_number + 2);
  dfa.add_transition(intermediate_number + 2, '/', TokenType::COMMENT);
  // RESERVED KEYWORDS DFA
  intermediate_number = 6;
  dfa.add_state(TokenType::RESERVED, true);
  for(int i = 0; i < 13; i++) {
    dfa.add_transition(0,CONSTANTS::RESERVED_WORDS[i][0], intermediate_number);
    for(int j = 1; j < CONSTANTS::RESERVED_WORDS[i].size() - 1; j++) {
      dfa.add_transition(intermediate_number + j, CONSTANTS::RESERVED_WORDS[i][j], intermediate_number + j + 1);
    }
    intermediate_number += CONSTANTS::RESERVED_WORDS[i].size();
    add_transition(intermediate_number, CONSTANTS::RESERVED_WORDS[i][CONSTANTS::RESERVED_WORDS[i].size()-1], TokenType::RESERVED);
  }
  // ARITHMETIC OPERATOR DFA
  dfa.add_state(TokenType::ARITHMETIC_OPERATOR, true);
  dfa.add_transition(0,'+',TokenType::ARITHMETIC_OPERATOR);
  dfa.add_transition(0,'-',TokenType::ARITHMETIC_OPERATOR);
  dfa.add_transition(0,'*',TokenType::ARITHMETIC_OPERATOR);
  dfa.add_transition(0,'/',TokenType::ARITHMETIC_OPERATOR);
  // FUNCTION NAME DFA
   dfa.add_state(TokenType::FUNCTION_NAME, true);
  for(char i = 'a'; i <= 'z'; i++) {
    dfa.add_transition(0,i,TokenType::FUNCTION_NAME);
    dfa.add_transition(TokenType::FUNCTION_NAME, i, TokenType::FUNCTION_NAME);
  }
  for(int i = 'A'; i<='Z'; i++) {
    dfa.add_transition(0,i,TokenType::FUNCTION_NAME);
    dfa.add_transition(TokenType::FUNCTION_NAME, i, TokenType::FUNCTION_NAME);
  }
  for(int i = '0'; i<='9'; i++) {
    dfa.add_transition(TokenType::FUNCTION_NAME, i, TokenType::FUNCTION_NAME);
  }
}

vector<Token> Tokenizer::tokenize(string in) {
  vector<Token> ret;
  string current_lexeme;
  dfa.reset();
  for(int i = 0; i < in.size() - 1; i++) {
    current_lexeme += in[i];
    dfa.insert(in[i]);
    char next = in[i+1];
    if(dfa.is_accepted() && !dfa.will_accept(next)) {
      Token tmp_token;
      tmp_token.lexeme = current_lexeme;
      tmp_token.token_type = (TokenType)dfa.get_current_state();
      ret.push_back(tmp_token);
      lexeme.clear();
      dfa.reset();
    }
  }
  return ret;
}
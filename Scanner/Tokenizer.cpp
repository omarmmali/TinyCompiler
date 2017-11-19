#include "Tokenizer.h"

void Tokenizer::add_symbols() {
    dfa.add_state(TokenType::PARAN_OPEN, true);
    dfa.add_state(TokenType::PARAN_CLOSE, true);
    
    dfa.add_state(TokenType::OPERATOR_PLUS, true);
    dfa.add_state(TokenType::OPERATOR_MINUS, true);
    dfa.add_state(TokenType::OPERATOR_TIMES, true);
    dfa.add_state(TokenType::OPERATOR_ASSIGNMENT, true);
    
    dfa.add_state(TokenType::WHITESPACE, true);
    
    dfa.add_state(TokenType::QUOTE_OPEN, false);
    dfa.add_state(TokenType::QUOTE_CLOSE, true);

    dfa.add_transition(0, '(', TokenType::PARAN_OPEN);
    dfa.add_transition(0, ')', TokenType::PARAN_CLOSE);
    dfa.add_transition(0, '+', TokenType::OPERATOR_PLUS);
    dfa.add_transition(0, '-', TokenType::OPERATOR_MINUS);
    dfa.add_transition(0, '*', TokenType::OPERATOR_TIMES);
    dfa.add_transition(0, '=', TokenType::OPERATOR_ASSIGNMENT);

    dfa.add_transition(0, ' ', TokenType::WHITESPACE);
    dfa.add_transition(TokenType::WHITESPACE, ' ', TokenType::WHITESPACE);
}

void Tokenizer::add_identifier() {
  dfa.add_state(TokenType::IDENTIFIER, true);

  for(char i = 'a'; i <= 'z'; i++) {
    dfa.add_transition(0, i, TokenType::IDENTIFIER);
    dfa.add_transition(0, std::toupper(i), TokenType::IDENTIFIER);
    dfa.add_transition(TokenType::IDENTIFIER, i, TokenType::IDENTIFIER);
    dfa.add_transition(TokenType::IDENTIFIER, std::toupper(i), TokenType::IDENTIFIER);
  }
}

void Tokenizer::add_integer() {
  dfa.add_state(TokenType::INTEGER, true);

  for(char i = '0'; i <= '9'; i++) {
    dfa.add_transition(0, i, TokenType::INTEGER);
    dfa.add_transition(TokenType::INTEGER, i, TokenType::INTEGER);
  }
}

void Tokenizer::add_double() {
  dfa.add_state(TokenType::DOUBLE, true);
  
  dfa.add_transition(TokenType::INTEGER, '.', TokenType::DOUBLE);

  for(char i = '0'; i <= '9'; i++) {
    dfa.add_transition(TokenType::DOUBLE, i, TokenType::DOUBLE);
  }
}

void Tokenizer::add_string() {
  dfa.add_state(TokenType::STRING, true);

  dfa.add_transition(0,'"', TokenType::QUOTE_OPEN);

  for(char i = 'a'; i <= 'z'; i++) {
    dfa.add_transition(TokenType::QUOTE_OPEN, i, TokenType::QUOTE_OPEN);
    dfa.add_transition(TokenType::QUOTE_OPEN, std::toupper(i), TokenType::QUOTE_OPEN);
  }
  for(char i = '0'; i <= '9'; i++) {
    dfa.add_transition(TokenType::QUOTE_OPEN, i, TokenType::QUOTE_OPEN);
  }
  
  dfa.add_transition(TokenType::QUOTE_OPEN, ' ', TokenType::QUOTE_OPEN);

  dfa.add_transition(TokenType::QUOTE_OPEN, '"', TokenType::STRING);
}

Tokenizer::Tokenizer() {
  dfa.add_state(0, false);
  add_symbols();
  add_identifier();
  add_integer();
  add_double();
  add_string();
}

std::vector<Token> Tokenizer::tokenize(std::string in) {
  std::vector<Token> ret;
  std::string current_lexeme;
  dfa.reset();
  in += '#';
  for(int i = 0; i < in.size() - 1; i++) {
    current_lexeme += in[i];
    dfa.insert(in[i]);
    char next = in[i+1];
    if(dfa.is_accepted() && !dfa.will_accept(next)) {
      Token tmp_token;
      tmp_token.lexeme = current_lexeme;
      tmp_token.token_type = (TokenType)dfa.get_current_state();
      ret.push_back(tmp_token);
      current_lexeme.clear();
      dfa.reset();
    }
  }
  if(ret.size() == 0) {
    ret.push_back(Token());
  }
  Token eof;
  eof.token_type = TokenType::END_OF_FILE;
  eof.lexeme = "EOF";
  ret.push_back(eof);
  return ret;
}
#include "Tokenizer.h"


void Tokenizer::add_symbol() {
    dfa.add_state(TokenType::PARAN_OPEN, true);
    dfa.add_state(TokenType::PARAN_CLOSE, true);
    
    dfa.add_state(TokenType::OPERATOR_PLUS, true);
    dfa.add_state(TokenType::OPERATOR_MINUS, true);
    dfa.add_state(TokenType::OPERATOR_TIMES, true);
    dfa.add_state(TokenType::OPERATOR_DIVISION, true);
    dfa.add_state(TokenType::OPERATOR_ASSIGNMENT, true);
    
    dfa.add_state(TokenType::SEMICOLON, true);
    dfa.add_state(TokenType::WHITESPACE, true);
    dfa.add_state(TokenType::COMMA, true);
    dfa.add_state(TokenType::COLON, false);
    dfa.add_state(TokenType::COMMENT_START, false);
    dfa.add_state(TokenType::COMMENT_END, false);


    dfa.add_state(TokenType::LOGIC_AND_OPERATOR, true);
    dfa.add_state(TokenType::LOGIC_OR_OPERATOR, true);
    dfa.add_state(TokenType::AND_OPERATOR, true);
    dfa.add_state(TokenType::OR_OPERATOR, true);

    dfa.add_state(TokenType::QUOTE_OPEN, false);
    dfa.add_state(TokenType::QUOTE_CLOSE, true);

    dfa.add_state(TokenType::EQUAL_OPERATOR, true);
    dfa.add_state(TokenType::LESS_THAN_OPERATOR, true);
    dfa.add_state(TokenType::GREATER_THAN_OPERATOR, true);
    dfa.add_state(TokenType::NOT_EQUAL_OPERATOR, true);

    dfa.add_transition(0, '(', TokenType::PARAN_OPEN);
    dfa.add_transition(0, ')', TokenType::PARAN_CLOSE);
    dfa.add_transition(0, '+', TokenType::OPERATOR_PLUS);
    dfa.add_transition(0, '-', TokenType::OPERATOR_MINUS);
    dfa.add_transition(0, '*', TokenType::OPERATOR_TIMES);


    dfa.add_transition(0, ':', TokenType::COLON);
    dfa.add_transition(TokenType::COLON, '=', TokenType::OPERATOR_ASSIGNMENT);
    
    
    dfa.add_transition(0, '=', TokenType::EQUAL_OPERATOR);
    dfa.add_transition(0, '<', TokenType::LESS_THAN_OPERATOR);
    dfa.add_transition(0, '>', TokenType::GREATER_THAN_OPERATOR);
    dfa.add_transition(TokenType::LESS_THAN_OPERATOR, '>', TokenType::NOT_EQUAL_OPERATOR);

    dfa.add_transition(0, '&', TokenType::AND_OPERATOR);
    dfa.add_transition(TokenType::AND_OPERATOR, '&', TokenType::LOGIC_AND_OPERATOR);
    dfa.add_transition(0, '|', TokenType::OR_OPERATOR);
    dfa.add_transition(TokenType::OR_OPERATOR, '|', TokenType::LOGIC_OR_OPERATOR);

    dfa.add_transition(0, ';', TokenType::SEMICOLON);
    dfa.add_transition(0, ',', TokenType::COMMA);

    dfa.add_transition(0, ' ', TokenType::WHITESPACE);
    dfa.add_transition(TokenType::WHITESPACE, ' ', TokenType::WHITESPACE);
}

void Tokenizer::add_identifier() {
  dfa.add_state(TokenType::IDENTIFIER, true);
  
  dfa.add_transition(0, '_', TokenType::IDENTIFIER);

  for(char i = 'a'; i <= 'z'; i++) {
    dfa.add_transition(0, i, TokenType::IDENTIFIER);
    dfa.add_transition(0, std::toupper(i), TokenType::IDENTIFIER);
    dfa.add_transition(TokenType::IDENTIFIER, i, TokenType::IDENTIFIER);
    dfa.add_transition(TokenType::IDENTIFIER, std::toupper(i), TokenType::IDENTIFIER);
  }
  for(char i = '0'; i <= '9'; i++) {
    dfa.add_transition(TokenType::IDENTIFIER, i, TokenType::IDENTIFIER);
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

void Tokenizer::add_comment() {
  dfa.add_state(TokenType::COMMENT, true);
  dfa.add_transition(0, '/', TokenType::OPERATOR_DIVISION);
  dfa.add_transition(TokenType::OPERATOR_DIVISION, '*', TokenType::COMMENT_START);

  for(char i = 'a'; i <= 'z'; i++) {
    dfa.add_transition(TokenType::COMMENT_START, i, TokenType::COMMENT_START);
    dfa.add_transition(TokenType::COMMENT_START, std::toupper(i), TokenType::COMMENT_START);
  }

  for(char i = '0'; i <= '9'; i++) {
    dfa.add_transition(TokenType::COMMENT_START, i, TokenType::COMMENT_START);
  }

  dfa.add_transition(TokenType::COMMENT_START, ' ', TokenType::COMMENT_START);
  dfa.add_transition(TokenType::COMMENT_START, '_', TokenType::COMMENT_START);

  dfa.add_transition(TokenType::COMMENT_START, '*', TokenType::COMMENT_END);
  dfa.add_transition(TokenType::COMMENT_END, '/', TokenType::COMMENT);
}

bool check_if_lexeme_is_reserved_keyword(std::string lexeme) {
  for(int i = 0; i < lexeme.size(); i++) {
    lexeme[i] = std::tolower(lexeme[i]);
  }
  for(int i = 0; i < 13; i++) {
    if(lexeme == CONSTANTS::RESERVED_WORDS[i]) {
      return true;
    }
  }
  return false;
}
Tokenizer::Tokenizer() {
  dfa.add_state(0, false);
  add_symbol();
  add_identifier();
  add_integer();
  add_double();
  add_string();
  add_comment();


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
    if((current_lexeme == "/" && next == '*') || (current_lexeme == "*" && next == '/')) {
      continue;
    }
    if(dfa.is_accepted() && !dfa.will_accept(next)) {
      Token tmp_token;
      tmp_token.lexeme = current_lexeme;
      if(check_if_lexeme_is_reserved_keyword(current_lexeme)) {
        tmp_token.token_type = TokenType::RESERVED_WORD;
      }
      else {
        tmp_token.token_type = (TokenType)dfa.get_current_state();
      }
      ret.push_back(tmp_token);
      current_lexeme.clear();
      dfa.reset();
    }
  }
  if(ret.size() == 0) {
    ret.push_back(Token());
  }
  Token eol;
  eol.token_type = TokenType::END_OF_LINE;
  eol.lexeme = "";
  ret.push_back(eol);
  return ret;
}

Tokenizer::~Tokenizer() {}
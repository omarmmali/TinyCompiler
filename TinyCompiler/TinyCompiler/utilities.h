#pragma once

#include "stdc++.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

namespace CONSTANTS {
  const int TOKEN_ID_START = 1;
  const std::string TOKEN_NAMES[] = {
  "INVALID_TOKEN",
  "INTEGER",
  "DOUBLE",
  "STRING",
  "COMMENT",
  "RESERVED_WORD",
  "IDENTIFIER",
  "FUNCTION_CALL",
  "TERM",
  "EXPRESSION",
  "STATEMENT",
  "STATEMENTS",
  "ASSIGNMENT_STATEMENT",
  "DATATYPE",
  "DECLARATION_STATEMENT",
  "WRITE_STATEMENT",
  "READ_STATEMENT",
  "RETURN_STATEMENT",
  "CONDITION_TERM",
  "CONDITIONAL_STATEMENT",
  "CONDITIONAL_OPERATOR",
  "IF_STATEMENT",
  "ELSE_IF_STATEMENT",
  "ELSE_STATEMENT",
  "REPEAT_STATEMENT",
  "FUNCTION_NAME",
  "PARAMETER_LIST",
  "FUNCTION_DECLARATION",
  "FUNCTION_BODY",
  "FUNCTION_STATEMENT",
  "MAIN_FUNCTION",
  "PROGRAM",
  "WHITESPACE",
  "PARAN_OPEN",
  "PARAN_CLOSE",
  "OPERATOR_PLUS",
  "OPERATOR_MINUS",
  "OPERATOR_TIMES",
  "OPERATOR_DIVISION",
  "OPERATOR_ASSIGNMENT",
  "QUOTE_OPEN",
  "QUOTE_CLOSE",
  "SEMICOLON",
  "COMMA",
  "COLON",
  "EQUAL_OPERATOR",
  "LESS_THAN_OPERATOR",
  "GREATER_THAN_OPERATOR",
  "NOT_EQUAL_OPERATOR",
  "LOGIC_AND_OPERATOR",
  "LOGIC_OR_OPERATOR",
  "AND_OPERATOR",
  "OR_OPERATOR",
  "FRONT_SLASH",
  "COMMENT_START",
  "COMMENT_END",
  "END_OF_LINE"
  };
  const std::string RESERVED_WORDS[] = {
    "int", "double", "string", "read", "write", "repeat", "until", "end",
    "if", "elseif", "else", "then", "return", "endl"
  };
};
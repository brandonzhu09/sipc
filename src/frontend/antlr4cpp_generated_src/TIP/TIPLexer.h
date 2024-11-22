
// Generated from TIP.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  TIPLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    MUL = 21, DIV = 22, MOD = 23, ADD = 24, SUB = 25, GT = 26, GTE = 27, 
    LT = 28, LTE = 29, EQ = 30, NE = 31, NUMBER = 32, KALLOC = 33, KINPUT = 34, 
    KWHILE = 35, KIF = 36, KELSE = 37, KVAR = 38, KRETURN = 39, KNULL = 40, 
    KOUTPUT = 41, KERROR = 42, KAND = 43, KOR = 44, KTRUE = 45, KFALSE = 46, 
    KFOR = 47, KPOLY = 48, IDENTIFIER = 49, WS = 50, BLOCKCOMMENT = 51, 
    COMMENT = 52
  };

  explicit TIPLexer(antlr4::CharStream *input);

  ~TIPLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};


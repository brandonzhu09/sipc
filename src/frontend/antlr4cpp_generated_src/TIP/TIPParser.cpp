
// Generated from TIP.g4 by ANTLR 4.13.1


#include "TIPVisitor.h"

#include "TIPParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct TIPParserStaticData final {
  TIPParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TIPParserStaticData(const TIPParserStaticData&) = delete;
  TIPParserStaticData(TIPParserStaticData&&) = delete;
  TIPParserStaticData& operator=(const TIPParserStaticData&) = delete;
  TIPParserStaticData& operator=(TIPParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tipParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
TIPParserStaticData *tipParserStaticData = nullptr;

void tipParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (tipParserStaticData != nullptr) {
    return;
  }
#else
  assert(tipParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TIPParserStaticData>(
    std::vector<std::string>{
      "program", "function", "declaration", "nameDeclaration", "expr", "recordExpr", 
      "fieldExpr", "statement", "assignStmt", "blockStmt", "whileStmt", 
      "ifStmt", "outputStmt", "errorStmt", "returnStmt", "forStmt", "forRangeStmt", 
      "incrementStmt", "decrementStmt"
    },
    std::vector<std::string>{
      "", "'('", "','", "')'", "'{'", "'}'", "';'", "'['", "']'", "'of'", 
      "'.'", "'not'", "'&'", "'#'", "'\\u003F'", "':'", "'='", "'..'", "'by'", 
      "'++'", "'--'", "'*'", "'/'", "'%'", "'+'", "'-'", "'>'", "'>='", 
      "'<'", "'<='", "'=='", "'!='", "", "'alloc'", "'input'", "'while'", 
      "'if'", "'else'", "'var'", "'return'", "'null'", "'output'", "'error'", 
      "'and'", "'or'", "'true'", "'false'", "'for'", "'poly'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "MUL", "DIV", "MOD", "ADD", "SUB", "GT", "GTE", "LT", 
      "LTE", "EQ", "NE", "NUMBER", "KALLOC", "KINPUT", "KWHILE", "KIF", 
      "KELSE", "KVAR", "KRETURN", "KNULL", "KOUTPUT", "KERROR", "KAND", 
      "KOR", "KTRUE", "KFALSE", "KFOR", "KPOLY", "IDENTIFIER", "WS", "BLOCKCOMMENT", 
      "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,52,282,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,4,0,40,8,0,11,0,12,0,41,
  	1,1,1,1,1,1,1,1,1,1,5,1,49,8,1,10,1,12,1,52,9,1,3,1,54,8,1,1,1,1,1,3,
  	1,58,8,1,1,1,1,1,5,1,62,8,1,10,1,12,1,65,9,1,1,1,5,1,68,8,1,10,1,12,1,
  	71,9,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,5,2,80,8,2,10,2,12,2,83,9,2,1,2,1,
  	2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,5,4,94,8,4,10,4,12,4,97,9,4,3,4,99,8,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,133,8,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,5,4,161,8,4,10,4,12,4,164,9,4,3,4,166,
  	8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,5,4,177,8,4,10,4,12,4,180,9,4,
  	1,5,1,5,1,5,1,5,5,5,186,8,5,10,5,12,5,189,9,5,3,5,191,8,5,1,5,1,5,1,6,
  	1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,209,8,7,1,8,1,
  	8,1,8,1,8,1,8,1,9,1,9,5,9,218,8,9,10,9,12,9,221,9,9,1,9,1,9,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,3,11,238,8,11,
  	1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,3,16,269,8,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,18,1,18,1,18,
  	1,18,1,18,0,1,8,19,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	0,5,1,0,21,23,1,0,24,25,1,0,26,29,1,0,30,31,1,0,43,44,312,0,39,1,0,0,
  	0,2,43,1,0,0,0,4,75,1,0,0,0,6,86,1,0,0,0,8,132,1,0,0,0,10,181,1,0,0,0,
  	12,194,1,0,0,0,14,208,1,0,0,0,16,210,1,0,0,0,18,215,1,0,0,0,20,224,1,
  	0,0,0,22,230,1,0,0,0,24,239,1,0,0,0,26,243,1,0,0,0,28,247,1,0,0,0,30,
  	251,1,0,0,0,32,259,1,0,0,0,34,273,1,0,0,0,36,277,1,0,0,0,38,40,3,2,1,
  	0,39,38,1,0,0,0,40,41,1,0,0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,1,1,0,0,
  	0,43,44,3,6,3,0,44,53,5,1,0,0,45,50,3,6,3,0,46,47,5,2,0,0,47,49,3,6,3,
  	0,48,46,1,0,0,0,49,52,1,0,0,0,50,48,1,0,0,0,50,51,1,0,0,0,51,54,1,0,0,
  	0,52,50,1,0,0,0,53,45,1,0,0,0,53,54,1,0,0,0,54,55,1,0,0,0,55,57,5,3,0,
  	0,56,58,5,48,0,0,57,56,1,0,0,0,57,58,1,0,0,0,58,59,1,0,0,0,59,63,5,4,
  	0,0,60,62,3,4,2,0,61,60,1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,64,1,0,
  	0,0,64,69,1,0,0,0,65,63,1,0,0,0,66,68,3,14,7,0,67,66,1,0,0,0,68,71,1,
  	0,0,0,69,67,1,0,0,0,69,70,1,0,0,0,70,72,1,0,0,0,71,69,1,0,0,0,72,73,3,
  	28,14,0,73,74,5,5,0,0,74,3,1,0,0,0,75,76,5,38,0,0,76,81,3,6,3,0,77,78,
  	5,2,0,0,78,80,3,6,3,0,79,77,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,81,82,
  	1,0,0,0,82,84,1,0,0,0,83,81,1,0,0,0,84,85,5,6,0,0,85,5,1,0,0,0,86,87,
  	5,49,0,0,87,7,1,0,0,0,88,89,6,4,-1,0,89,98,5,7,0,0,90,95,3,8,4,0,91,92,
  	5,2,0,0,92,94,3,8,4,0,93,91,1,0,0,0,94,97,1,0,0,0,95,93,1,0,0,0,95,96,
  	1,0,0,0,96,99,1,0,0,0,97,95,1,0,0,0,98,90,1,0,0,0,98,99,1,0,0,0,99,100,
  	1,0,0,0,100,133,5,8,0,0,101,102,5,7,0,0,102,103,3,8,4,0,103,104,5,9,0,
  	0,104,105,3,8,4,0,105,106,5,8,0,0,106,133,1,0,0,0,107,108,5,25,0,0,108,
  	133,3,8,4,21,109,110,5,11,0,0,110,133,3,8,4,20,111,112,5,21,0,0,112,133,
  	3,8,4,19,113,114,5,25,0,0,114,133,5,32,0,0,115,116,5,12,0,0,116,133,3,
  	8,4,17,117,118,5,13,0,0,118,133,3,8,4,16,119,133,5,49,0,0,120,133,5,32,
  	0,0,121,133,5,45,0,0,122,133,5,46,0,0,123,133,5,34,0,0,124,125,5,33,0,
  	0,125,133,3,8,4,4,126,133,5,40,0,0,127,133,3,10,5,0,128,129,5,1,0,0,129,
  	130,3,8,4,0,130,131,5,3,0,0,131,133,1,0,0,0,132,88,1,0,0,0,132,101,1,
  	0,0,0,132,107,1,0,0,0,132,109,1,0,0,0,132,111,1,0,0,0,132,113,1,0,0,0,
  	132,115,1,0,0,0,132,117,1,0,0,0,132,119,1,0,0,0,132,120,1,0,0,0,132,121,
  	1,0,0,0,132,122,1,0,0,0,132,123,1,0,0,0,132,124,1,0,0,0,132,126,1,0,0,
  	0,132,127,1,0,0,0,132,128,1,0,0,0,133,178,1,0,0,0,134,135,10,15,0,0,135,
  	136,7,0,0,0,136,177,3,8,4,16,137,138,10,14,0,0,138,139,7,1,0,0,139,177,
  	3,8,4,15,140,141,10,13,0,0,141,142,7,2,0,0,142,177,3,8,4,14,143,144,10,
  	12,0,0,144,145,7,3,0,0,145,177,3,8,4,13,146,147,10,11,0,0,147,148,7,4,
  	0,0,148,177,3,8,4,12,149,150,10,10,0,0,150,151,5,14,0,0,151,152,3,8,4,
  	0,152,153,5,15,0,0,153,154,3,8,4,11,154,177,1,0,0,0,155,156,10,26,0,0,
  	156,165,5,1,0,0,157,162,3,8,4,0,158,159,5,2,0,0,159,161,3,8,4,0,160,158,
  	1,0,0,0,161,164,1,0,0,0,162,160,1,0,0,0,162,163,1,0,0,0,163,166,1,0,0,
  	0,164,162,1,0,0,0,165,157,1,0,0,0,165,166,1,0,0,0,166,167,1,0,0,0,167,
  	177,5,3,0,0,168,169,10,23,0,0,169,170,5,7,0,0,170,171,3,8,4,0,171,172,
  	5,8,0,0,172,177,1,0,0,0,173,174,10,22,0,0,174,175,5,10,0,0,175,177,5,
  	49,0,0,176,134,1,0,0,0,176,137,1,0,0,0,176,140,1,0,0,0,176,143,1,0,0,
  	0,176,146,1,0,0,0,176,149,1,0,0,0,176,155,1,0,0,0,176,168,1,0,0,0,176,
  	173,1,0,0,0,177,180,1,0,0,0,178,176,1,0,0,0,178,179,1,0,0,0,179,9,1,0,
  	0,0,180,178,1,0,0,0,181,190,5,4,0,0,182,187,3,12,6,0,183,184,5,2,0,0,
  	184,186,3,12,6,0,185,183,1,0,0,0,186,189,1,0,0,0,187,185,1,0,0,0,187,
  	188,1,0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,190,182,1,0,0,0,190,191,1,
  	0,0,0,191,192,1,0,0,0,192,193,5,5,0,0,193,11,1,0,0,0,194,195,5,49,0,0,
  	195,196,5,15,0,0,196,197,3,8,4,0,197,13,1,0,0,0,198,209,3,18,9,0,199,
  	209,3,16,8,0,200,209,3,34,17,0,201,209,3,36,18,0,202,209,3,20,10,0,203,
  	209,3,30,15,0,204,209,3,32,16,0,205,209,3,22,11,0,206,209,3,24,12,0,207,
  	209,3,26,13,0,208,198,1,0,0,0,208,199,1,0,0,0,208,200,1,0,0,0,208,201,
  	1,0,0,0,208,202,1,0,0,0,208,203,1,0,0,0,208,204,1,0,0,0,208,205,1,0,0,
  	0,208,206,1,0,0,0,208,207,1,0,0,0,209,15,1,0,0,0,210,211,3,8,4,0,211,
  	212,5,16,0,0,212,213,3,8,4,0,213,214,5,6,0,0,214,17,1,0,0,0,215,219,5,
  	4,0,0,216,218,3,14,7,0,217,216,1,0,0,0,218,221,1,0,0,0,219,217,1,0,0,
  	0,219,220,1,0,0,0,220,222,1,0,0,0,221,219,1,0,0,0,222,223,5,5,0,0,223,
  	19,1,0,0,0,224,225,5,35,0,0,225,226,5,1,0,0,226,227,3,8,4,0,227,228,5,
  	3,0,0,228,229,3,14,7,0,229,21,1,0,0,0,230,231,5,36,0,0,231,232,5,1,0,
  	0,232,233,3,8,4,0,233,234,5,3,0,0,234,237,3,14,7,0,235,236,5,37,0,0,236,
  	238,3,14,7,0,237,235,1,0,0,0,237,238,1,0,0,0,238,23,1,0,0,0,239,240,5,
  	41,0,0,240,241,3,8,4,0,241,242,5,6,0,0,242,25,1,0,0,0,243,244,5,42,0,
  	0,244,245,3,8,4,0,245,246,5,6,0,0,246,27,1,0,0,0,247,248,5,39,0,0,248,
  	249,3,8,4,0,249,250,5,6,0,0,250,29,1,0,0,0,251,252,5,47,0,0,252,253,5,
  	1,0,0,253,254,3,8,4,0,254,255,5,15,0,0,255,256,3,8,4,0,256,257,5,3,0,
  	0,257,258,3,14,7,0,258,31,1,0,0,0,259,260,5,47,0,0,260,261,5,1,0,0,261,
  	262,3,8,4,0,262,263,5,15,0,0,263,264,3,8,4,0,264,265,5,17,0,0,265,268,
  	3,8,4,0,266,267,5,18,0,0,267,269,3,8,4,0,268,266,1,0,0,0,268,269,1,0,
  	0,0,269,270,1,0,0,0,270,271,5,3,0,0,271,272,3,14,7,0,272,33,1,0,0,0,273,
  	274,3,8,4,0,274,275,5,19,0,0,275,276,5,6,0,0,276,35,1,0,0,0,277,278,3,
  	8,4,0,278,279,5,20,0,0,279,280,5,6,0,0,280,37,1,0,0,0,20,41,50,53,57,
  	63,69,81,95,98,132,162,165,176,178,187,190,208,219,237,268
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tipParserStaticData = staticData.release();
}

}

TIPParser::TIPParser(TokenStream *input) : TIPParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

TIPParser::TIPParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  TIPParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *tipParserStaticData->atn, tipParserStaticData->decisionToDFA, tipParserStaticData->sharedContextCache, options);
}

TIPParser::~TIPParser() {
  delete _interpreter;
}

const atn::ATN& TIPParser::getATN() const {
  return *tipParserStaticData->atn;
}

std::string TIPParser::getGrammarFileName() const {
  return "TIP.g4";
}

const std::vector<std::string>& TIPParser::getRuleNames() const {
  return tipParserStaticData->ruleNames;
}

const dfa::Vocabulary& TIPParser::getVocabulary() const {
  return tipParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TIPParser::getSerializedATN() const {
  return tipParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

TIPParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TIPParser::FunctionContext *> TIPParser::ProgramContext::function() {
  return getRuleContexts<TIPParser::FunctionContext>();
}

TIPParser::FunctionContext* TIPParser::ProgramContext::function(size_t i) {
  return getRuleContext<TIPParser::FunctionContext>(i);
}


size_t TIPParser::ProgramContext::getRuleIndex() const {
  return TIPParser::RuleProgram;
}


std::any TIPParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::ProgramContext* TIPParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, TIPParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(39); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(38);
      function();
      setState(41); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TIPParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

TIPParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TIPParser::NameDeclarationContext *> TIPParser::FunctionContext::nameDeclaration() {
  return getRuleContexts<TIPParser::NameDeclarationContext>();
}

TIPParser::NameDeclarationContext* TIPParser::FunctionContext::nameDeclaration(size_t i) {
  return getRuleContext<TIPParser::NameDeclarationContext>(i);
}

TIPParser::ReturnStmtContext* TIPParser::FunctionContext::returnStmt() {
  return getRuleContext<TIPParser::ReturnStmtContext>(0);
}

tree::TerminalNode* TIPParser::FunctionContext::KPOLY() {
  return getToken(TIPParser::KPOLY, 0);
}

std::vector<TIPParser::DeclarationContext *> TIPParser::FunctionContext::declaration() {
  return getRuleContexts<TIPParser::DeclarationContext>();
}

TIPParser::DeclarationContext* TIPParser::FunctionContext::declaration(size_t i) {
  return getRuleContext<TIPParser::DeclarationContext>(i);
}

std::vector<TIPParser::StatementContext *> TIPParser::FunctionContext::statement() {
  return getRuleContexts<TIPParser::StatementContext>();
}

TIPParser::StatementContext* TIPParser::FunctionContext::statement(size_t i) {
  return getRuleContext<TIPParser::StatementContext>(i);
}


size_t TIPParser::FunctionContext::getRuleIndex() const {
  return TIPParser::RuleFunction;
}


std::any TIPParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::FunctionContext* TIPParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, TIPParser::RuleFunction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    nameDeclaration();
    setState(44);
    match(TIPParser::T__0);
    setState(53);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TIPParser::IDENTIFIER) {
      setState(45);
      nameDeclaration();
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TIPParser::T__1) {
        setState(46);
        match(TIPParser::T__1);
        setState(47);
        nameDeclaration();
        setState(52);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(55);
    match(TIPParser::T__2);
    setState(57);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TIPParser::KPOLY) {
      setState(56);
      match(TIPParser::KPOLY);
    }
    setState(59);
    match(TIPParser::T__3);

    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TIPParser::KVAR) {
      setState(60);
      declaration();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 817070319089810) != 0)) {
      setState(66);
      statement();
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    returnStmt();
    setState(73);
    match(TIPParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

TIPParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::DeclarationContext::KVAR() {
  return getToken(TIPParser::KVAR, 0);
}

std::vector<TIPParser::NameDeclarationContext *> TIPParser::DeclarationContext::nameDeclaration() {
  return getRuleContexts<TIPParser::NameDeclarationContext>();
}

TIPParser::NameDeclarationContext* TIPParser::DeclarationContext::nameDeclaration(size_t i) {
  return getRuleContext<TIPParser::NameDeclarationContext>(i);
}


size_t TIPParser::DeclarationContext::getRuleIndex() const {
  return TIPParser::RuleDeclaration;
}


std::any TIPParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::DeclarationContext* TIPParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, TIPParser::RuleDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(TIPParser::KVAR);
    setState(76);
    nameDeclaration();
    setState(81);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TIPParser::T__1) {
      setState(77);
      match(TIPParser::T__1);
      setState(78);
      nameDeclaration();
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(84);
    match(TIPParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameDeclarationContext ------------------------------------------------------------------

TIPParser::NameDeclarationContext::NameDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::NameDeclarationContext::IDENTIFIER() {
  return getToken(TIPParser::IDENTIFIER, 0);
}


size_t TIPParser::NameDeclarationContext::getRuleIndex() const {
  return TIPParser::RuleNameDeclaration;
}


std::any TIPParser::NameDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitNameDeclaration(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::NameDeclarationContext* TIPParser::nameDeclaration() {
  NameDeclarationContext *_localctx = _tracker.createInstance<NameDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, TIPParser::RuleNameDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(TIPParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

TIPParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TIPParser::ExprContext::getRuleIndex() const {
  return TIPParser::RuleExpr;
}

void TIPParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayOfConstructorContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::ArrayOfConstructorContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::ArrayOfConstructorContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

TIPParser::ArrayOfConstructorContext::ArrayOfConstructorContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::ArrayOfConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitArrayOfConstructor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayRefExprContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::ArrayRefExprContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::ArrayRefExprContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

TIPParser::ArrayRefExprContext::ArrayRefExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::ArrayRefExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitArrayRefExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayPrefixLengthContext ------------------------------------------------------------------

TIPParser::ExprContext* TIPParser::ArrayPrefixLengthContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

TIPParser::ArrayPrefixLengthContext::ArrayPrefixLengthContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::ArrayPrefixLengthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitArrayPrefixLength(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::NullExprContext::KNULL() {
  return getToken(TIPParser::KNULL, 0);
}

TIPParser::NullExprContext::NullExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::NullExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitNullExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::TrueExprContext::KTRUE() {
  return getToken(TIPParser::KTRUE, 0);
}

TIPParser::TrueExprContext::TrueExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::TrueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitTrueExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AllocExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::AllocExprContext::KALLOC() {
  return getToken(TIPParser::KALLOC, 0);
}

TIPParser::ExprContext* TIPParser::AllocExprContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

TIPParser::AllocExprContext::AllocExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::AllocExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitAllocExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExprContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::AdditiveExprContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::AdditiveExprContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

tree::TerminalNode* TIPParser::AdditiveExprContext::ADD() {
  return getToken(TIPParser::ADD, 0);
}

tree::TerminalNode* TIPParser::AdditiveExprContext::SUB() {
  return getToken(TIPParser::SUB, 0);
}

TIPParser::AdditiveExprContext::AdditiveExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::AdditiveExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeRefExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::DeRefExprContext::MUL() {
  return getToken(TIPParser::MUL, 0);
}

TIPParser::ExprContext* TIPParser::DeRefExprContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

TIPParser::DeRefExprContext::DeRefExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::DeRefExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitDeRefExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

TIPParser::ExprContext* TIPParser::ParenExprContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

TIPParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TernaryExprContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::TernaryExprContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::TernaryExprContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

TIPParser::TernaryExprContext::TernaryExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::TernaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitTernaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FalseExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::FalseExprContext::KFALSE() {
  return getToken(TIPParser::KFALSE, 0);
}

TIPParser::FalseExprContext::FalseExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::FalseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitFalseExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunAppExprContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::FunAppExprContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::FunAppExprContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

TIPParser::FunAppExprContext::FunAppExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::FunAppExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitFunAppExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AccessExprContext ------------------------------------------------------------------

TIPParser::ExprContext* TIPParser::AccessExprContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

tree::TerminalNode* TIPParser::AccessExprContext::IDENTIFIER() {
  return getToken(TIPParser::IDENTIFIER, 0);
}

TIPParser::AccessExprContext::AccessExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::AccessExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitAccessExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RecordRuleContext ------------------------------------------------------------------

TIPParser::RecordExprContext* TIPParser::RecordRuleContext::recordExpr() {
  return getRuleContext<TIPParser::RecordExprContext>(0);
}

TIPParser::RecordRuleContext::RecordRuleContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::RecordRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitRecordRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegNumberContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::NegNumberContext::SUB() {
  return getToken(TIPParser::SUB, 0);
}

tree::TerminalNode* TIPParser::NegNumberContext::NUMBER() {
  return getToken(TIPParser::NUMBER, 0);
}

TIPParser::NegNumberContext::NegNumberContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::NegNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitNegNumber(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InputExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::InputExprContext::KINPUT() {
  return getToken(TIPParser::KINPUT, 0);
}

TIPParser::InputExprContext::InputExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::InputExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitInputExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalExprContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::RelationalExprContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::RelationalExprContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

tree::TerminalNode* TIPParser::RelationalExprContext::GT() {
  return getToken(TIPParser::GT, 0);
}

tree::TerminalNode* TIPParser::RelationalExprContext::GTE() {
  return getToken(TIPParser::GTE, 0);
}

tree::TerminalNode* TIPParser::RelationalExprContext::LT() {
  return getToken(TIPParser::LT, 0);
}

tree::TerminalNode* TIPParser::RelationalExprContext::LTE() {
  return getToken(TIPParser::LTE, 0);
}

TIPParser::RelationalExprContext::RelationalExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::RelationalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitRelationalExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::NumExprContext::NUMBER() {
  return getToken(TIPParser::NUMBER, 0);
}

TIPParser::NumExprContext::NumExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::NumExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitNumExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::VarExprContext::IDENTIFIER() {
  return getToken(TIPParser::IDENTIFIER, 0);
}

TIPParser::VarExprContext::VarExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::VarExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitVarExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

TIPParser::ExprContext* TIPParser::NotExprContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

TIPParser::NotExprContext::NotExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayConstructorContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::ArrayConstructorContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::ArrayConstructorContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

TIPParser::ArrayConstructorContext::ArrayConstructorContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::ArrayConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitArrayConstructor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegExprContext ------------------------------------------------------------------

tree::TerminalNode* TIPParser::NegExprContext::SUB() {
  return getToken(TIPParser::SUB, 0);
}

TIPParser::ExprContext* TIPParser::NegExprContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

TIPParser::NegExprContext::NegExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::NegExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitNegExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RefExprContext ------------------------------------------------------------------

TIPParser::ExprContext* TIPParser::RefExprContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

TIPParser::RefExprContext::RefExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::RefExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitRefExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndOrExprContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::AndOrExprContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::AndOrExprContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

tree::TerminalNode* TIPParser::AndOrExprContext::KAND() {
  return getToken(TIPParser::KAND, 0);
}

tree::TerminalNode* TIPParser::AndOrExprContext::KOR() {
  return getToken(TIPParser::KOR, 0);
}

TIPParser::AndOrExprContext::AndOrExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::AndOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitAndOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicativeExprContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::MultiplicativeExprContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::MultiplicativeExprContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

tree::TerminalNode* TIPParser::MultiplicativeExprContext::MUL() {
  return getToken(TIPParser::MUL, 0);
}

tree::TerminalNode* TIPParser::MultiplicativeExprContext::DIV() {
  return getToken(TIPParser::DIV, 0);
}

tree::TerminalNode* TIPParser::MultiplicativeExprContext::MOD() {
  return getToken(TIPParser::MOD, 0);
}

TIPParser::MultiplicativeExprContext::MultiplicativeExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::MultiplicativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityExprContext ------------------------------------------------------------------

std::vector<TIPParser::ExprContext *> TIPParser::EqualityExprContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::EqualityExprContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

tree::TerminalNode* TIPParser::EqualityExprContext::EQ() {
  return getToken(TIPParser::EQ, 0);
}

tree::TerminalNode* TIPParser::EqualityExprContext::NE() {
  return getToken(TIPParser::NE, 0);
}

TIPParser::EqualityExprContext::EqualityExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TIPParser::EqualityExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitEqualityExpr(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::ExprContext* TIPParser::expr() {
   return expr(0);
}

TIPParser::ExprContext* TIPParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TIPParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  TIPParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, TIPParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ArrayConstructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(89);
      match(TIPParser::T__6);
      setState(98);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 669632681752722) != 0)) {
        setState(90);
        expr(0);
        setState(95);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TIPParser::T__1) {
          setState(91);
          match(TIPParser::T__1);
          setState(92);
          expr(0);
          setState(97);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(100);
      match(TIPParser::T__7);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ArrayOfConstructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(101);
      match(TIPParser::T__6);
      setState(102);
      expr(0);
      setState(103);
      match(TIPParser::T__8);
      setState(104);
      expr(0);
      setState(105);
      match(TIPParser::T__7);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NegExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(107);
      match(TIPParser::SUB);
      setState(108);
      expr(21);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(109);
      match(TIPParser::T__10);
      setState(110);
      expr(20);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<DeRefExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(111);
      match(TIPParser::MUL);
      setState(112);
      expr(19);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NegNumberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(113);
      match(TIPParser::SUB);
      setState(114);
      match(TIPParser::NUMBER);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<RefExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(115);
      match(TIPParser::T__11);
      setState(116);
      expr(17);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ArrayPrefixLengthContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(117);
      match(TIPParser::T__12);
      setState(118);
      expr(16);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<VarExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(119);
      match(TIPParser::IDENTIFIER);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<NumExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(120);
      match(TIPParser::NUMBER);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<TrueExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(121);
      match(TIPParser::KTRUE);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<FalseExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(122);
      match(TIPParser::KFALSE);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<InputExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(123);
      match(TIPParser::KINPUT);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<AllocExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(124);
      match(TIPParser::KALLOC);
      setState(125);
      expr(4);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<NullExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(126);
      match(TIPParser::KNULL);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<RecordRuleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(127);
      recordExpr();
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(128);
      match(TIPParser::T__0);
      setState(129);
      expr(0);
      setState(130);
      match(TIPParser::T__2);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(178);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(176);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultiplicativeExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(134);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(135);
          antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 14680064) != 0))) {
            antlrcpp::downCast<MultiplicativeExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(136);
          expr(16);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AdditiveExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(137);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(138);
          antlrcpp::downCast<AdditiveExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TIPParser::ADD

          || _la == TIPParser::SUB)) {
            antlrcpp::downCast<AdditiveExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(139);
          expr(15);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(140);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(141);
          antlrcpp::downCast<RelationalExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1006632960) != 0))) {
            antlrcpp::downCast<RelationalExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(142);
          expr(14);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqualityExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(143);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(144);
          antlrcpp::downCast<EqualityExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TIPParser::EQ

          || _la == TIPParser::NE)) {
            antlrcpp::downCast<EqualityExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(145);
          expr(13);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AndOrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(146);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(147);
          antlrcpp::downCast<AndOrExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == TIPParser::KAND

          || _la == TIPParser::KOR)) {
            antlrcpp::downCast<AndOrExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(148);
          expr(12);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<TernaryExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(149);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(150);
          match(TIPParser::T__13);
          setState(151);
          expr(0);
          setState(152);
          match(TIPParser::T__14);
          setState(153);
          expr(11);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<FunAppExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(155);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(156);
          match(TIPParser::T__0);
          setState(165);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 669632681752722) != 0)) {
            setState(157);
            expr(0);
            setState(162);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == TIPParser::T__1) {
              setState(158);
              match(TIPParser::T__1);
              setState(159);
              expr(0);
              setState(164);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
          }
          setState(167);
          match(TIPParser::T__2);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<ArrayRefExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(168);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(169);
          match(TIPParser::T__6);
          setState(170);
          expr(0);
          setState(171);
          match(TIPParser::T__7);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<AccessExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(173);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(174);
          match(TIPParser::T__9);
          setState(175);
          match(TIPParser::IDENTIFIER);
          break;
        }

        default:
          break;
        } 
      }
      setState(180);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RecordExprContext ------------------------------------------------------------------

TIPParser::RecordExprContext::RecordExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TIPParser::FieldExprContext *> TIPParser::RecordExprContext::fieldExpr() {
  return getRuleContexts<TIPParser::FieldExprContext>();
}

TIPParser::FieldExprContext* TIPParser::RecordExprContext::fieldExpr(size_t i) {
  return getRuleContext<TIPParser::FieldExprContext>(i);
}


size_t TIPParser::RecordExprContext::getRuleIndex() const {
  return TIPParser::RuleRecordExpr;
}


std::any TIPParser::RecordExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitRecordExpr(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::RecordExprContext* TIPParser::recordExpr() {
  RecordExprContext *_localctx = _tracker.createInstance<RecordExprContext>(_ctx, getState());
  enterRule(_localctx, 10, TIPParser::RuleRecordExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(TIPParser::T__3);
    setState(190);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TIPParser::IDENTIFIER) {
      setState(182);
      fieldExpr();
      setState(187);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TIPParser::T__1) {
        setState(183);
        match(TIPParser::T__1);
        setState(184);
        fieldExpr();
        setState(189);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(192);
    match(TIPParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldExprContext ------------------------------------------------------------------

TIPParser::FieldExprContext::FieldExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::FieldExprContext::IDENTIFIER() {
  return getToken(TIPParser::IDENTIFIER, 0);
}

TIPParser::ExprContext* TIPParser::FieldExprContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}


size_t TIPParser::FieldExprContext::getRuleIndex() const {
  return TIPParser::RuleFieldExpr;
}


std::any TIPParser::FieldExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitFieldExpr(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::FieldExprContext* TIPParser::fieldExpr() {
  FieldExprContext *_localctx = _tracker.createInstance<FieldExprContext>(_ctx, getState());
  enterRule(_localctx, 12, TIPParser::RuleFieldExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    match(TIPParser::IDENTIFIER);
    setState(195);
    match(TIPParser::T__14);
    setState(196);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

TIPParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TIPParser::BlockStmtContext* TIPParser::StatementContext::blockStmt() {
  return getRuleContext<TIPParser::BlockStmtContext>(0);
}

TIPParser::AssignStmtContext* TIPParser::StatementContext::assignStmt() {
  return getRuleContext<TIPParser::AssignStmtContext>(0);
}

TIPParser::IncrementStmtContext* TIPParser::StatementContext::incrementStmt() {
  return getRuleContext<TIPParser::IncrementStmtContext>(0);
}

TIPParser::DecrementStmtContext* TIPParser::StatementContext::decrementStmt() {
  return getRuleContext<TIPParser::DecrementStmtContext>(0);
}

TIPParser::WhileStmtContext* TIPParser::StatementContext::whileStmt() {
  return getRuleContext<TIPParser::WhileStmtContext>(0);
}

TIPParser::ForStmtContext* TIPParser::StatementContext::forStmt() {
  return getRuleContext<TIPParser::ForStmtContext>(0);
}

TIPParser::ForRangeStmtContext* TIPParser::StatementContext::forRangeStmt() {
  return getRuleContext<TIPParser::ForRangeStmtContext>(0);
}

TIPParser::IfStmtContext* TIPParser::StatementContext::ifStmt() {
  return getRuleContext<TIPParser::IfStmtContext>(0);
}

TIPParser::OutputStmtContext* TIPParser::StatementContext::outputStmt() {
  return getRuleContext<TIPParser::OutputStmtContext>(0);
}

TIPParser::ErrorStmtContext* TIPParser::StatementContext::errorStmt() {
  return getRuleContext<TIPParser::ErrorStmtContext>(0);
}


size_t TIPParser::StatementContext::getRuleIndex() const {
  return TIPParser::RuleStatement;
}


std::any TIPParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::StatementContext* TIPParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 14, TIPParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(198);
      blockStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(199);
      assignStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(200);
      incrementStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(201);
      decrementStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(202);
      whileStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(203);
      forStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(204);
      forRangeStmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(205);
      ifStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(206);
      outputStmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(207);
      errorStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignStmtContext ------------------------------------------------------------------

TIPParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TIPParser::ExprContext *> TIPParser::AssignStmtContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::AssignStmtContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}


size_t TIPParser::AssignStmtContext::getRuleIndex() const {
  return TIPParser::RuleAssignStmt;
}


std::any TIPParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::AssignStmtContext* TIPParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 16, TIPParser::RuleAssignStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    expr(0);
    setState(211);
    match(TIPParser::T__15);
    setState(212);
    expr(0);
    setState(213);
    match(TIPParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockStmtContext ------------------------------------------------------------------

TIPParser::BlockStmtContext::BlockStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TIPParser::StatementContext *> TIPParser::BlockStmtContext::statement() {
  return getRuleContexts<TIPParser::StatementContext>();
}

TIPParser::StatementContext* TIPParser::BlockStmtContext::statement(size_t i) {
  return getRuleContext<TIPParser::StatementContext>(i);
}


size_t TIPParser::BlockStmtContext::getRuleIndex() const {
  return TIPParser::RuleBlockStmt;
}


std::any TIPParser::BlockStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitBlockStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::BlockStmtContext* TIPParser::blockStmt() {
  BlockStmtContext *_localctx = _tracker.createInstance<BlockStmtContext>(_ctx, getState());
  enterRule(_localctx, 18, TIPParser::RuleBlockStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(TIPParser::T__3);

    setState(219);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 817070319089810) != 0)) {
      setState(216);
      statement();
      setState(221);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(222);
    match(TIPParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

TIPParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::WhileStmtContext::KWHILE() {
  return getToken(TIPParser::KWHILE, 0);
}

TIPParser::ExprContext* TIPParser::WhileStmtContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

TIPParser::StatementContext* TIPParser::WhileStmtContext::statement() {
  return getRuleContext<TIPParser::StatementContext>(0);
}


size_t TIPParser::WhileStmtContext::getRuleIndex() const {
  return TIPParser::RuleWhileStmt;
}


std::any TIPParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::WhileStmtContext* TIPParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, TIPParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    match(TIPParser::KWHILE);
    setState(225);
    match(TIPParser::T__0);
    setState(226);
    expr(0);
    setState(227);
    match(TIPParser::T__2);
    setState(228);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

TIPParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::IfStmtContext::KIF() {
  return getToken(TIPParser::KIF, 0);
}

TIPParser::ExprContext* TIPParser::IfStmtContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}

std::vector<TIPParser::StatementContext *> TIPParser::IfStmtContext::statement() {
  return getRuleContexts<TIPParser::StatementContext>();
}

TIPParser::StatementContext* TIPParser::IfStmtContext::statement(size_t i) {
  return getRuleContext<TIPParser::StatementContext>(i);
}

tree::TerminalNode* TIPParser::IfStmtContext::KELSE() {
  return getToken(TIPParser::KELSE, 0);
}


size_t TIPParser::IfStmtContext::getRuleIndex() const {
  return TIPParser::RuleIfStmt;
}


std::any TIPParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::IfStmtContext* TIPParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 22, TIPParser::RuleIfStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(TIPParser::KIF);
    setState(231);
    match(TIPParser::T__0);
    setState(232);
    expr(0);
    setState(233);
    match(TIPParser::T__2);
    setState(234);
    statement();
    setState(237);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(235);
      match(TIPParser::KELSE);
      setState(236);
      statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutputStmtContext ------------------------------------------------------------------

TIPParser::OutputStmtContext::OutputStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::OutputStmtContext::KOUTPUT() {
  return getToken(TIPParser::KOUTPUT, 0);
}

TIPParser::ExprContext* TIPParser::OutputStmtContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}


size_t TIPParser::OutputStmtContext::getRuleIndex() const {
  return TIPParser::RuleOutputStmt;
}


std::any TIPParser::OutputStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitOutputStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::OutputStmtContext* TIPParser::outputStmt() {
  OutputStmtContext *_localctx = _tracker.createInstance<OutputStmtContext>(_ctx, getState());
  enterRule(_localctx, 24, TIPParser::RuleOutputStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(TIPParser::KOUTPUT);
    setState(240);
    expr(0);
    setState(241);
    match(TIPParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ErrorStmtContext ------------------------------------------------------------------

TIPParser::ErrorStmtContext::ErrorStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::ErrorStmtContext::KERROR() {
  return getToken(TIPParser::KERROR, 0);
}

TIPParser::ExprContext* TIPParser::ErrorStmtContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}


size_t TIPParser::ErrorStmtContext::getRuleIndex() const {
  return TIPParser::RuleErrorStmt;
}


std::any TIPParser::ErrorStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitErrorStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::ErrorStmtContext* TIPParser::errorStmt() {
  ErrorStmtContext *_localctx = _tracker.createInstance<ErrorStmtContext>(_ctx, getState());
  enterRule(_localctx, 26, TIPParser::RuleErrorStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(TIPParser::KERROR);
    setState(244);
    expr(0);
    setState(245);
    match(TIPParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

TIPParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::ReturnStmtContext::KRETURN() {
  return getToken(TIPParser::KRETURN, 0);
}

TIPParser::ExprContext* TIPParser::ReturnStmtContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}


size_t TIPParser::ReturnStmtContext::getRuleIndex() const {
  return TIPParser::RuleReturnStmt;
}


std::any TIPParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::ReturnStmtContext* TIPParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 28, TIPParser::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(TIPParser::KRETURN);
    setState(248);
    expr(0);
    setState(249);
    match(TIPParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

TIPParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::ForStmtContext::KFOR() {
  return getToken(TIPParser::KFOR, 0);
}

std::vector<TIPParser::ExprContext *> TIPParser::ForStmtContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::ForStmtContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

TIPParser::StatementContext* TIPParser::ForStmtContext::statement() {
  return getRuleContext<TIPParser::StatementContext>(0);
}


size_t TIPParser::ForStmtContext::getRuleIndex() const {
  return TIPParser::RuleForStmt;
}


std::any TIPParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::ForStmtContext* TIPParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 30, TIPParser::RuleForStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(TIPParser::KFOR);
    setState(252);
    match(TIPParser::T__0);
    setState(253);
    expr(0);
    setState(254);
    match(TIPParser::T__14);
    setState(255);
    expr(0);
    setState(256);
    match(TIPParser::T__2);
    setState(257);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForRangeStmtContext ------------------------------------------------------------------

TIPParser::ForRangeStmtContext::ForRangeStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TIPParser::ForRangeStmtContext::KFOR() {
  return getToken(TIPParser::KFOR, 0);
}

std::vector<TIPParser::ExprContext *> TIPParser::ForRangeStmtContext::expr() {
  return getRuleContexts<TIPParser::ExprContext>();
}

TIPParser::ExprContext* TIPParser::ForRangeStmtContext::expr(size_t i) {
  return getRuleContext<TIPParser::ExprContext>(i);
}

TIPParser::StatementContext* TIPParser::ForRangeStmtContext::statement() {
  return getRuleContext<TIPParser::StatementContext>(0);
}


size_t TIPParser::ForRangeStmtContext::getRuleIndex() const {
  return TIPParser::RuleForRangeStmt;
}


std::any TIPParser::ForRangeStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitForRangeStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::ForRangeStmtContext* TIPParser::forRangeStmt() {
  ForRangeStmtContext *_localctx = _tracker.createInstance<ForRangeStmtContext>(_ctx, getState());
  enterRule(_localctx, 32, TIPParser::RuleForRangeStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(TIPParser::KFOR);
    setState(260);
    match(TIPParser::T__0);
    setState(261);
    expr(0);
    setState(262);
    match(TIPParser::T__14);
    setState(263);
    expr(0);
    setState(264);
    match(TIPParser::T__16);
    setState(265);
    expr(0);
    setState(268);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TIPParser::T__17) {
      setState(266);
      match(TIPParser::T__17);
      setState(267);
      expr(0);
    }
    setState(270);
    match(TIPParser::T__2);
    setState(271);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncrementStmtContext ------------------------------------------------------------------

TIPParser::IncrementStmtContext::IncrementStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TIPParser::ExprContext* TIPParser::IncrementStmtContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}


size_t TIPParser::IncrementStmtContext::getRuleIndex() const {
  return TIPParser::RuleIncrementStmt;
}


std::any TIPParser::IncrementStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitIncrementStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::IncrementStmtContext* TIPParser::incrementStmt() {
  IncrementStmtContext *_localctx = _tracker.createInstance<IncrementStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, TIPParser::RuleIncrementStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    expr(0);
    setState(274);
    match(TIPParser::T__18);
    setState(275);
    match(TIPParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecrementStmtContext ------------------------------------------------------------------

TIPParser::DecrementStmtContext::DecrementStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TIPParser::ExprContext* TIPParser::DecrementStmtContext::expr() {
  return getRuleContext<TIPParser::ExprContext>(0);
}


size_t TIPParser::DecrementStmtContext::getRuleIndex() const {
  return TIPParser::RuleDecrementStmt;
}


std::any TIPParser::DecrementStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TIPVisitor*>(visitor))
    return parserVisitor->visitDecrementStmt(this);
  else
    return visitor->visitChildren(this);
}

TIPParser::DecrementStmtContext* TIPParser::decrementStmt() {
  DecrementStmtContext *_localctx = _tracker.createInstance<DecrementStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, TIPParser::RuleDecrementStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    expr(0);
    setState(278);
    match(TIPParser::T__19);
    setState(279);
    match(TIPParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool TIPParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 4: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TIPParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 15);
    case 1: return precpred(_ctx, 14);
    case 2: return precpred(_ctx, 13);
    case 3: return precpred(_ctx, 12);
    case 4: return precpred(_ctx, 11);
    case 5: return precpred(_ctx, 10);
    case 6: return precpred(_ctx, 26);
    case 7: return precpred(_ctx, 23);
    case 8: return precpred(_ctx, 22);

  default:
    break;
  }
  return true;
}

void TIPParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  tipParserInitialize();
#else
  ::antlr4::internal::call_once(tipParserOnceFlag, tipParserInitialize);
#endif
}

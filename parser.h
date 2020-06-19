#ifndef PARSER_H
#define PARSER_H

#define TOKEN_ADD 1
#define TOKEN_MIN 2
#define TOKEN_MUL 3
#define TOKEN_DIV 4
#define TOKEN_LEFTPARE 5
#define TOKEN_RIGHTPARE 6
#define TOKEN_SIN 7
#define TOKEN_COS 8
#define TOKEN_LN 9
#define TOKEN_EXP 10
#define TOKEN_SQRT 11
#define TOKEN_POW 12
#define TOKEN_FABS 13
#define TOKEN_PI 14
#define TOKEN_E 15
#define TOKEN_DOT 16
#define TOKEN_COMMA 17
#define TOKEN_END 18
#define TOKEN_0 19
#define TOKEN_1 20
#define TOKEN_2 21
#define TOKEN_3 22
#define TOKEN_4 23
#define TOKEN_5 24
#define TOKEN_6 25
#define TOKEN_7 26
#define TOKEN_8 27
#define TOKEN_9 28

#define CONST_PI 3.141592653589793
#define CONST_E 2.718281828459045

struct Token
{
    int type;
    char lexeme[6];
};

struct LexParseResult
{
    int success;
    int size;
    struct Token token[100];
};

struct GrammarParseArgs
{
    struct LexParseResult lex;
    int current_idx;
};

struct GrammarParseResult
{
    int success;
    char errorMsg[100];
    double value;
    char numStr[100];
};

struct LexParseResult lexParse(const char* line);
void printLexParseResult(struct LexParseResult result);

struct GrammarParseResult grammarParse(struct GrammarParseArgs *args);
struct GrammarParseResult parseAddExp(struct GrammarParseArgs *args);
struct GrammarParseResult parseAddExpQuote(struct GrammarParseArgs *args, double value);
struct GrammarParseResult parseMulExp(struct GrammarParseArgs *args);
struct GrammarParseResult parseMulExpQuote(struct GrammarParseArgs *args, double value);
struct GrammarParseResult parseAtomExp(struct GrammarParseArgs *args);
struct GrammarParseResult parseFuncExp(struct GrammarParseArgs *args);
struct GrammarParseResult parseFunc1(struct GrammarParseArgs *args);
struct GrammarParseResult parseFunc2(struct GrammarParseArgs *args);
struct GrammarParseResult parseConstValue(struct GrammarParseArgs *args);
struct GrammarParseResult parseNumericValue(struct GrammarParseArgs *args);
struct GrammarParseResult parseNumericValueQuote(struct GrammarParseArgs *args);
struct GrammarParseResult parseDigits(struct GrammarParseArgs *args);
struct GrammarParseResult parseDigit(struct GrammarParseArgs *args);

#endif
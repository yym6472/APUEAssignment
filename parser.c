#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "parser.h"


struct LexParseResult lexParse(const char* line)
{
    struct LexParseResult result;
    result.size = 0;

    const char* cur = line;
    while (cur[0] != '\0')
    {
        if (isspace(cur[0]))
        {
            cur += 1;
            continue;
        }
        if (strstr(cur, "+") == cur) {
            result.token[result.size].type = TOKEN_ADD;
            strcpy(result.token[result.size].lexeme, "+");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "-") == cur) {
            result.token[result.size].type = TOKEN_MIN;
            strcpy(result.token[result.size].lexeme, "-");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "*") == cur) {
            result.token[result.size].type = TOKEN_MUL;
            strcpy(result.token[result.size].lexeme, "*");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "/") == cur) {
            result.token[result.size].type = TOKEN_DIV;
            strcpy(result.token[result.size].lexeme, "/");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "(") == cur) {
            result.token[result.size].type = TOKEN_LEFTPARE;
            strcpy(result.token[result.size].lexeme, "(");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, ")") == cur) {
            result.token[result.size].type = TOKEN_RIGHTPARE;
            strcpy(result.token[result.size].lexeme, ")");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "sin") == cur) {
            result.token[result.size].type = TOKEN_SIN;
            strcpy(result.token[result.size].lexeme, "sin");
            result.size += 1;
            cur += 3;
        } else if (strstr(cur, "cos") == cur) {
            result.token[result.size].type = TOKEN_COS;
            strcpy(result.token[result.size].lexeme, "cos");
            result.size += 1;
            cur += 3;
        } else if (strstr(cur, "ln") == cur) {
            result.token[result.size].type = TOKEN_LN;
            strcpy(result.token[result.size].lexeme, "ln");
            result.size += 1;
            cur += 2;
        } else if (strstr(cur, "exp") == cur) {
            result.token[result.size].type = TOKEN_EXP;
            strcpy(result.token[result.size].lexeme, "exp");
            result.size += 1;
            cur += 3;
        } else if (strstr(cur, "sqrt") == cur) {
            result.token[result.size].type = TOKEN_SQRT;
            strcpy(result.token[result.size].lexeme, "sqrt");
            result.size += 1;
            cur += 4;
        } else if (strstr(cur, "pow") == cur) {
            result.token[result.size].type = TOKEN_POW;
            strcpy(result.token[result.size].lexeme, "pow");
            result.size += 1;
            cur += 3;
        } else if (strstr(cur, "fabs") == cur) {
            result.token[result.size].type = TOKEN_FABS;
            strcpy(result.token[result.size].lexeme, "fabs");
            result.size += 1;
            cur += 4;
        } else if (strstr(cur, "pi") == cur) {
            result.token[result.size].type = TOKEN_PI;
            strcpy(result.token[result.size].lexeme, "pi");
            result.size += 1;
            cur += 2;
        } else if (strstr(cur, "e") == cur) {
            result.token[result.size].type = TOKEN_E;
            strcpy(result.token[result.size].lexeme, "e");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, ".") == cur) {
            result.token[result.size].type = TOKEN_DOT;
            strcpy(result.token[result.size].lexeme, ".");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, ",") == cur) {
            result.token[result.size].type = TOKEN_COMMA;
            strcpy(result.token[result.size].lexeme, ",");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "0") == cur) {
            result.token[result.size].type = TOKEN_0;
            strcpy(result.token[result.size].lexeme, "0");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "1") == cur) {
            result.token[result.size].type = TOKEN_1;
            strcpy(result.token[result.size].lexeme, "1");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "2") == cur) {
            result.token[result.size].type = TOKEN_2;
            strcpy(result.token[result.size].lexeme, "2");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "3") == cur) {
            result.token[result.size].type = TOKEN_3;
            strcpy(result.token[result.size].lexeme, "3");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "4") == cur) {
            result.token[result.size].type = TOKEN_4;
            strcpy(result.token[result.size].lexeme, "4");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "5") == cur) {
            result.token[result.size].type = TOKEN_5;
            strcpy(result.token[result.size].lexeme, "5");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "6") == cur) {
            result.token[result.size].type = TOKEN_6;
            strcpy(result.token[result.size].lexeme, "6");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "7") == cur) {
            result.token[result.size].type = TOKEN_7;
            strcpy(result.token[result.size].lexeme, "7");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "8") == cur) {
            result.token[result.size].type = TOKEN_8;
            strcpy(result.token[result.size].lexeme, "8");
            result.size += 1;
            cur += 1;
        } else if (strstr(cur, "9") == cur) {
            result.token[result.size].type = TOKEN_9;
            strcpy(result.token[result.size].lexeme, "9");
            result.size += 1;
            cur += 1;
        } else {
            result.success = 0;
            return result;
        }
    }
    
    result.token[result.size].type = TOKEN_END;
    strcpy(result.token[result.size].lexeme, "#");
    result.size += 1;
    result.success = 1;
    return result;
}

void printLexParseResult(struct LexParseResult result)
{
    for (int i = 0; i < result.size; ++i)
    {
        printf("%s ", result.token[i].lexeme);
    }
    printf("\n");
}


struct GrammarParseResult grammarParse(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result = parseAddExp(args);
    if (args->current_idx != args->lex.size - 1) {
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression, too much tokens.");
    }
    return result;
}

struct GrammarParseResult parseAddExp(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    switch (nextToken.type)
    {
    case TOKEN_MIN:
    case TOKEN_LEFTPARE:
    case TOKEN_SIN:
    case TOKEN_COS:
    case TOKEN_LN:
    case TOKEN_EXP:
    case TOKEN_SQRT:
    case TOKEN_POW:
    case TOKEN_FABS:
    case TOKEN_PI:
    case TOKEN_E:
    case TOKEN_0:
    case TOKEN_1:
    case TOKEN_2:
    case TOKEN_3:
    case TOKEN_4:
    case TOKEN_5:
    case TOKEN_6:
    case TOKEN_7:
    case TOKEN_8:
    case TOKEN_9:
    case TOKEN_DOT:
        // AddExp -> MulExp AddExp'
        res1 = parseMulExp(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseAddExpQuote(args, res1.value);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        result.value = res2.value;
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse AddExp.");
        break;
    }
    return result;
}

struct GrammarParseResult parseAddExpQuote(struct GrammarParseArgs *args, double value)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    switch (nextToken.type)
    {
    case TOKEN_ADD:
        // AddExp' -> + MulExp AddExp'
        args->current_idx += 1;
        res1 = parseMulExp(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseAddExpQuote(args, value + res1.value);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        result.value = res2.value;
        break;
    case TOKEN_MIN:
        // AddExp' -> - MulExp AddExp'
        args->current_idx += 1;
        res1 = parseMulExp(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseAddExpQuote(args, value - res1.value);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        result.value = res2.value;
        break;
    case TOKEN_RIGHTPARE:
    case TOKEN_COMMA:
    case TOKEN_END:
        // AddExp' -> ε
        result.success = 1;
        result.value = value;
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse AddExp'.");
        break;
    }
    return result;
}

struct GrammarParseResult parseMulExp(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    switch (nextToken.type)
    {
    case TOKEN_MIN:
    case TOKEN_LEFTPARE:
    case TOKEN_SIN:
    case TOKEN_COS:
    case TOKEN_LN:
    case TOKEN_EXP:
    case TOKEN_SQRT:
    case TOKEN_POW:
    case TOKEN_FABS:
    case TOKEN_PI:
    case TOKEN_E:
    case TOKEN_0:
    case TOKEN_1:
    case TOKEN_2:
    case TOKEN_3:
    case TOKEN_4:
    case TOKEN_5:
    case TOKEN_6:
    case TOKEN_7:
    case TOKEN_8:
    case TOKEN_9:
    case TOKEN_DOT:
        // MulExp -> AtomExp MulExp'
        res1 = parseAtomExp(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseMulExpQuote(args, res1.value);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        result.value = res2.value;
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse MulExp.");
        break;
    }
    return result;
}

struct GrammarParseResult parseMulExpQuote(struct GrammarParseArgs *args, double value)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    switch (nextToken.type)
    {
    case TOKEN_MUL:
        // MulExp' -> * AtomExp MulExp'
        args->current_idx += 1;
        res1 = parseAtomExp(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseMulExpQuote(args, value * res1.value);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        result.value = res2.value;
        break;
    case TOKEN_DIV:
        // MulExp' -> / AtomExp MulExp'
        args->current_idx += 1;
        res1 = parseAtomExp(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        if (fabs(res1.value) < 1e-10) {
            result.success = 0;
            strcpy(result.errorMsg, "Computation error, divided by zero.");
            break;
        }
        res2 = parseMulExpQuote(args, value / res1.value);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        result.value = res2.value;
        break;
    case TOKEN_ADD:
    case TOKEN_MIN:
    case TOKEN_RIGHTPARE:
    case TOKEN_COMMA:
    case TOKEN_END:
        // MulExp' -> ε
        result.success = 1;
        result.value = value;
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse MulExp'.");
        break;
    }
    return result;
}

struct GrammarParseResult parseAtomExp(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    switch (nextToken.type)
    {
    case TOKEN_LEFTPARE:
        // AtomExp -> ( AddExp )
        args->current_idx += 1;
        res1 = parseAddExp(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        args->current_idx += 1;
        result.success = 1;
        result.value = res1.value;
        break;
    case TOKEN_SIN:
    case TOKEN_COS:
    case TOKEN_LN:
    case TOKEN_EXP:
    case TOKEN_SQRT:
    case TOKEN_POW:
    case TOKEN_FABS:
        // AtomExp -> FuncExp
        res1 = parseFuncExp(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        result.success = 1;
        result.value = res1.value;
        break;
    case TOKEN_PI:
    case TOKEN_E:
    case TOKEN_MIN:
    case TOKEN_DOT:
    case TOKEN_0:
    case TOKEN_1:
    case TOKEN_2:
    case TOKEN_3:
    case TOKEN_4:
    case TOKEN_5:
    case TOKEN_6:
    case TOKEN_7:
    case TOKEN_8:
    case TOKEN_9:
        // AtomExp -> ConstValue
        res1 = parseConstValue(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        result.success = 1;
        result.value = res1.value;
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse AtomExp.");
        break;
    }
    return result;
}

struct GrammarParseResult parseFuncExp(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    struct GrammarParseResult res3;
    switch (nextToken.type)
    {
    case TOKEN_SIN:
    case TOKEN_COS:
    case TOKEN_LN:
    case TOKEN_EXP:
    case TOKEN_SQRT:
    case TOKEN_FABS:
        // FuncExp -> Func1 ( AddExp )
        res1 = parseFunc1(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        args->current_idx += 1;
        res2 = parseAddExp(args);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        args->current_idx += 1;
        if (strcmp(res1.numStr, "sin") == 0) {
            result.success = 1;
            result.value = sin(res2.value);
        } else if (strcmp(res1.numStr, "cos") == 0) {
            result.success = 1;
            result.value = cos(res2.value);
        } else if (strcmp(res1.numStr, "ln") == 0) {
            if (res2.value <= 0.) {
                result.success = 0;
                strcpy(result.errorMsg, "Computation error when compute ln(x), x should be > 0.");
            } else {
                result.success = 1;
                result.value = log(res2.value);
            }
        } else if (strcmp(res1.numStr, "exp") == 0) {
            result.success = 1;
            result.value = exp(res2.value);
        } else if (strcmp(res1.numStr, "sqrt") == 0) {
            if (res2.value < 0.) {
                result.success = 0;
                strcpy(result.errorMsg, "Computation error when compute sqrt(x), x should be >= 0.");
            } else {
                result.success = 1;
                result.value = sqrt(res2.value);
            }
        } else if (strcmp(res1.numStr, "fabs") == 0) {
            result.success = 1;
            result.value = fabs(res2.value);
        }
        break;
    case TOKEN_POW:
        // FuncExp -> Func2 ( AddExp , AddExp )
        res1 = parseFunc2(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        args->current_idx += 1;
        res2 = parseAddExp(args);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        args->current_idx += 1;
        res3 = parseAddExp(args);
        if (!res3.success) {
            result.success = 0;
            strcpy(result.errorMsg, res3.errorMsg);
            break;
        }
        args->current_idx += 1;
        if (strcmp(res1.numStr, "pow") == 0) {
            result.success = 1;
            result.value = pow(res2.value, res3.value);
        }
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse FuncExp.");
        break;
    }
    return result;
}

struct GrammarParseResult parseFunc1(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    switch (nextToken.type)
    {
    case TOKEN_SIN:
        // Func1 -> sin
        args->current_idx += 1;
        result.success = 1;
        strcpy(result.numStr, "sin");
        break;
    case TOKEN_COS:
        // Func1 -> cos
        args->current_idx += 1;
        result.success = 1;
        strcpy(result.numStr, "cos");
        break;
    case TOKEN_LN:
        // Func1 -> ln
        args->current_idx += 1;
        result.success = 1;
        strcpy(result.numStr, "ln");
        break;
    case TOKEN_EXP:
        // Func1 -> exp
        args->current_idx += 1;
        result.success = 1;
        strcpy(result.numStr, "exp");
        break;
    case TOKEN_SQRT:
        // Func1 -> sqrt
        args->current_idx += 1;
        result.success = 1;
        strcpy(result.numStr, "sqrt");
        break;
    case TOKEN_FABS:
        // Func1 -> fabs
        args->current_idx += 1;
        result.success = 1;
        strcpy(result.numStr, "fabs");
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse Func1.");
        break;
    }
    return result;
}

struct GrammarParseResult parseFunc2(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    switch (nextToken.type)
    {
    case TOKEN_POW:
        // Func2 -> pow
        args->current_idx += 1;
        result.success = 1;
        strcpy(result.numStr, "pow");
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse Func2.");
        break;
    }
    return result;
}

struct GrammarParseResult parseConstValue(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    switch (nextToken.type)
    {
    case TOKEN_PI:
        // ConstValue -> pi
        args->current_idx += 1;
        result.success = 1;
        result.value = CONST_PI;
        break;
    case TOKEN_E:
        // ConstValue -> e
        args->current_idx += 1;
        result.success = 1;
        result.value = CONST_E;
        break;
    case TOKEN_DOT:
    case TOKEN_0:
    case TOKEN_1:
    case TOKEN_2:
    case TOKEN_3:
    case TOKEN_4:
    case TOKEN_5:
    case TOKEN_6:
    case TOKEN_7:
    case TOKEN_8:
    case TOKEN_9:
        // ConstValue -> NumericValue
        res1 = parseNumericValue(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        result.success = 1;
        result.value = atof(res1.numStr);
        break;
    case TOKEN_MIN:
        // ConstValue -> - NumericValue
        args->current_idx += 1;
        res1 = parseNumericValue(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        result.success = 1;
        result.value = -1.0 * atof(res1.numStr);
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse ConstValue.");
        break;
    }
    return result;
}

struct GrammarParseResult parseNumericValue(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    switch (nextToken.type)
    {
    case TOKEN_DOT:
        // NumericValue -> . Digit Digits
        args->current_idx += 1;
        res1 = parseDigit(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseDigits(args);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        strcpy(result.numStr, ".");
        strcat(result.numStr, res1.numStr);
        strcat(result.numStr, res2.numStr);
        break;
    case TOKEN_0:
    case TOKEN_1:
    case TOKEN_2:
    case TOKEN_3:
    case TOKEN_4:
    case TOKEN_5:
    case TOKEN_6:
    case TOKEN_7:
    case TOKEN_8:
    case TOKEN_9:
        // NumericValue -> Digit NumericValue'
        res1 = parseDigit(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseNumericValueQuote(args);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        strcpy(result.numStr, res1.numStr);
        strcat(result.numStr, res2.numStr);
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse NumericValue.");
        break;
    }
    return result;
}

struct GrammarParseResult parseNumericValueQuote(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    switch (nextToken.type)
    {
    case TOKEN_DOT:
        // NumericValue' -> . Digits
        args->current_idx += 1;
        res1 = parseDigits(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        result.success = 1;
        strcpy(result.numStr, ".");
        strcat(result.numStr, res1.numStr);
        break;
    case TOKEN_0:
    case TOKEN_1:
    case TOKEN_2:
    case TOKEN_3:
    case TOKEN_4:
    case TOKEN_5:
    case TOKEN_6:
    case TOKEN_7:
    case TOKEN_8:
    case TOKEN_9:
        // NumericValue' -> Digit NumericValue'
        res1 = parseDigit(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseNumericValueQuote(args);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        strcpy(result.numStr, res1.numStr);
        strcat(result.numStr, res2.numStr);
        break;
    case TOKEN_ADD:
    case TOKEN_MIN:
    case TOKEN_MUL:
    case TOKEN_DIV:
    case TOKEN_RIGHTPARE:
    case TOKEN_COMMA:
    case TOKEN_END:
        // NumericValue' -> ε
        result.success = 1;
        strcpy(result.numStr, "");
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse NumericValue'.");
        break;
    }
    return result;
}

struct GrammarParseResult parseDigits(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    struct GrammarParseResult res1;
    struct GrammarParseResult res2;
    switch (nextToken.type)
    {
    case TOKEN_0:
    case TOKEN_1:
    case TOKEN_2:
    case TOKEN_3:
    case TOKEN_4:
    case TOKEN_5:
    case TOKEN_6:
    case TOKEN_7:
    case TOKEN_8:
    case TOKEN_9:
        // Digits -> Digit Digits
        res1 = parseDigit(args);
        if (!res1.success) {
            result.success = 0;
            strcpy(result.errorMsg, res1.errorMsg);
            break;
        }
        res2 = parseDigits(args);
        if (!res2.success) {
            result.success = 0;
            strcpy(result.errorMsg, res2.errorMsg);
            break;
        }
        result.success = 1;
        strcpy(result.numStr, res1.numStr);
        strcat(result.numStr, res2.numStr);
        break;
    case TOKEN_ADD:
    case TOKEN_MIN:
    case TOKEN_MUL:
    case TOKEN_DIV:
    case TOKEN_RIGHTPARE:
    case TOKEN_COMMA:
    case TOKEN_END:
        // Digits -> ε
        result.success = 1;
        strcpy(result.numStr, "");
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse Digits.");
        break;
    }
    return result;
}

struct GrammarParseResult parseDigit(struct GrammarParseArgs *args)
{
    struct GrammarParseResult result;
    struct Token nextToken = args->lex.token[args->current_idx];
    switch (nextToken.type)
    {
    case TOKEN_0:
    case TOKEN_1:
    case TOKEN_2:
    case TOKEN_3:
    case TOKEN_4:
    case TOKEN_5:
    case TOKEN_6:
    case TOKEN_7:
    case TOKEN_8:
    case TOKEN_9:
        // Digit -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
        result.success = 1;
        strcpy(result.numStr, nextToken.lexeme);
        args->current_idx += 1;
        break;
    default:
        result.success = 0;
        strcpy(result.errorMsg, "Invalid expression when parse Digit.");
        break;
    }
    return result;
}

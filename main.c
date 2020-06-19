#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

#define BUFFER_SIZE 1024

char* precision; // 初始精度

/* 获取环境变量设置的提示符；若未设置，返回默认提示符。 */
char* getIndicator(void) {
    char* res = getenv("BC_INDICATOR");
    if (res == NULL) {
        res = "->";
    }
    return res;
}

/* 检测字符串是否全部为空白字符 */
int allSpace(const char* s)
{
    int idx = 0;
    while (s[idx] != '\0')
    {
        if (!isspace(s[idx])) return 0;
        idx += 1;
    }
    return 1;
}

/* 设置精度 */
int setPrecision(const char* s)
{
    if (s[0] != ' ')
        return 0;
    if (s[1] == '\0')
        return 0;
    if (s[2] == '\0')
    {
        if (s[1] < '0' || s[1] > '9')
            return 0;
        precision[0] = s[1];
        precision[1] = '\0';
        return 1;
    }
    else if (s[3] == '\0')
    {
        if (s[1] != '1')
            return 0;
        if (s[2] < '0' || s[2] > '9')
            return 0;
        precision[0] = s[1];
        precision[1] = s[2];
        precision[2] = '\0';
        return 1;
    }
    else
    {
        return 0;
    }
}

/* 主函数入口 */
int main(void)
{
    char* indicator = getIndicator();
    char* buf = (char*)malloc(BUFFER_SIZE);
    precision = (char*)malloc(5);
    precision[0] = '6';
    precision[1] = '\0';

    while (1) {
        /* 打印提示符 */
        printf("%s ", indicator);
        fflush(stdin);
        
        /* 从stdin中读取一行 */
        fgets(buf, BUFFER_SIZE, stdin);
        buf[strlen(buf) - 1] = '\0'; // 去除行末回车

        /* 空行检测 */
        if (allSpace(buf)) {
            continue;
        }

        /* 退出命令 */
        if (strcmp(buf, "EXIT") == 0) {
            printf("Bye.\n");
            break;
        }

        /* 设置精度命令 */
        if (strstr(buf, "SET_PRECISION ") == buf) {
            if (setPrecision(buf + 13))
                printf("OK.\n");
            else
                printf("Error. Precision unchanged.\n");
            continue;
        }

        /* 表达式求值 */
        struct LexParseResult lexResult = lexParse(buf);
        if (!lexResult.success) {
            printf("Error. Invalid tokens.\n");
            continue;
        }
        struct GrammarParseArgs *args = (struct GrammarParseArgs*)malloc(sizeof(struct GrammarParseArgs));
        args->current_idx = 0;
        args->lex = lexResult;
        struct GrammarParseResult graResult = grammarParse(args);
        if (!graResult.success) {
            printf("%s\n", graResult.errorMsg);
        } else {
            char fmtStr[100];
            strcpy(fmtStr, "%.");
            strcat(fmtStr, precision);
            strcat(fmtStr, "lf\n");
            printf(fmtStr, graResult.value);
        }
        free(args);
    }
    free(buf);
    free(precision);
    return 0;
}
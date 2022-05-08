#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;


int main(void){

    int ntoken, vtoken;

    ntoken = yylex();
    while(ntoken){
        switch(ntoken){
            case MONOM:
                printf("Monom: %s\n", yytext);
                break;
            case VARIABLE:
                printf("Var: %s\n", yytext);
                break;
            case COMMON_SIGN:
                printf("Common_sign: %s\n", yytext);
                break;
            case STRONG_SIGN:
                printf("Strong_sign: %s\n", yytext);
                break;
            case BRACKET:
                printf("BRACKET: %s\n", yytext);
                break;
            case END_OF_FILE:
            printf("We have EOF\n");
            break;
            default:
                printf("Error in line %d: unexpected symbol \"%s\"\n", yylineno, yytext);
                return -1;
        }
        ntoken = yylex();
    }
    return 0;
}
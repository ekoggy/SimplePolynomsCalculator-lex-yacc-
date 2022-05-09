#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;


int main(void){

    int ntoken, vtoken;

    ntoken = yylex();
    while(ntoken){
        printf("%s", yytext);
        // switch(ntoken){
        //     case MONOM:
        //         printf("Monom: %s\n", yytext);
        //         break;
        //     case VARIABLE:
        //         printf("Var: %s\n", yytext);
        //         break;
        //     case COMMON_SIGN:
        //         printf("Common_sign: %s\n", yytext);
        //         break;
        //     case STRONG_SIGN:
        //         printf("Strong_sign: %s\n", yytext);
        //         break;
        //     case LEFT_BRACKET:
        //         printf("LEFT_BRACKET: %s\n", yytext);
        //         break;
        //     case RIGHT_BRACKET:
        //         printf("RIGHT_BRACKET: %s\n", yytext);
        //         break;
        //      case SINGLE_LINE_COMMENT:
        //         printf("SINGLE_LINE_COMMENT: %d\n", yylineno);
        //         break;
        //      case MULTI_LINE_COMMENT_START :
        //         printf("MULTI_LINE_COMMENT_START : %d\n", yylineno);
        //         break;
        //      case MULTI_LINE_COMMENT_END:
        //         printf("MULTI_LINE_COMMENT_END: %d\n", yylineno);
        //         break; 
        //     case TRANSFER_COMMENT:
        //         printf("TRANSFER_COMMENT:%d\n", yylineno);
        //         break;
        //     case END_OF_STRING:
        //         printf("String end\n");
        //         break;
        //     case END_OF_FILE:
        //         printf("We have EOF\n");
        //         return 0;
        //     default:
        //         printf("Error in line %d: unexpected symbol \"%s\"\n", yylineno, yytext);
        //         return -1;
        // }
        ntoken = yylex();
    }
            printf("\n\n");
    return 0;
}
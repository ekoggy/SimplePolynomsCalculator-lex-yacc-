%{
#ifdef __unix__
// __unix__ is usually defined by compilers targeting Unix systems
#include "analyser.tab.h"
#elif defined _WIN32
// _Win32 is usually defined by compilers targeting 32 or 64 bit Windows systems
#include "analyser.tab.h"
#endif
#include "grammar.h"

int yylex();
%}

%option yylineno
%option noyywrap
%Start out_com in_single in_multi

%%
						BEGIN out_com;
               
<out_com>"/*"           BEGIN in_multi;
<in_multi>.|\n          ;
<in_multi>"*/"          BEGIN in_single;

<out_com>"//"			BEGIN in_single;
<in_single>.          	;
<in_single>\n			BEGIN out_com;

<out_com>"-"            {return TMINUS;}
<out_com>">>"			{return PRINT;}
<out_com>[a-z]* 		{yylval.symbol = yytext[0]; return LITERAL;}
<out_com>[A-Z]* 		{yylval.symbol = yytext[0]; return VAR;}
<out_com>[1-9]+			{if((strlen(yytext) > 1)&&(yytext[0] == 48)){
                            PrintError("Incorrect number");
                            }
                        yylval.num = atoi(yytext); return NUMBER;
                        }
<out_com>[*+^=()]       {yylval.symbol = yytext[0]; return SIGN;}
<out_com>[\n]			{gLineNum++; return END_OF_LINE;}
<out_com><<EOF>> 		{gLineNum++; return END_OF_FILE;}
<out_com>[ \t\r]		;
<out_com>.				{ECHO; yyerror (yytext);}

%%
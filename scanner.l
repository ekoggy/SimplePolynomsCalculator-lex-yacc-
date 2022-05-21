%{
#ifdef __unix__
// __unix__ is usually defined by compilers targeting Unix systems
#include "y.tab.h"
#elif defined _WIN32
// _Win32 is usually defined by compilers targeting 32 or 64 bit Windows systems
#include "analyser.tab.h"
#endif
#include "grammar.h"

int yylex();
%}
%option yylineno
%option  noyywrap
%%
\/\/(.*)                {;}
\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/  {;}
"-"                     {return MINUS;}
"<<"				   	{return PRINT;}
[a-z]				   	{yylval.id = yytext[0]; return LITERAL;}
[A-Z]				   	{yylval.id = yytext[0]; return VAR;}
[0-9]+                 	{
                            
                            int len = strlen(yytext);
                            if((len > 1)&&(yytext[0] == 48))
                                Helper::PrintError("Incorrect number");
                            else
                                yylval.num = atoi(yytext); return NUMBER;
                        }
[ \t\r]                	{;}
[\n]                    {gLineNum++; return END_OF_LINE;}
<<EOF>>                 {gLineNum++; return END_OF_FILE;}
[*+^=;())(]           	{return yytext[0];}
.                      	{ECHO; yyerror (yytext);}


%%



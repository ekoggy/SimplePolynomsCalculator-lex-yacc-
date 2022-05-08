%{
	#include "scanner.h"
%}

%%
-{0,1}[a-z1-9^]+ return MONOM;
[A-Z]* 	return VARIABLE;
[+-=]	return COMMON_SIGN;
[*^]	return STRONG_SIGN;
[()]	return BRACKET;
<<EOF>>     return END_OF_FILE; 
[ \t\n]					;
.						;

%%

int yywrap (void){
	return 1;
}
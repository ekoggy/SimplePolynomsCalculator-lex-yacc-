%{
	#include "scanner.h"
%}


%Start out_com in_single in_multi
%%
						BEGIN out_com;
               
<out_com>"/*"           BEGIN in_multi;
<in_multi>.|\n          ;
<in_multi>"*/"          BEGIN in_single;

<out_com>"//"			BEGIN in_single;
<in_single>.          	;
<in_single>\n			BEGIN out_com;

<out_com>-?[1-9a-z]+ 	return MONOM;
<out_com>[A-Z]* 		return VARIABLE;
<out_com>[+-=]			return COMMON_SIGN;
<out_com>[*^]			return STRONG_SIGN;
<out_com>[(]			return LEFT_BRACKET;
<out_com>[)]			return RIGHT_BRACKET;
<out_com>[\n]			return END_OF_STRING;
<out_com><<EOF>> 		return END_OF_FILE;
<out_com>[ \t]			;
<out_com>.				;

%%

int yywrap (void){
	return 1;
}
%{
	#include "analyser.tab.h"
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

<out_com>-?"("?[2-9]*[a-z]+.*	return POLYNOM;
<out_com>[1-9]+			return NUMBER;
<out_com>[A-Z]* 		return VAR;
<out_com>"+"			return PLUS;
<out_com>"-"			return MINUS;
<out_com>"*"			return MUL;
<out_com>"^"			return POW;
<out_com>"="			return EQ;
<out_com>[(]			return LEFT_BRACKET;
<out_com>[)]			return RIGHT_BRACKET;
<out_com>[\n]			{gLineNum++; return END_OF_LINE;};
<out_com><<EOF>> 		return END_OF_FILE;
<out_com>[ \t]			;
<out_com>.				;

%%

int yywrap (void){
	return 1;
}
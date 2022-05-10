%{
	#include "grammar.h"
	void yyerror(char const *s);
	int	gLineNum;
%}

%union
{
	struct Polynom* 	poly;
	struct Expression*	expr;
	int 	num;
	char 	string[1000];
	char 	symbol;
}

%type <symbol>	    end_symbol
%type <expr> 	    expression variable
%type <poly> 	    polynom

%left '+' '-'
%left '*'
%right '^'

%start start
%token <symbol>	    END_OF_LINE END_OF_FILE
%token <string>	    POLYNOM PRINT
%token <symbol>	    RIGHT_BRACKET LEFT_BRACKET
%token <symbol>     VAR
%token <num>        NUMBER
%token <symbol>     PLUS MINUS MUL POW EQ
%%
start:
	        | start end_symbol
	        | start '\r'
	        | start command
	        ;

command:    expression EQ expression end_symbol     {add_to_variables($1, $3);}
		    | PRINT expression end_symbol           {print_expression($2);}
		    ;

end_symbol: END_OF_FILE                             {$$ = $1;}
			| END_OF_LINE                           {$$ = $1;}
	        ;

expression: expression PLUS variable                {$$ = sum_expression($1, $3);}
			| expression MINUS variable             {$$ = sub_expression($1, $3);}
			| expression MUL variable               {$$ = mul_expression($1, $3);}
			| expression POW NUMBER                 {$$ = pow_expression($1, $3);}
			| LEFT_BRACKET expression RIGHT_BRACKET {$$ = try_to_calculate_expression($2);}
			| variable                              {$$ = $1;}
			;

variable:   VAR                                     {$$ = get_expression($1);}
			| NUMBER VAR 							{$$ = get_mul_expression($2, $1);}
			| polynom                        		{$$ = add_to_expression($1);}
			;

polynom: 	POLYNOM									{create_polynom($1);}
%%

int main (void) {	
	return yyparse ();
}
%{
	#include "grammar.h"
%}

%union
{
	Poly* 	poly;
	Expr*	expr;
	int 	num;
	char 	string[100];
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
%token <string>	    MONOM VAR
%token <symbol>	    RIGHT_BRACKET LEFT_BRACKET
%token <str>        PRINT
%token <num>        NUMBER
%token <symbol>     PLUS MINUS MUL POW EQ
%%
start:
	        | start end_symbol
	        | start '\r'
	        | start command
	        ;

command:    expression EQ expression end_symbol     {add_to_variables($1, $3);}
		    |PRINT expression end_symbol            {print_expression($2);}
		    ;

end_symbol: END_OF_FILE                             {$$ = $1;}
			|END_OF_LINE                            {$$ = $1;}
	        ;

expression: expression PLUS variable                {$$ = sum_expression($1, $3);}
			| expression MINUS variable             {$$ = sub_expression($1, $3);}
			| expression MUL variable               {$$ = mul_expression($1, $3);}
			| expression POW NUMBER                 {$$ = pow_expression($1, $3);}
			| LEFT_BRACKET expression RIGHT_BRACKET {$$ = some_action2($2);}
			| variable                              {$$ = $1;}
			;

variable:   VAR                                     {$$ = get_expression($1);}
		    |polynom                                {$$ = add_to_expression($1);}
			;

polynom:    polynom PLUS MONOM                      {$$ = sum_polynoms($1, add_to_polymon($2));}
	    	| polynom MINUS MONOM                   {$$ = sub_polynoms($1, add_to_polymon($2));}
		    | LEFT_BRACKET polynom RIGHT_BRACKET    {$$ = some_action($2);}
            | MONOM                                 {$$ = add_to_polymon($1);}
		    ;
%%
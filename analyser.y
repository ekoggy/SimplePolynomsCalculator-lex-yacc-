%{
#include "grammar.h"
void yyerror (char *s);
int yylex();
%}

%union {
	int 	num; 
	int 	*piece_formula;
	char 	id; 
	struct 	Expression *formula;
	}         /* Yacc definitions */

%start begin
%token PRINT
%token MINUS
%token END_OF_LINE
%token END_OF_FILE

%token <num> NUMBER

%token <id> VAR  
%token <id> LITERAL

%type <formula> polynom  
%type <formula> brackets

%type <num> power
%type <num> begin 
%type <num> line 
%type <num> errors

%type <piece_formula> monom 
%type <piece_formula> symbol

%type <id> assignment

%left '+' 
%left NEG
%left MINUS
%left '*'
%right '^'
%left '(' ')'


%%
begin 		: line END_OF_LINE begin
				{
					;
				}
			| line END_OF_LINE
				{
					;
				}
				
			| END_OF_LINE begin
				{
					;
				}
			| line END_OF_FILE
				{
					exit(1);
				}
			;

line		: assignment ';'	
				{
					;
				}

			| PRINT VAR ';'
				{
					int idx = Helper::CharSymbolToIndex($2);
					PrintPolynom(idx);
				}
			| assignment 
				{
					Helper::PrintError("Forgot in assignment ';'");
				}
			| PRINT VAR 
				{
					Helper::PrintError("Forgot in error ';'");
				}
			;

assignment	: VAR '=' polynom 		
				{
					int idx = Helper::CharSymbolToIndex($1);
					AssignmentPolynom($1, $3);
				}
			| errors
				{
					;
				}
			;
errors 		: VAR '='
				{
					Helper::PrintError("Error initialization");
					exit(-1);
				}
			
			;

polynom 	: MINUS polynom %prec NEG
				{
					$$ = PolynomInit();
					PolynomMinus($$, $2);
				} 
			| brackets
				{
					$$ =$1;
				}
			| brackets brackets %prec '*'
				{
					$$ = PolynomMultiple($1, $2);
				}
			| polynom MINUS polynom
				{
					PolynomMinus($1, $3);
				}
 			| polynom '+' polynom			
 				{
					PolynomSummary($1, $3); 				
 				}
			| polynom '*' polynom
				{
					$$ = PolynomMultiple($1, $3);
				}
			| VAR
				{
					$$ = GetPolynom($1);
				}
			| VAR '^' power
				{
					$$ = GetPolynom($1);
					$$ = PolynomPower($$, $3);
				}
 			| monom 							
 				{	
 					$$ = PolynomInit();
 					AddMonom($$, $1, 0);
 				}
 			;

brackets 	: '(' polynom ')'
				{
					$$ = $2;
				}
			| brackets '^' power
				{
					$$ = PolynomPower($1, $3);
				}
			;

 monom 		: symbol
				{
					$$ = $1;
				}
			| symbol monom
				{
					$$ = MonomialMultipl($1, $2);;
				}
 			;

power 		: NUMBER
				{
					$$ = $1;
				}
			| power '+' power
				{
					$$ = $1 + $3;
				}
			| power MINUS power
				{
					$$ = $1 - $3;
				}
			| power '*' power
				{
					$$ = Helper::MultipleNumbers($1,$3);
				}
			| power '^' power 
				{
					$$ = Helper::Pow($1, $3);
				}
			| MINUS power %prec NEG	
				{
					Helper::PrintError("Negative power not supposed");
					$$ = 0 - $2;
				}
			| '(' power ')'
				{
					$$ = $2;
				}
			;

symbol		: NUMBER
				{
					$$ = MonomialInit(0, 1, $1);
					;
				}
			| LITERAL
 				{
 					$$ = MonomialInit($1, 1, 1);
 				}
			| PRINT
				{
					Helper::PrintError("Incorrect assignment");
				}
			| symbol '^' power
				{
					//printf("symbol '^' power\n");
					MonomlPower($1, $3);
				}

%%                     /* C code */


int main (void) {
	/* init symbol table */
	int i;
	
	
	return yyparse ();
}




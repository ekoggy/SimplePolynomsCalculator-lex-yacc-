%{
#include "grammar.h"
void yyerror (char *s);
int yylex();
%}

%union {
	int 	num; 
	int 	*piece_formula;
	char 	symbol; 
	struct 	Expression *formula;
	}    

%start begin
%token PRINT TMINUS
%token END_OF_LINE END_OF_FILE

%token <num> NUMBER

%token <symbol> VAR LITERAL SIGN

%type <formula> polynom  
%type <formula> brackets

%type <num> power
%type <num> begin 
%type <num> line 
%type <num> errors

%type <piece_formula> monom 
%type <piece_formula> symbol

%type <symbol> assignment

%left '+' 
%left NEG
%left TMINUS
%left '*'
%right '^'
%left '(' ')'


%%
begin:		line END_OF_LINE begin			{;} 
			| line END_OF_LINE				{;}
			| END_OF_LINE begin				{;}
			| line END_OF_FILE				{exit(-1);}
			;

line:		assignment END_OF_LINE					{;}
			| PRINT VAR END_OF_LINE			{ 
												int idx = CharSymbolToIndex($2);
												PrintPolynom(idx);
											}
			;

assignment: VAR '=' polynom 				{
												int idx = CharSymbolToIndex($1);
												AssignmentPolynom($1, $3);
											}
			| errors						{;}
			;

errors: 	VAR '='							{
												PrintError("Error initialization");
												exit(-1);
											}
			;

polynom: 	TMINUS polynom %prec NEG		{
												$$ = PolynomInit();
												PolynomMinus($$, $2);
											} 
			| brackets						{$$ = $1;}
			| brackets brackets %prec '*'	{$$ = PolynomMultiple($1, $2);}//объявление что опрерация ()() == умножение
			| polynom TMINUS polynom		{PolynomMinus($1, $3);}
 			| polynom '+' polynom			{PolynomSummary($1, $3);}
			| polynom '*' polynom			{$$ = PolynomMultiple($1, $3);}
			| VAR							{$$ = GetPolynom($1);}
			| VAR '^' power					{
												$$ = GetPolynom($1);
												$$ = PolynomPower($$, $3);
											}
 			| monom 						{	
 												$$ = PolynomInit();
 												AddMonom($$, $1, 0);
 											}
 			;

brackets: 	'(' polynom ')'					{$$ = $2;}
			| brackets '^' power			{$$ = PolynomPower($1, $3);}
			;

 monom: 	symbol							{$$ = $1;}
			| symbol monom					{$$ = MonomialMultipl($1, $2);}
 			;

power: 		NUMBER							{$$ = $1;}
			| power '+' power				{$$ = $1 + $3;}
			| power TMINUS power			{$$ = $1 - $3;}
			| power '*' power				{$$ = MultipleNumbers($1,$3);}
			| power '^' power 				{$$ = Pow($1, $3);}
			| TMINUS power %prec NEG		{
												PrintError("Negative power not supposed");
												$$ = 0 - $2;
											}
			| '(' power ')'					{$$ = $2;}
			;

symbol: 	NUMBER							{$$ = MonomialInit(0, 1, $1);}
			| LITERAL						{$$ = MonomialInit($1, 1, 1);}
			| PRINT							{PrintError("Incorrect assignment");}
			| symbol '^' power				{MonomlPower($1, $3);}

%%                 


int main (void) {
	return yyparse ();
}





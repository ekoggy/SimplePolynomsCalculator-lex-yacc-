#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef unsigned short BOOL;
typedef struct Expression Expr;
typedef struct Polynom Poly;

struct Polynom{
    int coef;
    char var_string[25];
    int power;
    char next_sign;
    char prev_sign;

    Poly *next;
    Poly *prev;
};

struct Expression{
    char var;
    int coef;
    Poly Polynom;
    int power;

    Expr *next;
    Expr *prev;
};

void printError	(const char *, const char *);
void add_to_variables(char, Expr);
void print_expression(Expr*);
Expr* sum_expression(Expr, Expr);
Expr* sub_expression(Expr, Expr);
Expr* mul_expression(Expr, Expr);
Expr* pow_expression(Expr, int);
Expr* some_action2(Expr);
Expr* get_expression(char);
Expr* add_to_expression(Poly);
Poly* sum_polynoms(Poly, Poly);
Poly* sub_polynoms(Poly, Poly);
Poly* add_to_polynoms(char string[100]);
Poly* some_action(Poly);
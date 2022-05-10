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
    char sign;

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

extern Expr * expr_list = NULL;
void printError	(const char *, const char *);
void add_to_expression_list(char, Expr);
void print_expression(Expr*);
Expr* sum_expression(Expr*, Expr*);
Expr* sub_expression(Expr*, Expr*);
Expr* mul_expression(Expr*, Expr*);
Expr* pow_expression(Expr*, int);
Expr* try_to_calculate_expression(Expr*);
Expr* get_expression(char);
Expr* get_mul_expression(char, int);
Expr* add_to_expression(Poly*);
Poly* create_polynom(char string[1000]);
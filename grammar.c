#define _CRT_SECURE_NO_WARNINGS

#include "grammar.h"

extern int gLineNum;

void printError	(const char *s1, const char *s2){
	printf("ERROR in line %d: %s%s\n", gLineNum + 1, s1, s2);
	exit(-1);
}

void add_to_expression_list(char symbol, Expr input){
    printf("add_to_expression_list %c\n", symbol);
}

void print_expression(Expr* expr){
    printf("print_expression\n");
}

Expr* sum_expression(Expr* left, Expr* right){
    printf("sum_expression\n");

    return NULL;
}

Expr* sub_expression(Expr* left, Expr* right){
    printf("sub_expression\n");

    return NULL;
}

Expr* mul_expression(Expr* left, Expr* right){
    printf("mul_expression\n");

    return NULL;
}

Expr* pow_expression(Expr* expr, int power){
    printf("pow_expression %d\n", power);

    return NULL;
}

Expr* try_to_calculate_expression(Expr* expr){
    printf("try_to_calculate_expression\n");

    return NULL;
}

Expr* get_expression(char variable){
    printf("get_expression %c\n", variable);

    return NULL;
}

Expr* add_to_expression(Poly* polynom){
    printf("add_to_expression\n");

    return NULL;
}

Poly* create_polynom(char string[1000]){
    printf("create_polynom %s\n", string);

    return NULL;
}

Expr* get_mul_expression(char var, int mul){
    printf("get_mul_expression %c %d\n", var, mul);

    return NULL;
}

#define _CRT_SECURE_NO_WARNINGS

#include "grammar.h"

extern int gLineNum;
#define bool char
#define false 0
#define true 1

Expr* gVariableList = NULL;

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


// void addVariableToList(char letter, poly polynom)
// {
// 	expr* var = (expr *)malloc(sizeof(expr));
// 	var->var = letter;
// 	var->polynom = polynom;
// 	var->next = NULL;
// 	var->prev = NULL;

// 	if (gVariableList == NULL)
// 	{
// 		gVariableList = var;
// 		return;
// 	}

// 	expr *varList = gVariableList;
// 	for (; varList->next != NULL; varList = varList->next)
// 	{
// 		if (varList->var == letter)
// 		{
// 			varList->polynom = polynom;
// 			return;
// 		}
// 	}

// 	if (varList->var == letter)
// 	{
// 		varList->polynom = polynom;
// 		return;
// 	}

// 	var->prev = varList;
// 	varList->next = var;
// }

// poly* getVariable(char variable)
// {
// 	expr* varList = gVariableList;
// 	while (varList != NULL)
// 	{
// 		if (varList->var == variable)
// 		{
// 			return &(varList->polynom);
// 		}
// 		varList = varList->next;
// 	}
// 	printError("Not initialize variable ", variable);
// }

// poly* initPolynom(void)
// {
// 	poly *result = (poly *)malloc(sizeof(poly));

// 	result->begin = (struct Node *) malloc(sizeof(struct Node));
// 	result->begin->prev = NULL;
// 	result->begin->next = NULL;
// 	result->count = 0;

// 	return result;
// }

// poly* addMononomToPolynom(poly polynom, mono mononom)
// {
// 	struct Node * node;
// 	poly *result = (poly *)malloc(sizeof(poly));

// 	node = polynom.begin;

// 	if (polynom.count == 0)
// 	{
// 		node->item = mononom;
// 		polynom.count++;
// 		(*result) = polynom;
// 		return result;
// 	}

// 	while (node->next != NULL)
// 	{
// 		node = node->next;
// 	}

// 	node->next = (struct Node *)malloc(sizeof(struct Node));
// 	node->next->prev = node;
// 	node->next->next = NULL;
// 	node = node->next;
// 	node->item = mononom;

// 	polynom.count++;
// 	(*result) = polynom;
// 	return result;
// }

// struct Node * deleteNode(poly *polynom, struct Node *node)
// {
// 	struct Node * result = node;

// 	if (polynom->begin == node)
// 	{
// 		if (node->next == NULL)
// 		{
// 			free(node);
// 			return NULL;
// 		}

// 		node->next->prev = NULL;
// 		result = node->next;
// 		free(node);

// 		polynom->begin = result;
// 		return result;
// 	}

// 	if (node->next == NULL)
// 	{
// 		node->prev->next = NULL;
// 		result = node->prev;

// 		free(node);
// 		return result;
// 	}

// 	node->next->prev = node->prev;
// 	node->prev->next = node->next;
// 	result = node->prev;
// 	free(node);
// 	return result;
// }

// poly * deleteSimilarSummands(poly polynom)
// {
// 	poly * result = initPolynom();
// 	for (struct Node *i = polynom.begin; i != NULL;)
// 	{
// 		mono mononom = i->item;
// 		for (struct Node *j = polynom.begin; j != NULL; j = j->next)
// 		{
// 			if (strncmp(i->item.var, j->item.var, 32) == 0 &&
// 				i->item.power == j->item.power &&
// 				i != j)
// 			{
// 				mononom.coef += j->item.coef;
// 				if (mononom.coef == 0)
// 				{
// 					mononom.power = 0;
// 					strncpy(mononom.var, "", 32);
// 				}

// 				j = deleteNode(&polynom, j);
// 			}
// 		}

// 		i = deleteNode(&polynom, i);
// 		poly *freePtr = result;
// 		result = addMononomToPolynom(*result, mononom);
// 		free(freePtr);
// 	}

// 	return result;
// }

// poly* sumPolynoms(poly p1, poly p2)
// {
// 	for (struct mono* i = p1.head; i != NULL; i = i->next)
// 	{
// 		char varI[32] = {0};
// 		strncpy(varI, i->item.variable, 32);
// 		for (struct Node* j = p2.begin; j != NULL; j = j->next)
// 		{
// 			char varJ[32] = {0};
// 			strncpy(varJ, j->item.variable, 32);

// 			if (strncmp(varI, varJ, 32) != 0 && strncmp(varI, "", 32) != 0 && strncmp(varJ, "", 32) != 0)//Если переменные не совпадают и ни одна из переменных не является числом, то ошибка
// 			{
// 				printError("different variables in polynom", "");
// 			}
// 		}
// 	}

// 	poly *result = (poly *)malloc(sizeof(poly));
// 	(*result) = p1;
// 	poly *freePtr;
// 	for (struct Node *node = p2.begin; node != NULL; node = node->next)
// 	{
// 		freePtr = result;
// 		result = addMononomToPolynom(*result, node->item);
// 		free(freePtr);
// 	}

// 	freePtr = result;
// 	result = deleteSimilarSummands(*result);
// 	free(freePtr);
// 	return result;
// }

// poly * subPolynoms(poly p1, poly p2)
// {
// 	for (struct Node *i = p1.begin; i != NULL; i = i->next)
// 	{
// 		for (struct Node *j = p2.begin; j != NULL; j = j->next)
// 		{
// 			char varI[32] = {0};
// 			strncpy(varI, i->item.variable, 32);
// 			char varJ[32] = {0};
// 			strncpy(varJ, j->item.variable, 32);

// 			if (strncmp(varI, varJ, 32) != 0 && strncmp(varI, "", 32) != 0 && strncmp(varJ, "", 32) != 0) //Если переменные не совпадают и ни одна из переменных не является числом, то
// 			{
// 				printError("different variables in polynom", "");
// 			}
// 		}
// 	}

// 	poly *minusP2 = unaryMinus(&p2);///////////
// 	poly * result = sumPolynoms(p1, *minusP2);
// 	result = deleteSimilarSummands(*result);

// 	return result;
// }

// poly * mulPolynoms(poly p1, poly p2)
// {
// 	poly * result = initPolynom();
		
// 	for (struct Node *i = p1.begin; i != NULL; i = i->next)
// 	{
// 		for (struct Node *j = p2.begin; j != NULL; j = j->next)
// 		{
// 			mono mononom = i->item;

// 			mononom.coef *= j->item.coef;

// 			bool IisNumber = (strncmp(mononom.variable, "", 32) == 0);
// 			bool JisNumber = (strncmp(j->item.variable, "", 32) == 0);
// 			bool varMatch = (strcmp(mononom.variable, j->item.variable) == 0);

// 			if (!IisNumber && varMatch) //у обоих одинаковая переменная
// 			{
// 				mononom.power += j->item.power;
// 			}
// 			else if (IisNumber && !JisNumber)//У мононома нет переменной, у второго есть
// 			{
// 				strncpy(mononom.variable, j->item.variable, 32);
// 				mononom.power += j->item.power;
// 				}
// 			else if (!IisNumber && !JisNumber && !varMatch)//у обоих разные переменные
// 			{
// 				printError("different variables in polynom", "");
// 			}

// 			if (mononom.coef == 0)
// 			{
// 				strncpy(mononom.variable, "", 32);
// 				mononom.power = 0;
// 			}

// 			poly *freePtr = result;
// 			result = addMononomToPolynom(*result, mononom);
// 			free(freePtr);
// 		}
// 	}

// 	poly *freePtr = result;
// 	result = deleteSimilarSummands(*result);
// 	free(freePtr);
// 	return result;
// }

// void printMononom(mono *mononom)
// {
// 	if (!strcmp(mononom->var, ""))
// 	{
// 		printf("%d", mononom->coef);
// 	}
// 	else
// 	{
// 		if (abs(mononom->coef) == 1)
// 		{
// 			if (mononom->coef == -1)
// 			{
// 				printf("-");
// 			}
// 			if (mononom->power == 1)
// 			{
// 				printf("%s", mononom->var);
// 			}
// 			else
// 			{
// 				printf("%s^%d", mononom->var, mononom->power);
// 			}
// 		}
// 		else
// 		{
// 			if (mononom->power == 1)
// 			{
// 				printf("%d%s", mononom->coef, mononom->var);
// 			}
// 			else
// 			{
// 				printf("%d%s^%d", mononom->coef, mononom->var, mononom->power);
// 			}
// 		}
// 	}
// }

// void printPolynom(poly *polynom)
// {
// 	struct Node *begin = polynom->begin;
// 	printf("= ");
	
// 	while (begin->item.coef == 0 && begin->next != NULL)
// 	{
// 		begin = begin->next;
// 	}

// 	int itemNum = 0;
// 	for (struct Node *node = begin; node != NULL; node = node->next)
// 	{
// 		itemNum++;
// 	}

// 	bool *itemWasPrinted = (bool *)calloc(sizeof(bool), itemNum);

// 	char varName[32] = { 0 };
// 	for (struct Node *node = begin; node != NULL; node = node->next)
// 	{
// 		if (strncmp(node->item.variable, "", 32) != 0)//Если это не число
// 		{
// 			strncpy(varName, node->item.variable, 32);	
// 		}
// 	}

// 	bool firstWasPrinted = false;
// 	//Вывести все одночлены с этой переменной
// 	for (int i = 0; i < itemNum; i++)
// 	{
// 		//Найти самую старшую невыведенную степень
// 		int maxPower = 0;
// 		int currentItemIndex = 0;
// 		int itemIndex = 0;
// 		struct Node *result = begin;
// 		for (struct Node *node = begin; node != NULL; node = node->next)
// 		{
// 			if (strncmp(node->item.variable, varName, 32) == 0 && //Если совпадает имя переменной
// 				!itemWasPrinted[currentItemIndex] &&					  //Эта переменная не была выведена
// 				node->item.power > maxPower)					  //Cтепень выше других
// 			{
// 				result = node;
// 				maxPower = node->item.power;
// 				itemIndex = currentItemIndex;
// 			}

// 			currentItemIndex++;
// 		}

// 		if (maxPower != 0)//Если был найден хоть один подходящий элемент, то
// 		{
// 			//Вывести найденный элемент
// 			if (firstWasPrinted && result->item.coef > 0)//Если уже были выведены значения и коэффициент положительный
// 			{
// 				printf("+");
// 			}

// 			firstWasPrinted = true;
// 			printMononom(&result->item);
// 			itemWasPrinted[itemIndex] = true;
// 		}
// 		else
// 		{
// 			break;//Если нового невыведенного элемента не было найдено, то можно перейти к следующей переменной
// 		}
// 	}
	
// 	//Вывести константное значение
// 	for (struct Node *node = begin; node != NULL; node = node->next)
// 	{
// 		if (strncmp(node->item.variable, "", 32) == 0 && node->item.coef != 0)
// 		{
// 			if (firstWasPrinted && node->item.coef > 0) //Если уже были выведены значения и коэффициент положительный
// 			{
// 				printf("+");
// 			}

// 			firstWasPrinted = true;
// 			printMononom(&node->item);
// 			break;
// 		}
// 	}

// 	//Вывести 0, если совсем ничего не было выведено
// 	if (!firstWasPrinted)
// 	{
// 		printf("0");
// 	}
// 	printf(".\n");
// }

// void yyerror(char const *s)
// {
// 	printf("ERROR in line %d: '%s'\n", gLineNum + 1, s);
// }

// void printError(const char *s1, const char *s2)
// {
// 	printf("ERROR in line %d: %s%s\n", gLineNum + 1, s1, s2);
// 	exit(-1);
// }
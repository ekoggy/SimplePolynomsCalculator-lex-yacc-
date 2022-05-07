//основная идея в том, чтобы в любом случае считать переменными
//будет массив переменных из 24 элементов, каждый из которых содержит полином
//кроме него будет линейный список - выражение
//программа будет идти по списку со второго элемента до предпоследнего, смотреть пердыдущий знак и следующий
//если текущее действие (предыдущий знак) приоритетнее, то два полинома сливаются и вырезается один элемент
//из списка, изменяются знаки, заносится новая переменная, изменяется выражение, проход начинается сначала(???)
//так пока не останется один единственный элемент

//считывание
//если не поступает конкретной переменной, например, А, то полином заносится под ближайшую свободную (первый свободный индекс)
//иначе полином запихивается в конкретную ячейку
//далее его переменная заносится в ВЫРАЖЕНИЕ
//при получении знака, программа заносит его в выражение как следующий для последнего добавленного элемента
//а также создаёт новый элемент и записывает знак в предыдущий

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)
typedef unsigned short bool;

struct polynom{
    char **monoms;// матрица, а точнее массив строк вида "a", "abc", "a^2b^2c^v"
    int *coefs; // массив коэфициентов для выше указанных значений
    int amount_monoms;
    void input(){
        //функция добавление выше указанного чуда
    };

    void print(){
        //функция вывода выше указанного чуда, для отладки и выводы ответа
    };
};
typedef struct polynom poly;


struct expression{
    int prev_sign;
    int next_sign;
    poly var;

    struct expression *next_var;
    struct expression *prev_var;
};
typedef struct expression expr;

poly variables[24];

bool find_monom(char *monom, char **list_monoms, int amount_strs){
    for(int i = 0; i < amount_strs; i++)
        if(!strcmp(monom,list_monoms[i]))
            return TRUE;
    return FALSE;
}

poly summation(poly left, poly right){
    poly new_polynom = {NULL, NULL, 0};

    for(int i = 0; i < left.amount_monoms; i++){
       //заносим строчку монома в новый полином
        if(find_monom(left.monoms[i],right.monoms,right.amount_monoms)){
            //работа с коэфициентами
        }
        else{
            //просто вносим коэфицент
        }
    }

    for(int i = 0; i < right.amount_monoms; i++){
       //заносим строчку монома в новый полином
        //заносим коэф
    }
    return new_polynom;
}

poly subtraction(poly left, poly right){
    poly new_polynom = {NULL, NULL, 0};

    for(int i = 0; i < left.amount_monoms; i++){
       //заносим строчку монома в новый полином
        if(find_monom(left.monoms[i],right.monoms,right.amount_monoms)){
            //работа с коэфициентами
        }
        else{
            //просто вносим коэфицент
        }
    }

    for(int i = 0; i < right.amount_monoms; i++){
       //заносим строчку монома в новый полином
        //заносим коэф со знаком "-"
    }
    return new_polynom;
}

poly multiplication(poly left, poly right){
    poly new_polynom = {NULL, NULL, 0};

    for(int i = 0; i < left.amount_monoms; i++){
       for(int j = 0; j < right.amount_monoms; i++){
           //перемножение каждого на каждый
           //то есть перемножение коэфициентов и парсинг строк
           //парсинг строчек посимвольно
           //если есть две одинаковых переменных то заносим степень на 1 больше бывшей
           //если нет - просто приклеиваем
       }
    }
    return new_polynom;
}
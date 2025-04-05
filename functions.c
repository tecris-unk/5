//
// Created by intak on 01.04.2025.
//

#include "functions.h"
void setNumber(int* number)
{
    rewind(stdin);
    *number = 0;
    int digit;
    while((digit = getchar()) != '\n' && digit != ' ')
    {
        if(digit < '0' || digit > '9'){
            printf("Incorrect number\n");
            while((digit = getchar()) != '\n' && digit != ' ');
            *number = 0;
        }
        else{*number = *number * 10 + digit - '0';}
    }
    rewind(stdin);
}
int getAnswer()
{
    printf("\nYES - 1, NO - 0\n");
    int ch = getch();
    if(ch == '1'){return 1;}
    if(ch == '0'){return 0;}
}
int max(int first, int second)
{
    return first > second ? first : second;
}
int min(int first, int second)
{
    return first < second ? first : second;
}

Stack* push(Stack* top, int data, int *size, int maxSize, int order)
{
    if(size != NULL && *size == maxSize)
    {
        printf("You cant add more elements, looser lol\n");
        return top;
    }
    else if(top != NULL && ((order == 1 && data > top->data) || (order == 2 && data < top->data))){
        printf("You cant add this element\n");
        return top;
    }
    else if(size != NULL){(*size)++;}
    Stack* ptr = malloc(sizeof(Stack));
    if(ptr == NULL){
        fprintf(stderr, "malloc fail\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = top;
    return ptr;
}
Stack* pop(Stack* top)
{
    if(top == NULL){return top;}
    Stack* next = top->next;
    free(top);
    return next;
}
void show(Stack* top)
{
    if(top == NULL){return;}
    printf("%d\n", top->data);
    show(top->next);
}
int findMax(Stack* top, int max)
{
    if(top != NULL)
    {
        if(top->data > max){
            max = top->data;
        }
        max = findMax(top->next, max);
    }
    return max;
}

Stack* reverseStack(Stack* stack)
{
    Stack* resultStack = NULL;
    Stack* tempStack = stack;
    while (tempStack != NULL) {
        resultStack = push(resultStack, tempStack->data, NULL, 0, 0);
        tempStack = tempStack->next;
    }
    return resultStack;
}
Stack* mergeStacks(Stack* stack1, Stack* stack2) {

    if (stack1 == NULL && stack2 == NULL) {
        return NULL;
    }
    int data1 = (stack1 != NULL) ? stack1->data : INT_MIN;
    int data2 = (stack2 != NULL) ? stack2->data : INT_MIN;

    Stack* nextStack1 = (stack1 != NULL) ? stack1->next : NULL;
    Stack* nextStack2 = (stack2 != NULL) ? stack2->next : NULL;

    Stack* resultStack = NULL;

    if(data1 >= data2){
        resultStack = push(resultStack, data1, NULL, 0, 0);
        resultStack->next = mergeStacks(nextStack1, stack2);
    }
    else{
        resultStack = push(resultStack, data2, NULL, 0, 0);
        resultStack->next = mergeStacks(stack1, nextStack2);
    }
    return resultStack;
}

CharStack *charPush(CharStack *s, char c)
{
    CharStack *new = malloc(sizeof(CharStack));
    if(new == NULL){
        fprintf(stderr, "malloc fail\n");
        exit(1);
    }
    new->data = c;
    new->next = s;
    return new;
}

CharStack *charPop(CharStack *s)
{
    if (s != NULL) {
       CharStack* new = s->next;
       free(s);
       return new;
    }
    return NULL;
}

char charPeek(CharStack *s)
{
    if (s!=NULL) {
        return s->data;
    }
    return '\0';
}

DoubleStack* doublePush(DoubleStack *stack, double data)
{
    DoubleStack* ptr = malloc(sizeof(DoubleStack));
    if(ptr == NULL){
        fprintf(stderr, "malloc fail\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = stack;
    return ptr;
}

DoubleStack *doublePop(DoubleStack *s)
{
    if (s!=NULL) {
        DoubleStack *new = s->next;
        free(s);
        return new;
    }
    return NULL;
}
double doublePeek(DoubleStack *s)
{
    if (s!=NULL) {
        return s->data;
    }
    return 0.0;
}
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op)
{
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

int isDigitOrDot(char c)
{
    return isdigit(c) || c == '.';
}


double evaluateExpression(const char *expr, int *errorPos)
{
    CharStack *opStack = NULL;
    DoubleStack *valStack = NULL;


    int i = 0;
    unsigned int len = strlen(expr);
    int unary = 1;

    while (i < len) {
        if (expr[i] == ' ') {
            i++;
            continue;
        }

        if (isDigitOrDot(expr[i])) {
            char numStr[32];
            int j = 0;
            int dotCount = 0;

            while (i < len && isDigitOrDot(expr[i])) {
                if (expr[i] == '.') {
                    if (++dotCount > 1) {
                        *errorPos = i;
                        return 0;
                    }
                }
                numStr[j++] = expr[i++];
            }
            numStr[j] = '\0';

            double num = atof(numStr);
            valStack = doublePush(valStack, num);
            unary = 0;
            continue;
        }


        if (expr[i] == '(') {
            opStack = charPush(opStack, expr[i]);
            i++;
            unary = 1;
            continue;
        }

        if (expr[i] == ')') {
            while (opStack!=NULL && charPeek(opStack) != '(') {
                char op = charPeek(opStack);
                opStack = charPop(opStack);
                double b = doublePeek(valStack);
                valStack = doublePop(valStack);
                double a = doublePeek(valStack);
                valStack = doublePop(valStack);
                switch (op) {
                    case '+': valStack = doublePush(valStack, a + b); break;
                    case '-': valStack = doublePush(valStack, a - b); break;
                    case '*': valStack = doublePush(valStack, a * b); break;
                    case '/':
                        if (b == 0) {
                            *errorPos = i;
                            return 0;
                        }
                        valStack = doublePush(valStack, a / b);
                        break;
                }
            }

            if (opStack == NULL) {
                *errorPos = i;
                while(valStack != NULL)
                {
                    valStack = doublePop(valStack);
                }
                return 0;
            }
            opStack = charPop(opStack);
            i++;
            unary = 0;
            continue;
        }


        if (isOperator(expr[i])) {

            if (expr[i] == '-' && unary) {
                valStack = doublePush(valStack, 0);
            }

            while (opStack!=NULL &&
                   charPeek(opStack) != '(' &&
                   precedence(charPeek(opStack)) >= precedence(expr[i])) {
                char op = charPeek(opStack);
                opStack = charPop(opStack);
                double b = doublePeek(valStack);
                valStack = doublePop(valStack);
                double a = doublePeek(valStack);
                valStack = doublePop(valStack);
                switch (op) {
                    case '+': valStack = doublePush(valStack, a + b); break;
                    case '-': valStack = doublePush(valStack, a - b); break;
                    case '*': valStack = doublePush(valStack, a * b); break;
                    case '/':
                        if (b == 0) {
                            *errorPos = i;
                            return 0;
                        }
                        valStack = doublePush(valStack, a / b);
                        break;
                }
            }
            opStack = charPush(opStack, expr[i]);
            i++;
            unary = 1;
            continue;
        }
        printf("%c", expr[i]);
        *errorPos = i;
        return 0;
    }

    // Обработка оставшихся операторов
    while (opStack!=NULL) {
        char op = charPeek(opStack);
        opStack = charPop(opStack);
        if (op == '(') {
            *errorPos = i;
            return 0;
        }

        double b = doublePeek(valStack);
        valStack = doublePop(valStack);
        double a = doublePeek(valStack);
        valStack = doublePop(valStack);

        switch (op) {
            case '+': valStack = doublePush(valStack, a + b); break;
            case '-': valStack = doublePush(valStack, a - b); break;
            case '*': valStack = doublePush(valStack, a * b); break;
            case '/':
                if (b == 0) {
                    *errorPos = i;
                    return 0;
                }
                valStack = doublePush(valStack, a / b);
                break;
        }
    }
    double answer = doublePeek(valStack);
    valStack = doublePop(valStack);
    if (valStack != NULL) {
        *errorPos = i;
        while(valStack != NULL)
            valStack = doublePop(valStack);
        return 0;
    }
    return answer;
}

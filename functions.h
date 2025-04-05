//
// Created by intak on 01.04.2025.
//

#ifndef INC_5_FUNCTIONS_H
#define INC_5_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "stack.h"
#include "myString.h"


void setNumber(int* number);
int getAnswer();
int max(int first, int second);
int min(int first, int second);

Stack* push(Stack* top, int data, int *size, int maxSize, int order);
Stack* pop(Stack* top);
void show(Stack* top);
int findMax(Stack* top, int max);
Stack* reverseStack(Stack* stack);
Stack* mergeStacks(Stack* stack1, Stack* stack2);


CharStack *charPush(CharStack *s, char c);
CharStack *charPop(CharStack *s);
char charPeek(CharStack *s);
DoubleStack* doublePush(DoubleStack *stack, double data);
DoubleStack *doublePop(DoubleStack *s);
double doublePeek(DoubleStack *s);
int isOperator(char c);
int precedence(char op);
int isDigitOrDot(char c);
double evaluateExpression(const char *expr, int *errorPos);

void createAndFindMaxInStack();
void uniteAndSortTwoStacks();
void mathExpressions();

#endif //INC_5_FUNCTIONS_H

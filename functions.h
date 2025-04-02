//
// Created by intak on 01.04.2025.
//

#ifndef INC_5_FUNCTIONS_H
#define INC_5_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>

#include "stack.h"
#include "myString.h"
void setNumber(int* number);
int getAnswer();
int max(int first, int second);
int min(int first, int second);

Stack* push(Stack* top, int data, int*size, int maxSize);
Stack* pop(Stack* top);
void show(Stack* top);
int findMax(Stack* top, int max);
int getLast(Stack* stack, int last);
Stack* mergeStacks(Stack* stack1, Stack* stack2);

void createAndFindMaxInStack();
void uniteAndSortTwoStacks();
void mathExpressions();
#endif //INC_5_FUNCTIONS_H

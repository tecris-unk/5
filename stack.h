//
// Created by intak on 01.04.2025.
//

#ifndef INC_5_STACK_H
#define INC_5_STACK_H

typedef struct obj {
    int data;
    struct obj* next;
} Stack;

typedef struct ch{
    char data;
    struct ch* next;
} CharStack;

// Структура стека для чисел
typedef struct db{
    double data;
    struct db* next;
} DoubleStack;

#endif //INC_5_STACK_H

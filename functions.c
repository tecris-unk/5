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

Stack* push(Stack* top, int data, int *size, int maxSize)
{
    if(size != NULL && *size == maxSize)
    {
        printf("You cant add more elements, looser lol\n");
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
        resultStack = push(resultStack, tempStack->data, NULL, 0);
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
        resultStack = push(resultStack, data1, NULL, 0);
        resultStack->next = mergeStacks(nextStack1, stack2);
    }
    else{
        resultStack = push(resultStack, data2, NULL, 0);
        resultStack->next = mergeStacks(stack1, nextStack2);
    }
    return resultStack;
}

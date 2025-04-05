//
// Created by intak on 01.04.2025.
//

#include "functions.h"

void createAndFindMaxInStack()
{
      printf("Enter max size of the stack\n");
      int maxSize, size = 0;
      setNumber(&maxSize);

      Stack* stack;
      stack = NULL;

      // МЕНЮШКА
      printf(
             "1 - add object in stack\n"
             "2 - show full stack\n"
             "3 - find max element\n"
             "4 - Exit task\n"
     );
      while(1)
      {
         printf("what would you like to do\n");
         int ch = getch();
         switch(ch)
         {
             case '1':
                 printf("\nEnter new element\n");
                 int data;
                 setNumber(&data);
                 stack = push(stack, data, &size, maxSize);
                 break;
             case '2':
                 printf("\nHere is your full stack\n");
                 show(stack);
                 break;
             case '3':
                 printf("\nHere is your max element: %d\n", findMax(stack, INT_MIN));
                 break;
             case '4':
                 while(stack != NULL)
                     stack = pop(stack);
                 return;
             default:
                 printf("There is no this case, try again\n");
                 continue;
         }
      }
}
void uniteAndSortTwoStacks()
{
    printf("Enter ONE max size of two stacks\n");
    int maxSize, size1 = 0, size2 = 0;
    setNumber(&maxSize);

    Stack *stack1, *stack2, *stack3 = NULL;
    stack1 = NULL;
    stack2 = NULL;

    // МЕНЮШКА
    printf(
            "1 - add object in first stack\n"
            "2 - add object in second stack\n"
            "3 - unite and show full stack\n"
            "4 - Exit task\n"
    );
    while(1)
    {
        printf("what would you like to do\n");
        int ch = getch();
        int data;
        switch(ch)
        {
            case '1':
                printf("Enter new element for first stack\n");
                setNumber(&data);
                stack1 = push(stack1, data, &size1, maxSize);
                break;
            case '2':
                printf("Enter new element for second stack\n");
                setNumber(&data);
                stack2 = push(stack2, data, &size2, maxSize);
                break;
            case '3':
                stack3 = mergeStacks(reverseStack(stack1), stack2);
                printf("Here is united sorted stack: \n");
                show(stack3);
                break;
            case '4':
                while(stack1 != NULL)
                    stack1 = pop(stack1);
                while(stack2 != NULL)
                    stack2 = pop(stack2);
                return;
            default:
                printf("There is no this case, try again\n");
                continue;
        }
    }
}
void mathExpressions()
{

}
#include "functions.h"

int main(void) {
    while(1)
    {

        printf("Enter task number: ");
        int choice = getch();
        system("cls");
        switch(choice)
        {
            case '1':
                createAndFindMaxInStack();
                break;
            case '2':
                uniteAndSortTwoStacks();
                break;
            case '3':
                mathExpressions();
                break;
            default:
                printf("There is no this task, try again\n");
                continue;
        }
        printf("Do you want to continue? ");
        if(!getAnswer()){return 0;}
        system("cls");
    }
    return 0;
}

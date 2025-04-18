//Андрей Ивашнев 02.04
//1. Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти
//максимальный элемент стека.

//4. Создать два стека для целых чисел. Первый стек – организовать ввод по убыванию, второй
//стек – организовать ввод по возрастанию. Без сортировок и переворачивания исходных
//стеков сформировать третий стек упорядоченный по убыванию

//1. В текстовом файле записаны строки – арифметические выражения. Числа – вещественные,
//знаки действий - -, +, *, / и скобки (). Используя работу со стеками найти значение каждого выражения
//и записать в файл результатов. Если в исходном файле в строке есть ошибка – найти ее предполагаемую
//позицию (позицию первой ошибки) и в выходной файл записать сообщение «Ошибка в позиции N»
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
}

//
// Created by intak on 01.03.2025.
//

#include "mystring.h"
void coutString(char* string)
{
    if(string == NULL){return;}
    for(int i = 0; string[i] != '\0'; ++i)
        printf("%c", string[i]);
}
void strSize(const char *string, int* size)
{
    while(string[*size] != '\0' && string[*size] != EOF)
    {
        (*size)++;
    }
}
void resize(char** array, int size)
{
    char *temp = (char*)realloc(*array, sizeof(temp) * (size+1));
    if(temp == NULL){
        printf("memory cant be allocated\n");
        free(temp);
        exit(1);
    }
    *array = (char*)temp;
    (*array)[size] = '\0';
}
void strCat(char** string, int size, const char* sumString)
{
    int i = 0;
    while(sumString[i]!='\0' && sumString[i] != EOF)
    {
        *string = (char *) realloc(*string, sizeof(char) * (size + i + 2));
        if(*string == NULL){
            printf("mlc fail\n");
            free(*string);
            exit(1);
        }
        (*string)[size+i] = sumString[i];
        (*string)[size+i+1] = '\0';
        i++;
    }
}
int isEqualStr(char* string1, char* string2)
{
    int i = 0;
    while(string1[i] != '\0' && string2[i] != '\0')
    {
        if(string1[i] != string2[i]){return 0;}
        i++;
    }
    if(string1[i] != string2[i]){return 0;}
    return 1;
}
void eraseInString(int *size, char** array, int i, int length)
{
    if(i < 0 || length <= 0) {return;}
    if(i + length > *size){length = *size - i;}

    for (; i + length < *size; ++i)
        (*array)[i] = (*array)[i + length];

    *size -= length;
    resize(array, *size);
}

void scanString(char **string, int *size) {
    *string = NULL;
    *size = 0;

    int capacity = 16;
    *string = (char *)malloc(sizeof(char) * capacity);
    if (*string == NULL) {
        fprintf(stderr, "malloc fail\n");
        exit(1);
    }

    int c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i >= capacity - 1) {
            capacity *= 2;
            char *temp = (char *)realloc(*string, sizeof(char) * capacity);
            if (temp == NULL) {
                fprintf(stderr, "realloc fail\n");
                free(*string);
                exit(1);
            }
            *string = temp;
        }
        (*string)[i++] = (char)c;
        (*string)[i] = '\0';
        *size = i;
    }
}
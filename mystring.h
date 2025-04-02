//
// Created by intak on 01.03.2025.
//

#ifndef INC_2_MYSTRING_H
#define INC_2_MYSTRING_H

#include <stdio.h>
#include <stdlib.h>

void coutString(char* string);
void strSize(const char *string, int* size);
void resize(char** array, int size);
void strCat(char** string, int size, const char* sumString);
void scanString(char **string, int *size);
void eraseInString(int *size, char** array, int i, int length);
int isEqualStr(char* string1, char* string2);

#endif //INC_2_MYSTRING_H

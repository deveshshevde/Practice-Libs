#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

/*
    * Function to compare two strings
*/
int compare_string(const void *a, const void *b);



int compare_string(const void *a, const void *b){
    char *s1 = *(char**)a;
    char *s2 = *(char**)b;
    return strcmp(s1, s2);
}


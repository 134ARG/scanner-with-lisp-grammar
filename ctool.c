//
// Created by xen134 on 21/3/2021.
//

#include "ctool.h"
#include <malloc.h>
#include <string.h>

int islparen(int ch) {
    return ch == '(';
}

int isrparen(int ch) {
    return ch == ')';
}

char *copy_string(const char *str) {
    char *p = malloc(sizeof(char)*(strlen(str)+1));
    strcpy(p, str);
    return p;
}
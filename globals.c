//
// Created by xen134 on 29/3/2021.
//

#include <string.h>
#include "stack.h"
#include "expression.h"
#include "globals.h"


// for scanner (both for script and source file)
int lineno = 0;
char *Text = NULL;

// for sparser
struct stack regex;
struct stack token_names;
char funcodes[][FUNCSIZE] = {"cat", "or", "pls", "mul", "range"};

// initialize global stacks
void init_globals() {
    init_stack(&regex);
    init_stack(&token_names);
}

// free global stacks
void destruct_globals() {
    for (int i = 0; i < regex.length; i++) {
        free_expression(get(&regex, i));
    }
    free_content(&token_names);
    destruct(&regex);
    destruct(&token_names);
}

// get function code by name
int get_funcode(const char *name) {
    for (int i = 0; i < FUNCSIZE; i++) {
        if (!strcmp(name, funcodes[i])) {
            return i;
        }
    }
    return -1;
}
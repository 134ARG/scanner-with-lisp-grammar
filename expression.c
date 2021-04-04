//
// Created by xen134 on 28/3/2021.
//

#include "expression.h"
#include "stack.h"
#include <malloc.h>
#include <string.h>
#include "globals.h"

expression *make_expression(int type, int funcode, void *data) {
    expression *p = malloc(sizeof(struct expression));
    p->funcode = funcode;
    p->type = type;
    p->data.param = data;
    return p;
}

void free_expression(struct expression *p) {
    if (p->type == ATOM) {
        free(p->data.str);
    } else {
        destruct(p->data.param);
        free(p->data.param);
    }
    free(p);
}


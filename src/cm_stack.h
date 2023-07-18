#ifndef CM_STACK_H
#define CM_STACK_H

#include "cm_element.h"


typedef struct {
	cm_element* first;
    cm_element* last;
} cm_stack;

cm_stack* cm_stack_init() {
    cm_stack* s = (cm_stack*)malloc(sizeof(cm_stack));
    s->first = NULL;
    s->last = NULL;
    return s;
}

long long int cm_stack_size(cm_stack* s) {
    cm_element* current = s->first;
    long long int sz = 0;
    while (current) {
        ++sz;
        current = current->next;
    }
    return sz;
}

void cm_stack_push(cm_stack* s, cm_any val) {
    if (!s->first) {
        s->first = cm_element_init(val);
        s->last = s->first;
    } else {
        cm_element* new_element = cm_element_init(val);
        s->last->next = new_element;
        new_element->prev = s->last;
        s->last = new_element;
    }
}

cm_any cm_stack_pop(cm_stack* s) {
    if (!s->last) {
        return cm_any_err();
    }

    cm_element* e = s->last;
    cm_any val = e->value;

    if (s->last == s->first) {
        s->first = NULL;
        s->last = NULL;
    } else {
        s->last = s->last->prev;
        s->last->next = NULL;
    }

    free(e);
    return val;
}

cm_any cm_stack_top(cm_stack* s) {
    if (!s->last) {
        return cm_any_err();
    }

    cm_element* e = s->last;
    cm_any val = e->value;

    return val;
}

#endif // CM_STACK_H

#ifndef CM_STACK_H
#define CM_STACK_H

#include "cm_element.h"


typedef struct {
	cm_element* first;
    cm_element* last;
} cm_stack;

cm_stack* cm_stack_init() {
    cm_stack* stack = (cm_stack*)malloc(sizeof(cm_stack));
    stack->first = NULL;
    stack->last = NULL;
    return stack;
}

long long int cm_stack_size(cm_stack* stack) {
    cm_element* current = stack->first;
    long long int size = 0;
    while (current) {
        ++size;
        current = current->next;
    }
    return size;
}

void cm_stack_push(cm_stack* stack, cm_any* value) {
    if (!stack->first) {
        stack->first = cm_element_init(value);
        stack->last = stack->first;
    } else {
        cm_element* new_element = cm_element_init(value);
        stack->last->next = new_element;
        new_element->prev = stack->last;
        stack->last = new_element;
    }
}

cm_any* cm_stack_pop(cm_stack* stack) {
    if (!stack->last) {
        return cm_any_err();
    }

    cm_element* element = stack->last;
    cm_any* value = element->value;

    if (stack->last == stack->first) {
        stack->first = NULL;
        stack->last = NULL;
    } else {
        stack->last = stack->last->prev;
        stack->last->next = NULL;
    }

    free(element);
    return value;
}

cm_any* cm_stack_top(cm_stack* stack) {
    if (!stack->last) {
        return NULL;
    }

    cm_element* element = stack->last;
    cm_any* value = element->value;

    return value;
}

void cm_stack_free(cm_stack* stack) {
    cm_element* current = stack->first;
    while (current) {
        cm_element* to_free = current;
        current = current->next;
        cm_element_free(to_free);
    }
}

#endif // CM_STACK_H

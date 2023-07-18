#ifndef CM_VECTOR_H
#define CM_VECTOR_H

#include "cm_element.h"


typedef struct {
	cm_element* first;
    cm_element* last;
} cm_vector;

cm_vector* cm_vector_init() {
    cm_vector* v = (cm_vector*)malloc(sizeof(cm_vector));
    v->first = NULL;
    v->last = NULL;
    return v;
}

long long int cm_vector_size(cm_vector* v) {
    cm_element* current = v->first;
    long long int sz = 0;
    while (current) {
        ++sz;
        current = current->next;
    }
    return sz;
}

void cm_vector_push_back(cm_vector* v, cm_any val) {
    if (!v->first) {
        v->first = cm_element_init(val);
        v->last = v->first;
    } else {
        cm_element* new_element = cm_element_init(val);
        v->last->next = new_element;
        new_element->prev = v->last;
        v->last = new_element;
    }
}

cm_any cm_vector_at(cm_vector* v, long long int i) {
    if (i < 0 || i >= cm_vector_size(v)) {
        return cm_any_err();
    }

    cm_element* current = v->first;
    long long int index = 0;

    while (current && index < i) {
        current = current->next;
        index++;
    }

    if (current && index == i) {
        return current->value;
    } else {
        return cm_any_err();
    }
}

#endif // CM_VECTOR_H

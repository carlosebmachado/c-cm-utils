#ifndef CM_VECTOR_H
#define CM_VECTOR_H

#include "cm_element.h"


typedef struct {
	cm_element* first;
    cm_element* last;
} cm_vector;

cm_vector* cm_vector_init() {
    cm_vector* vector = (cm_vector*)malloc(sizeof(cm_vector));
    vector->first = NULL;
    vector->last = NULL;
    return vector;
}

long long int cm_vector_size(cm_vector* vector) {
    cm_element* current = vector->first;
    long long int size = 0;
    while (current) {
        ++size;
        current = current->next;
    }
    return size;
}

void cm_vector_push_back(cm_vector* vector, cm_any* value) {
    if (!vector->first) {
        vector->first = cm_element_init(value);
        vector->last = vector->first;
    } else {
        cm_element* new_element = cm_element_init(value);
        vector->last->next = new_element;
        new_element->prev = vector->last;
        vector->last = new_element;
    }
}

cm_any* cm_vector_at(cm_vector* vector, long long int index) {
    if (index < 0 || index >= cm_vector_size(vector)) {
        return NULL;
    }

    cm_element* current = vector->first;
    long long int curr_index = 0;

    while (current && curr_index < index) {
        current = current->next;
        curr_index++;
    }

    if (current && curr_index == index) {
        return current->value;
    } else {
        return NULL;
    }
}

#endif // CM_VECTOR_H

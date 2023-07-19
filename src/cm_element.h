#ifndef CM_ELEMENT_H
#define CM_ELEMENT_H

#include "cm_any.h"


typedef struct cm_element {
    cm_any value;
    struct cm_element* next;
    struct cm_element* prev;
} cm_element;

cm_element* cm_element_init(cm_any value) {
    cm_element* e = (cm_element*)malloc(sizeof(cm_element));
    e->value = value;
    e->next = NULL;
    e->prev = NULL;
    return e;
}

#endif // CM_ELEMENT_H

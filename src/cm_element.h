#ifndef CM_ELEMENT_H
#define CM_ELEMENT_H

#include "cm_any.h"


typedef struct cm_element {
    cm_any* value;
    struct cm_element* next;
    struct cm_element* prev;
} cm_element;

cm_element* cm_element_init(cm_any* value) {
    cm_element* element = (cm_element*)malloc(sizeof(cm_element));
    element->value = value;
    element->next = NULL;
    element->prev = NULL;
    return element;
}

#endif // CM_ELEMENT_H

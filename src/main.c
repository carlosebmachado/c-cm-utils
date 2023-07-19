#include <stdio.h>
#include <stdlib.h>

#include "cm.h"

void cm_any_print(cm_any any) {
    switch (any.type) {
        case CM_TYPE_ERROR:
            printf("Error value: %d\n", *(int*)any.data);
            break;
        case CM_TYPE_BOOL:
            printf("Bool value: %s\n", *(bool*)any.data ? "true" : "false");
            break;
        case CM_TYPE_INT:
            printf("Integer value: %lld\n", *(long long int*)any.data);
            break;
        case CM_TYPE_FLOAT:
            printf("Float value: %Lf\n", (double)(*(long double*)any.data));
            break;
        case CM_TYPE_CHAR:
            printf("Char value: %c\n", *(char*)any.data);
            break;
        case CM_TYPE_STRING:
            printf("String value: %s\n", (char*)any.data);
            break;
        default:
            printf("Unknown type\n");
    }
}

void vector_print(cm_vector* v) {
    for(int i = 0; i < cm_vector_size(v); ++i) {
        cm_any_print(cm_vector_at(v, i));
    }
}

void stack_print(cm_stack* s) {
    int size = cm_stack_size(s);
    for(int i = 0; i < size; ++i) {
        cm_any_print(cm_stack_pop(s));
    }
}

int main() {
    cm_vector* v = cm_vector_init();
    cm_vector_push_back(v, cm_any_int(10));
    cm_vector_push_back(v, cm_any_int(9));
    cm_vector_push_back(v, cm_any_string("foo"));

    printf("Full vector:\n");
    vector_print(v);
    printf("\n");

    printf("Print out of bound:\n");
    cm_any_print(cm_vector_at(v, 3));

    printf("\n-----------------\n\n");

    cm_stack* s = cm_stack_init();
    cm_stack_push(s, cm_any_int(10));
    cm_stack_push(s, cm_any_int(9));
    cm_stack_push(s, cm_any_string("foo"));

    printf("Full stack:\n");
    stack_print(v);
    printf("\n");

    printf("Stack after print:\n");
    stack_print(v);

    return 0;
}

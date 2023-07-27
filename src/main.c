#include <stdio.h>
#include <stdlib.h>

#include "cm.h"

void any_print(cm_any* any) {
    if (!any) {
        printf("Null any");
        return;
    }
    switch (any->type) {
        case CM_TYPE_ERROR:
            printf("Error value\n");
            break;
        case CM_TYPE_BOOL:
            printf("Bool value: %s\n", *(bool*)any->data ? "true" : "false");
            break;
        case CM_TYPE_INT:
            printf("Integer value: %lld\n", *(long long int*)any->data);
            break;
        case CM_TYPE_FLOAT:
            printf("Float value: %Lf\n", (double)(*(long double*)any->data));
            break;
        case CM_TYPE_CHAR:
            printf("Char value: %c\n", *(char*)any->data);
            break;
        case CM_TYPE_STRING:
            printf("String value: %s\n", (char*)any->data);
            break;
        default:
            printf("Unknown type\n");
    }
}

void vector_print(cm_vector* v) {
    for(int i = 0; i < cm_vector_size(v); ++i) {
        any_print(cm_vector_at(v, i));
    }
}

void stack_print(cm_stack* s) {
    int size = cm_stack_size(s);
    for(int i = 0; i < size; ++i) {
        any_print(cm_stack_pop(s));
    }
}

void map_print(const char* key, cm_any* value) {
    printf("key: %s and ", key);
    any_print(value);
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
    any_print(cm_vector_at(v, 3));

    cm_vector_free(v);

    printf("\n-----------------\n\n");

    cm_stack* s = cm_stack_init();
    cm_stack_push(s, cm_any_int(10));
    cm_stack_push(s, cm_any_int(9));
    cm_stack_push(s, cm_any_string("foo"));

    printf("Full stack:\n");
    stack_print(s);
    printf("\n");

    printf("Stack after print:\n");
    stack_print(s);

    cm_stack_free(s);

    printf("\n-----------------\n\n");

    cm_map* m = cm_map_init();
    cm_map_insert(m, "item-10", cm_any_int(10));
    cm_map_insert(m, "item-9", cm_any_int(9));
    cm_map_insert(m, "item-foo", cm_any_string("foo"));

    printf("Map key print:\n");
    any_print(cm_map_get(m, "item-10"));
    any_print(cm_map_get(m, "item-9"));
    any_print(cm_map_get(m, "item-foo"));
    printf("\n");

    printf("Map foreach print:\n");
    cm_map_foreach(m, map_print);

    cm_map_free(m);

    return 0;
}

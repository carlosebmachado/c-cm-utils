#ifndef CM_ANY_H
#define CM_ANY_H

// This library is not intended to store types in order to save memory,
// but to store the maximum value of each data type, and also provide
// differentiation between data of the same type as char and bool.

#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include <float.h>
#include <string.h>
#include <stdbool.h>


typedef enum {
    CM_TYPE_ERROR,
    CM_TYPE_BOOL,
    CM_TYPE_INT,
    CM_TYPE_FLOAT,
    CM_TYPE_CHAR,
    CM_TYPE_STRING
} cm_data_type;

typedef struct {
    cm_data_type type;
    void* data;
} cm_any;

cm_any* cm_any_custom(void* value, int type) {
    cm_any* any;
    any->type = CM_TYPE_STRING + type;
    any->data = malloc(sizeof(void*));
    *((void*)*)any->data = value;
    return any;
}

cm_any* cm_any_bool(bool value) {
    cm_any* any;
    any->type = CM_TYPE_BOOL;
    any->data = malloc(sizeof(bool));
    *(bool*)any->data = value;
    return any;
}

cm_any* cm_any_int(long long int value) {
    cm_any* any;
    any->type = CM_TYPE_INT;
    any->data = malloc(sizeof(long long int));
    *(long long int*)any->data = value;
    return any;
}

cm_any* cm_any_err() {
    cm_any* any;
    any->type = CM_TYPE_ERROR;
    any->data = NULL;
    return any;
}

cm_any* cm_any_float(long double value) {
    cm_any* any;
    any->type = CM_TYPE_FLOAT;
    any->data = malloc(sizeof(long double));
    *(long double*)any->data = value;
    return any;
}

cm_any* cm_any_char(char value) {
    cm_any* any;
    any->type = CM_TYPE_CHAR;
    any->data = malloc(sizeof(char));
    *(char*)any->data = value;
    return any;
}

cm_any* cm_any_string(const char* value) {
    cm_any* any;
    any->type = CM_TYPE_STRING;
    any->data = strdup(value);
    return any;
}

void cm_any_free(cm_any* any) {
    free(any->data);
    free(any);
}

#endif //CM_ANY_H

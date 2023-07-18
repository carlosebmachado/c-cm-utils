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

cm_any cm_any_bool(bool value) {
    cm_any a;
    a.type = CM_TYPE_BOOL;
    a.data = malloc(sizeof(bool));
    *(bool*)a.data = value;
    return a;
}

cm_any cm_any_int(long long int value) {
    cm_any a;
    a.type = CM_TYPE_INT;
    a.data = malloc(sizeof(long long int));
    *(long long int*)a.data = value;
    return a;
}

cm_any cm_any_err() {
    cm_any a;
    a.type = CM_TYPE_ERROR;
    a.data = malloc(sizeof(int));
    *(int*)a.data = -1;
    return a;
}

cm_any cm_any_float(long double value) {
    cm_any a;
    a.type = CM_TYPE_FLOAT;
    a.data = malloc(sizeof(long double));
    *(long double*)a.data = value;
    return a;
}

cm_any cm_any_char(char value) {
    cm_any a;
    a.type = CM_TYPE_CHAR;
    a.data = malloc(sizeof(char));
    *(char*)a.data = value;
    return a;
}

cm_any cm_any_string(const char* value) {
    cm_any a;
    a.type = CM_TYPE_STRING;
    a.data = strdup(value);
    return a;
}

void cm_any_free(cm_any a) {
    free(a.data);
}

#endif //CM_ANY_H

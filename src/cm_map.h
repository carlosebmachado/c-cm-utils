#ifndef CM_MAP_H
#define CM_MAP_H

#include "cm_element.h"


typedef void (*cm_map_callback)(const char*, cm_any);

typedef struct {
    char* key;
    cm_any value;
} cm_key_value_pair;

typedef struct cm_node {
    cm_key_value_pair pair;
    struct cm_node* next;
} cm_node;

typedef struct {
    cm_node* head;
} cm_map;

cm_map* cm_map_init() {
    cm_map* m = (cm_map*)malloc(sizeof(cm_map));
    m->head = NULL;
    return m;
}

long long int cm_map_size(cm_map* m) {
    cm_node* current = m->head;
    long long int sz = 0;
    while (current) {
        ++sz;
        current = current->next;
    }
    return sz;
}

void cm_map_insert(cm_map* m, const char* key, cm_any value) {
    cm_node* new_node = (cm_node*)malloc(sizeof(cm_node));
    new_node->pair.key = strdup(key);
    new_node->pair.value = value;
    new_node->next = m->head;
    m->head = new_node;
}

cm_any cm_map_get(cm_map* m, const char* key) {
    cm_node* current = m->head;
    while (current) {
        if (strcmp(current->pair.key, key) == 0) {
            return current->pair.value;
        }
        current = current->next;
    }
    return cm_any_err();
}

void cm_map_foreach(cm_map* m, cm_map_callback callback) {
    cm_node* current = m->head;
    while (current) {
        callback(current->pair.key, current->pair.value);
        current = current->next;
    }
}

#endif // CM_MAP_H

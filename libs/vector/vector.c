#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void validateIndex(vector* vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Invalid index %zu for size %zu", index, vector->size);
        exit(1);
    }
}

void* validateMemory(void* memory) {
    if (memory == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return memory;
}

vector createVector(size_t capacity) {
    return (vector) {
        validateMemory(malloc(capacity * sizeof(int))),
        0,
        capacity,
    };
}

void setCapacity(vector *vector, size_t newCapacity) {
    if (newCapacity == 0) {
        free(vector->data);
        vector->data = NULL;
    } else if (newCapacity < vector->size) {
        vector->size = newCapacity;
    }

    vector->data = validateMemory(realloc(vector->data, newCapacity * sizeof(int)));
    vector->capacity = newCapacity;
}

void compact(vector *vector) {
    if (vector->size < vector->capacity) {
        vector->capacity = vector->size;
        vector->data = validateMemory(realloc(vector->data, vector->capacity * sizeof(int)));
    }
}

void deleteVector(vector *vector) {
    free(vector->data);

    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

bool isFull(vector* vector) {
    return vector->size >= vector->capacity;
}

bool isEmpty(vector* vector) {
    return vector->size == 0;
}

int getVectorValue(vector *vector, size_t index) {
    return *atVector(vector, index);
}

void push(vector* vector, int value) {
    if (isFull(vector)) {
        setCapacity(vector, vector->capacity << 1);
    }

    vector->data[vector->size++] = value;
}

int pop(vector* vector) {
    int value = *first(vector);

    vector->size--;

    return value;
}

int* atVector(vector* vector, size_t index) {
    validateIndex(vector, index);

    return &(vector->data[index]);
}

int* first(vector* vector) {
    return atVector(vector, vector->size - 1);
}

int* last(vector* vector) {
    return atVector(vector, 0);
}
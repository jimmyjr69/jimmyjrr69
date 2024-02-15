#include "int_vector.h"
#include <stdio.h>
#include <stdlib.h>

void validateIndex(int_vector* vector, size_t index) {
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

int_vector createIntVector(size_t capacity) {
    return (int_vector) {
        validateMemory(malloc(capacity * sizeof(int))),
        0,
        capacity,
    };
}

void setIntVectorCapacity(int_vector *vector, size_t newCapacity) {
    if (newCapacity == 0) {
        free(vector->elements);
        vector->elements = NULL;
    } else if (newCapacity < vector->size) {
        vector->size = newCapacity;
    }

    vector->elements = validateMemory(realloc(vector->elements, newCapacity * sizeof(int)));
    vector->capacity = newCapacity;
}

void compactIntVector(int_vector *vector) {
    if (vector->size < vector->capacity) {
        vector->capacity = vector->size;
        vector->elements = validateMemory(realloc(vector->elements, vector->capacity * sizeof(int)));
    }
}

void deleteIntVector(int_vector *vector) {
    free(vector->elements);

    vector->elements = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

bool isIntVectorFull(int_vector* vector) {
    return vector->size >= vector->capacity;
}

bool isIntVectorEmpty(int_vector* vector) {
    return vector->size == 0;
}

int getIntVectorValue(int_vector *vector, size_t index) {
    return *elementInIntVector(vector, index);
}

void pushToIntVector(int_vector* vector, int value) {
    if (isIntVectorFull(vector)) {
        setIntVectorCapacity(vector, vector->capacity << 1);
    }

    vector->elements[vector->size++] = value;
}

int popFromIntVector(int_vector* vector) {
    int value = *firstInIntVector(vector);

    vector->size--;

    return value;
}

int* elementInIntVector(int_vector* vector, size_t index) {
    validateIndex(vector, index);

    return &(vector->elements[index]);
}

int* firstInIntVector(int_vector* vector) {
    return elementInIntVector(vector, vector->size - 1);
}

int* lastInIntVector(int_vector* vector) {
    return elementInIntVector(vector, 0);
}
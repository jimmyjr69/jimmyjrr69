#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"

void validateIndex(vector * vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Invalid index %zu for size %zu", index, vector->size);
        exit(1);
    }
}

vector createVector(size_t capacity, size_t typeSize) {
    vector vector;

    vector.elements = malloc(capacity * typeSize);
    vector.size = 0;
    vector.capacity = capacity;
    vector.typeSize = typeSize;

    return vector;
}

void setVectorCapacity(vector* vector, size_t newCapacity) {
    if (newCapacity > vector->capacity) {
        void* newData = realloc(vector->elements, newCapacity * vector->typeSize);

        if (newData) {
            vector->elements = newData;
            vector->capacity = newCapacity;
        }
    }
}

void compactVector(vector* vector) {
    if (vector->size < vector->capacity) {
        void *newData = realloc(vector->elements, vector->size * vector->typeSize);
        if (newData) {
            vector->elements = newData;
            vector->capacity = vector->size;
        }
    }
}

void deleteVector(vector* vector) {
    free(vector->elements);

    vector->elements = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

bool isVectorEmpty(vector* vector) {
    return vector->size == 0;
}

bool isVectorFull(vector* vector) {
    return vector->size == vector->capacity;
}

void getVectorValue(vector* vector, size_t index, void *destination) {
    validateIndex(vector, index);

    memcpy(destination, vector->elements + index * vector->typeSize, vector->typeSize);
}

void pushToVector(vector* vector, void* source) {
    if (isVectorFull(vector)) {
        setVectorCapacity(vector, vector->capacity << 1);
    }

    memcpy(vector->elements + vector->size++, source, vector->typeSize);
}

void popFromVector(vector* vector, void* destination) {
    firstInVector(vector, destination);
    vector->size--;
}

void firstInVector(vector* vector, void* destination) {
    getVectorValue(vector, 0, destination);
}

void lastInVector(vector* vector, void* destination) {
    getVectorValue(vector, vector->size - 1, destination);
}
#ifndef LAB14_VECTOR_H
#define LAB14_VECTOR_H

#include <limits.h>
#include <stdbool.h>

typedef struct vector {
    void* elements;
    size_t size;
    size_t capacity;
    size_t typeSize;
} vector;

vector createVector(size_t capacity, size_t typeSize);

void setVectorCapacity(vector* vector, size_t newCapacity);

void compactVector(vector* vector);

void deleteVector(vector* vector);

bool isVectorEmpty(vector* vector);

bool isVectorFull(vector* vector);

void getVectorValue(vector* vector, size_t index, void* destination);

void pushToVector(vector* vector, void* source);

void popFromVector(vector* vector, void* destination);

void firstInVector(vector* vector, void* destination);

void lastInVector(vector* vector, void* destination);

#endif //LAB14_VECTOR_H
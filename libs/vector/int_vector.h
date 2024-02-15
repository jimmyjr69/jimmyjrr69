#ifndef LAB14_VECTOR_H
#define LAB14_VECTOR_H

#include <corecrt.h>
#include <stdbool.h>

typedef struct int_vector {
    int* elements;
    size_t size;
    size_t capacity;
} int_vector;

int_vector createIntVector(size_t capacity);

void setIntVectorCapacity(int_vector* vector, size_t newCapacity);

void compactIntVector(int_vector* vector);

void deleteIntVector(int_vector* vector);

bool isIntVectorEmpty(int_vector* vector);

bool isIntVectorFull(int_vector* vector);

int getIntVectorValue(int_vector* vector, size_t index);

void pushToIntVector(int_vector* vector, int value);

int popFromIntVector(int_vector* vector);

int* elementInIntVector(int_vector* vector, size_t index);

int* firstInIntVector(int_vector* vector);

int* lastInIntVector(int_vector* vector);

#endif //LAB14_VECTOR_H
#ifndef LAB14_VECTOR_H
#define LAB14_VECTOR_H

#include <corecrt.h>
#include <stdbool.h>

typedef struct vector {
    int* data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t capacity);

void setCapacity(vector* vector, size_t newCapacity);

void compact(vector* vector);

void deleteVector(vector* vector);

bool isEmpty(vector* vector);

bool isFull(vector* vector);

int getVectorValue(vector* vector, size_t index);

void push(vector* vector, int value);

int pop(vector* vector);

int* atVector(vector* vector, size_t index);

int* first(vector* vector);

int* last(vector* vector);

#endif //LAB14_VECTOR_H
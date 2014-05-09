
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned ElementType;

typedef struct {
    ElementType *data;
    int size;
    
} SVECTOR;

typedef SVECTOR *vectorP;


void createVector(vectorP *v1, int _size) {
    int i = 0;
    
    if(*v1 == NULL) {
        *v1 = (vectorP) malloc (sizeof(SVECTOR));
        
        (*v1) -> data = (ElementType*) malloc(_size * sizeof(ElementType));
        (*v1) -> size = _size;
        
        for (i = 0; i < _size; ++i) {
            *((*v1) -> data + i) = 0;
        }
        
    } else {
        printf("[ERROR] The vector is already created.");
    }
}

void assignValue(vectorP *v1, int position, ElementType value) {
    if (*v1 != NULL) {
        *((*v1) -> data + position) = value;
        
    } else {
        printf("[ERROR] The vector is not initalized.");
    }
}


void freeVector(vectorP *v1) {
    if (*v1 != NULL) {
        free((*v1) -> data);
        free(*v1);
        
        *v1 = NULL;
        
    } else
        printf("[ERROR] El vector no ha sido inicializado.");
}


int getSize (vectorP v1) {
    int _size = -1;
    
    if(v1 != NULL)
        _size= (v1) -> size;
    
    return _size;
}


ElementType getValue(vectorP v1, int index) {
    int output = -1;

    if (v1 != NULL) {
        if(index < getSize(v1)) {
            output = *((v1) -> data + index);
            
        } else {
            printf("[ERROR] Not defined value at: %d.\n", index);
        }
        
    } else {
        printf("[ERROR] The vector is not initialized.\n");
    }
    
    return output;
}

void incrementVect (vectorP * v1, int position) {
    ElementType container = 0;
    
    if(position < getSize(*v1)) {
        container = getValue(*v1, position);
        container ++;
        assignValue(v1, position, container);
        
    } else {
        printf("[ERROR] Not defined value at: %d.\n", index);
    }
}


void decrementVect (vectorP * v1, int position) {
    ElementType container = 0;
    
    if(position < getSize(*v1)) {
        container = getValue(*v1, position);
        container --;
        assignValue(v1, position, container);
        
    } else {
        printf("[ERROR] Not defined value at: %d.\n", index);
    }
}


void printVect(vectorP v1, unsigned long size) {
    if (v1 != NULL) {
        for (int i = 0; i < getSize(v1); i++) {
            printf("Element at %d, value: %d\n", i, getValue(v1, i));
        }
        
    } else {
        printf("[ERROR] The vector is not initialized.");
    }
}

typedef int ElementType;

typedef void * vectorP;

void createVector (vectorP *v1, int size);

void assignValue(vectorP *v1, int position, ElementType valor);

ElementType getValue (vectorP v1, int position);

void freeVector (vectorP *v1);

int getSize (vectorP v1);

void printVect (vectorP v1);

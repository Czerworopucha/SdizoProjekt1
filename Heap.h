#ifndef SDIZO_PROJEKT_1_HEAP_H
#define SDIZO_PROJEKT_1_HEAP_H

#include "string"
using namespace std;

class Heap {
public:
    int *heapArray;
    int size;

    Heap();
    ~Heap();
    void addElement(int value);
    void deleteRoot();
    int getByValue(int value);
    void display(string, string, int);
    void loadFromFile(string fileName);
    void clearHeap();
    void generateToHeap(int amount);
};


#endif //SDIZO_PROJEKT_1_HEAP_H

#ifndef SDIZO_PROJEKT_1_ARRAY_H
#define SDIZO_PROJEKT_1_ARRAY_H

#include "string"
using namespace std;

class Array {

public:
    int *headPointer;
    unsigned int size;

    Array();
    ~Array();
    void addFront(int value);
    void addEnd(int value);
    void addByIndex(int value, int index);
    void deleteFront();
    void deleteEnd();
    void deleteByIndex(int index);
    int getByIndex(int index);
    int getByValue(int value);
    void display();
    void loadFromFile(string fileName);
    void clearArray();
    void generateToArray(int amount);

};


#endif //SDIZO_PROJEKT_1_ARRAY_H

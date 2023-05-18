#ifndef SDIZO_PROJEKT_1_LIST_H
#define SDIZO_PROJEKT_1_LIST_H


#include "ListElement.h"
#include "string"
using namespace std;

class List {
public:
    int size;
    ListElement *first;
    ListElement *last;
    ListElement *current;

    List();
    ~List();
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
    void clearList();
    void generateToList(int amount);

};


#endif //SDIZO_PROJEKT_1_LIST_H

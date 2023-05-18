#ifndef SDIZO_PROJEKT_1_MENU_H
#define SDIZO_PROJEKT_1_MENU_H


#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "RNG.h"

class Menu {
public:
    void displayMenuArray();
    void menuArray(Array*);

    void displayMenuList();
    void menuList(List*);

    void displayMenuHeap();
    void menuHeap(Heap*);
};


#endif //SDIZO_PROJEKT_1_MENU_H

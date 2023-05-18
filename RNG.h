#ifndef SDIZO_PROJEKT_1_RNG_H
#define SDIZO_PROJEKT_1_RNG_H


#include "Array.h"
#include "List.h"
#include "Heap.h"
#include <string>
using namespace std;

class RNG {
public:
    RNG();
    ~RNG();
    void randomNumberGeneratorToFile(int amount, string filename);
};


#endif //SDIZO_PROJEKT_1_RNG_H

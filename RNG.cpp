#include "fstream"
#include "RNG.h"
#include "iostream"
#include "random"
#include <string>

using namespace std;

void RNG::randomNumberGeneratorToFile(int amount, string filename){
    int value;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);

    fstream file;
    file.open(filename, ios::in | ios::out);
    file << amount;
    file << "\n";
    for(int i = 0; i < amount - 1; i++){
        value = dist(gen);
        file << value;
        file << "\n";
    }
    value = dist(gen);
    file << value;
    file.close();
}

RNG::~RNG() = default;

RNG::RNG() = default;

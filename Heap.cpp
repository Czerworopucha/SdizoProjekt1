#include "Heap.h"
#include <iostream>
#include <random>
#include "string"
#include "fstream"
using namespace std;

Heap::Heap() {
    Heap::heapArray = nullptr;
    Heap::size = 0;
}

Heap::~Heap() = default;

/*zwiekszenie rozmiaru o 1
 * indeks na pozycje wstawianego elementu
 * obliczenie indeksu rodzica
 * dodanie na koniec
 * tzw fix up:
 * tak dlugo jak rodzic jest mniejszy od syna to zamieniamy miejscami (albo dojdziemy do korzenia - index 0)*/
void Heap::addElement(int value) {
    int addedIndex, parentIndex;

    int *newArr = new int[size + 1];
    newArr[size] = value;
    for(int i=0; i<size; i++){
        newArr[i] = heapArray[i];
    }
    delete heapArray;
    heapArray = newArr;

    addedIndex = size;
    parentIndex = (addedIndex - 1)/2;

    while(addedIndex > 0 && heapArray[parentIndex] < value)
    {
        heapArray[addedIndex] = heapArray[parentIndex];
        addedIndex = parentIndex;
        parentIndex = (addedIndex - 1)/2;
    }

    heapArray[addedIndex] = value;
    size++;
}

void Heap::deleteRoot() {
    int parentIndex, sonIndex, temp;

    if(size == 0){
        cout << "ERR - can't delete, heap is empty" << endl;
        return;
    }

    size--;
    temp = heapArray[size];
    parentIndex = 0;
    sonIndex = 1;

    while(sonIndex < size){
        if(sonIndex + 1 < size && heapArray[sonIndex + 1] > heapArray[sonIndex]) sonIndex++;
        if(temp >= heapArray[sonIndex]) break;
        heapArray[parentIndex] = heapArray[sonIndex];
        parentIndex = sonIndex;
        sonIndex = 2 * sonIndex + 1;
    }
    heapArray[parentIndex] = temp;

    int *newArr = new int[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = heapArray[i];
    }
    delete heapArray;
    heapArray = newArr;
}

int Heap::getByValue(int value) {
    if(heapArray == nullptr){
        cout << "ERR - can't search for provided value, heap is empty" << endl;
        return -1;
    }
    else{
        for(int i = 0; i < size; i++){
            if(heapArray[i] == value){
                cout << "Number: " << value << " is in position: " << i << endl;
                return i;
            }
        }
        cout << "Such number does not exist in the heap" << endl;
        return -1;
    }
}

void Heap::display(string sp, string sn, int v) {
    string s;
    string cr, cl, cp;
    cr = cl = cp = "  ";
    cr [ 0 ] = 218; cr [ 1 ] = 196;
    cl [ 0 ] = 192; cl [ 1 ] = 196;
    cp [ 0 ] = 179;

    if( v < size )
    {
        s = sp;
        if( sn == cr ) s [ s.length( ) - 2 ] = ' ';
        display( s + cp, cr, 2 * v + 2 );

        s = s.substr ( 0, sp.length( ) - 2 );

        cout << s << sn << heapArray[v] << endl;

        s = sp;
        if( sn == cl ) s [ s.length( ) - 2 ] = ' ';
        display( s + cp, cl, 2 * v + 1 );
    }
}

void Heap::clearHeap() {
    delete heapArray;
    heapArray = new int[0];
    size = 0;
}

void Heap::generateToHeap(int amount) {
    int value,j,k;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    clearHeap();
    for(int i = 0; i < amount; i++){
        value = dist(gen);
        addElement(value);
    }
}

void Heap::loadFromFile(string fileName) {
    int value, amount;
    clearHeap();
    fstream file;
    file.open(fileName, ios::in | ios::out);
    file >> amount;
    while(!file.eof()){
        file >> value;
        addElement(value);
    }
    file.close();
}

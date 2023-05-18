#include <iostream>
#include "Array.h"
#include "fstream"
#include <string>
#include "random"
using namespace std;

//konstruktor
Array::Array() {

    Array::headPointer = nullptr;
    Array::size = 0;
}
//destruktor
Array::~Array() = default;

/*Nowa tablica z rozmiarem o 1 wiekszym
 * Dodawana liczba jako pierwsza
 * przekopiowanie danych ze starej tablicy do nowej
 * usuniecie wskaznika na stara tablice
 * wskaznik = wskaznik na nowa tablice*/
void Array::addFront(int value) {
    int *newArr = new int[size + 1];
    newArr[0] = value;
    for(int i=0; i<size; i++){
        newArr[i+1] = headPointer[i];
    }
    delete headPointer;
    headPointer = newArr;
    size++;
}
/*Nowa tablica z rozmiarem o 1 wiekszym
 * Dodawana liczba jako ostatnia
 * przekopiowanie danych ze starej tablicy do nowej
 * usuniecie wskaznika na stara tablice
 * wskaznik = wskaznik na nowa tablice*/
void Array::addEnd(int value) {
    int *newArr = new int[size + 1];
    newArr[size] = value;
    for(int i=0; i<size; i++){
        newArr[i] = headPointer[i];
    }
    delete headPointer;
    headPointer = newArr;
    size++;
}
/*Sprawdzenie czy taki index istnieje w tablicy
 * Nowa tablica z rozmiarem o 1 wiekszym
 * Dodawana liczba jako podane miejsce
 * przekopiowanie danych ze starej tablicy do nowej - najpierw aż do indexu na ktory dodajemy a potem po nim
 * usuniecie wskaznika na stara tablice
 * wskaznik = wskaznik na nowa tablice*/
void Array::addByIndex(int value, int index) {
    if (index < 0 || index >= size){
        cout << "ERR - wrong index value" << endl;
        return;
    }
    if(index == 0){
        addFront(value);
        return;
    }
    if(index == size-1){
        addEnd(value);
        return;
    }
        int *newArr = new int[size + 1];
        newArr[index] = value;
        for (int i = 0; i < index; i++) {
            newArr[i] = headPointer[i];
        }
        for (int i = index; i < size; i++) {
            newArr[i + 1] = headPointer[i];
        }
        delete headPointer;
        headPointer = newArr;
        size++;
}
/*Sprawdzenie czy tablica jest pusta?
 * Nowa tablica z romziarem 1 mniejszym
 * przekopiowanie wszystkich elementow poza pierwszym
 * usuniecie wskaznika na stara tablice
 * wskaznik = wskaznik na nowa tablice*/
void Array::deleteFront() {
    if(headPointer == nullptr){
        cout << "ERR - can't delete, array is empty" << endl;
    }
    else {
        int *newArr = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newArr[i] = headPointer[i + 1];
        }
        delete headPointer;
        headPointer = newArr;
        size--;
    }
}
/*Sprawdzenie czy tablica jest pusta?
 * Nowa tablica z rozmiarem 1 mniejszym
 * przekopiowanie wszystkich elementow poza ostatnim
 * usuniecie wskaznika na stara tablice
 * wskaznik = wskaznik na nowa tablice*/
void Array::deleteEnd() {
    if(headPointer == nullptr){
        cout << "ERR - can't delete, array is empty" << endl;
    }
    else {
        int *newArr = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            newArr[i] = headPointer[i];
        }
        delete headPointer;
        headPointer = newArr;
        size--;
    }
}
/*Sprawdzenie czy tablica jest pusta?
 * Sprawdzenie czy index sie miesci w tablicy
 * Nowa tablica z romziarem 1 mniejszym
 * przekopiowanie wszystkich elementow az do wskazanego
 * przekopiowanie wszystkich po wskazanym
 * usuniecie wskaznika na stara tablice
 * wskaznik = wskaznik na nowa tablice*/
void Array::deleteByIndex(int index) {
    if(headPointer == nullptr || index < 0 || index >= size){
        cout << "ERR - can't delete, arr is empty or wrong index value" << endl;
        return;
    }
    if(index == 0){
        deleteFront();
        return;
    }
    if(index == size - 1){
        deleteEnd();
        return;
    }
    else {
        int *newArr = new int[size - 1];
        for (int i = 0; i < index; i++) {
            newArr[i] = headPointer[i];
        }
        for (int i = index; i < size - 1; i++) {
            newArr[i] = headPointer[i + 1];
        }
        delete headPointer;
        headPointer = newArr;
        size--;
    }
}
/*Sprawdzenie czy tablica jest pusta
 * Sprawdzenie czy index sie miesci w tablicy
 * wypiasnie na ktorym*/
int Array::getByIndex(int index) {
    if(headPointer == nullptr || index < 0 || index >= size){
        cout << "ERR - can't delete, arr is empty or wrong index value" << endl;
        return -1;
    }
    else{
        cout << "Value for index "<< index << " is: " << headPointer[index] << endl;
        return headPointer[index];
    }
}
/*Sprawdzenie czy tablica jest pusta
 * Sprawdzenie czy index sie miesci w tablicy
 * Przeszukanie tablicy dla podanej wartości
 * Zwrócenie pointera na konkretne miejsce w tablicy
 * Lub nullptr jeśli taka wartośc nie istnieje*/
int Array::getByValue(int value) {
    if(headPointer == nullptr){
        cout << "ERR - can't search for provided value, array is empty" << endl;
        return -1;
    }
    else{
        for(int i = 0; i < size; i++){
            if(headPointer[i] == value){
                cout << "Number: " << value << " is in position: " << i << endl;
                return i;
            }
        }
        cout << "Such number does not exist in the array" << endl;
        return -1;
    }
}
/*Sprawdzenie czy tablica jest pusta
 * Wyświetlenie tablicy po kolei w 1 linijce*/
void Array::display() {
    if(headPointer == nullptr){
        cout << "ERR - array is empty, cannot display the current state" << endl;
    }
    else{
        for(int i = 0; i < size; i++) {
            cout << headPointer[i] << " | ";
        }
        cout << endl;
    }
}

void Array::loadFromFile(string fileName) {
    int value, amount, i = 0;
    clearArray();
    fstream file;
    file.open(fileName, ios::in | ios::out);
    file >> amount;
    headPointer = new int[amount];
    size = amount;
    while(!file.eof()){
        file >> value;
        headPointer[i] = value;
        i++;
    }
    file.close();
}

void Array::clearArray() {
    delete headPointer;
    headPointer = new int[0];
    size = 0;
}

void Array::generateToArray(int amount) {
    int value;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    clearArray();
    headPointer = new int[amount];
    size = amount;
    for(int i = 0; i < amount; i++){
        value = dist(gen);
        headPointer[i] = value;
    }
}

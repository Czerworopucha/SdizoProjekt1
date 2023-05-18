#include <fstream>
#include "iostream"
#include "List.h"
#include "random"
#include "string"
using namespace std;

List::List() {
    List:size = 0;
    List::first = nullptr;
    List::last = nullptr;
    List::current = nullptr;
}

List::~List() = default;
/*Sprawdzenie czy lista pusta - pierwszy elem
 * jak nie - ustawiamy jako first i last.
 * jak tak - current = first
 * first = new
 * current -> prev = first
 * size++*/
void List::addFront(int value) {
    if(first == nullptr){
        first = new ListElement(value, nullptr, nullptr);
        last = first;
    }
    else {
        current = first;
        first = new ListElement(value, current, nullptr);
        current -> previous = first;
    }
    size++;
}
/*Sprawdzenie czy lista pusta - pierwszy elem
 * jak tak - ustawiamy jako first i last.
 * jak nie - current = last
 * last = new
 * current -> next = last
 * size++*/
void List::addEnd(int value) {
    if(first == nullptr){
        first = new ListElement(value, nullptr, nullptr);
        last = first;
    }
    else {
        current = last;
        last = new ListElement(value, nullptr, current);
        current -> next = last;
    }
    size++;
}
/*Sprawdzenie czy lista pusta - pierwszy elem
 * jak tak to ustawiamy jako first i last return
 * Sprawdzenie czy index wchodzi w zakres
 * jak nie to
 * if index = 0 addfront return
 * if index = size - 1 addend return
 * current = first
 * for ustawienie current na index
 * ListElement *newElem = new ListElement(value, current -> next, current)
 * current -> next ->prev = newElem;
 * current -> next = newElem
 * size++*/
void List::addByIndex(int value, int index) {
    if(first == nullptr){
        first = new ListElement(value, nullptr, nullptr);
        last = first;
        return;
    }
    if(index < 0 || index >= size){
        cout << "ERR - wrong index value" << endl;
        return;
    }
    if(index == 0){
        addFront(value);
        return;
    }
    if(index == size - 1){
        addEnd(value);
        return;
    }
    if(index <= size/2) {
        current = first;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        auto *newElem = new ListElement(value, current->next, current);
        current->next->previous = newElem;
        current->next = newElem;
    }
    else{
        current = last;
        for(int i = size-1; i > index - 1 ; i--){
            current = current -> previous;
        }
        auto *newElem = new ListElement(value, current->next, current);
        current->next->previous = newElem;
        current->next = newElem;
    }
    size++;
}
/*Sprawdzenie czy lista pusta - pierwszy elem
 * jak nie - nie da sie usunac.
 * jak tak - current = first ->next
 * delete = first
 * size--
 * jak nie pusta -
 * current -> prev = null
 * first = current
 * jak lista jest pusta po usunieciu -
 * first,last,current = null*/
void List::deleteFront() {
    if(first == nullptr){
        cout << "ERR - can't delete element, list is empty" << endl;
    }
    else {
        current = first -> next;
        delete first;
        size--;
        if(size > 0){
            current -> previous = nullptr;
            first = current;
        }
        else {
            first = nullptr;
            last = nullptr;
            current = nullptr;
        }
    }
}
/*Sprawdzenie czy lista pusta - pierwszy elem
 * jak nie - nie da sie usunac.
 * jak tak - current = last ->prev
 * delete = last
 * size--
 * jak nie pusta -
 * current -> next = null
 * last = current
 * jak lista jest pusta po usunieciu -
 * first,last,current = null*/
void List::deleteEnd() {
    if(first == nullptr){
        cout << "ERR - can't delete element, list is empty" << endl;
    }
    else {
        current = last -> previous;
        delete last;
        size--;
        if(size > 0){
            current -> next = nullptr;
            last = current;
        }
        else {
            first = nullptr;
            last = nullptr;
            current = nullptr;
        }
    }
}

void List::deleteByIndex(int index) {
    if(first == nullptr){
        cout << "Can't delete element, array is empty" << endl;
        return;
    }
    if(index < 0 || index >= size){
        cout << "ERR - wrong index value" << endl;
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
    if(index <= size/2) {
        current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->next->previous = current->previous;
        current->previous->next = current->next;
        delete current;
    }
    else{
        current = last;
        for(int i = size-1; i > index; i--){
            current = current -> previous;
        }
        current->next->previous = current->previous;
        current->previous->next = current->next;
        delete current;
    }
    size--;

}

int List::getByIndex(int index) {
    if(first == nullptr){
        cout << "Can't find element, array is empty" << endl;
        return -1;
    }
    if(index < 0 || index >= size){
        cout << "ERR - wrong index value" << endl;
        return -1;
    }
    if(index <= size/2) {
        current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        cout << "Value for index: " << index << " is: " << current->value << endl;
        return 0;
    }
    else
    {
        current = last;
        for(int i = size-1; i > index; i--){
            current = current -> previous;
        }
        cout << "Value for index: " << index << " is: " << current->value << endl;
        return 0;
    }
}

int List::getByValue(int value) {
    if(first == nullptr){
        cout << "Can't find element, array is empty" << endl;
        return -1;
    }

    current = first;
    for(int i = 0; i < size; i++){
        if(current -> value == value){
            cout << "Number: " << value << " is in position: " << i << endl;
            return i;
        }
        current = current -> next;
    }
    cout << "Number does not exist in the List" << endl;
    return -1;
}
/*Sprawdzenie czy pusta
 * jak nie to -
 * current = first
 * w petli:
 * - cout << current-> value
 * - current = current -> next*/
void List::display() {
    if(first == nullptr){
        cout << "ERR - list is empty, cannot display the current state" << endl;
        return;
    }
    else{
        cout << "The list consists of " << size << " elements." << endl;
        current = first;
        for(int i = 0; i < size; i++){
            cout << " | " << current -> value;
            current = current -> next;
        }
        cout << " | " << endl;

        cout << endl;

        current = last;
        for(int i = size; i > 0; i--){
            cout << " | " << current -> value;
            current = current -> previous;
        }
        cout << " | " << endl;
    }
}

void List::clearList() {
    while(first != nullptr){
        deleteEnd();
    }
}

void List::generateToList(int amount) {
    int value;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    clearList();
    for(int i = 0; i < amount; i++){
        value = dist(gen);
        addEnd(value);
    }
}

void List::loadFromFile(string fileName) {
    int value,amount;
    clearList();
    fstream file;
    file.open(fileName, ios::in | ios::out);
    file >> amount;
    while(!file.eof()){
        file >> value;
        addEnd(value);
    }
    file.close();
}

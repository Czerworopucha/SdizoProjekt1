#include <conio.h>
#include "Menu.h"
#include "iostream"
#include "Array.h"
#include "string"

using namespace std;


void Menu::displayMenuArray()
{
    cout << endl;
    cout << "------Array------" << endl;
    cout << "1.Load from file" << endl;
    cout << "2.Delete Front" << endl;
    cout << "3.Delete End" << endl;
    cout << "4.Delete on Index" << endl;
    cout << "5.Add Front" << endl;
    cout << "6.Add End" << endl;
    cout << "7.Add on Index" << endl;
    cout << "8.Find by Index" << endl;
    cout << "9.Find by Value" << endl;
    cout << "10.Generate random numbers" << endl;
    cout << "11.Display" << endl;
    cout << "0.Main Menu" << endl;
    cout << "Choice: " << endl;
}

void Menu::menuArray(Array* array)
{
    int option;
    string fileName;
    int index, value;



    do{
        displayMenuArray();
        cin >> option;
        cout << endl;
        switch (option){
            case 1:
                cout << " Enter file path: " << endl;
                cin >> fileName;
                cout << endl;
                array->loadFromFile(fileName);
                array->display();
                break;

            case 2:
                array->deleteFront();
                array->display();
                break;

            case 3:
                array->deleteEnd();
                array->display();
                break;

            case 4:
                cout << " Enter Index: " << endl;
                cin >> index;
                cout << endl;
                array->deleteByIndex(index);
                array->display();
                break;

            case 5:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                array->addFront(value);
                array->display();
                break;

            case 6:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                array->addEnd(value);
                array->display();
                break;

            case 7:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                cout << " Enter Index: " << endl;
                cin >> index;
                cout << endl;
                array->addByIndex(value,index);
                array->display();
                break;

            case 8:
                cout << " Enter Index: " << endl;
                cin >> index;
                cout << endl;
                array->getByIndex(index);
                array->display();
                break;

            case 9:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                array->getByValue(value);
                array->display();
                break;

            case 10:
                cout << " Enter the Amount: " << endl;
                cin >> value;
                cout << endl;
                array->generateToArray(value);
                array->display();
                break;

            case 11:
                array->display();
                break;
        }
    } while (option != 0);
}

void Menu::displayMenuList() {
    cout << endl;
    cout << "------List------" << endl;
    cout << "1.Load from file" << endl;
    cout << "2.Delete Front" << endl;
    cout << "3.Delete End" << endl;
    cout << "4.Delete on Index" << endl;
    cout << "5.Add Front" << endl;
    cout << "6.Add End" << endl;
    cout << "7.Add on Index" << endl;
    cout << "8.Find by Index" << endl;
    cout << "9.Find by Value" << endl;
    cout << "10.Generate random numbers" << endl;
    cout << "11.Display" << endl;
    cout << "0.Main Menu" << endl;
    cout << "Choice: " << endl;
}

void Menu::menuList(List * list) {
    int option;
    string fileName;
    int index, value;



    do{
        displayMenuList();
        cin >> option;
        cout << endl;
        switch (option){
            case 1:
                cout << " Enter file path: " << endl;
                cin >> fileName;
                cout << endl;
                list->loadFromFile(fileName);
                list->display();
                break;

            case 2:
                list->deleteFront();
                list->display();
                break;

            case 3:
                list->deleteEnd();
                list->display();
                break;

            case 4:
                cout << " Enter Index: " << endl;
                cin >> index;
                cout << endl;
                list->deleteByIndex(index);
                list->display();
                break;

            case 5:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                list->addFront(value);
                list->display();
                break;

            case 6:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                list->addEnd(value);
                list->display();
                break;

            case 7:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                cout << " Enter Index: " << endl;
                cin >> index;
                cout << endl;
                list->addByIndex(value,index);
                list->display();
                break;

            case 8:
                cout << " Enter Index: " << endl;
                cin >> index;
                cout << endl;
                list->getByIndex(index);
                list->display();
                break;

            case 9:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                list->getByValue(value);
                list->display();
                break;

            case 10:
                cout << " Enter the Amount: " << endl;
                cin >> value;
                cout << endl;
                list->generateToList(value);
                list->display();
                break;

            case 11:
                list->display();
                break;
        }

    } while (option != 0);
}

void Menu::displayMenuHeap() {
    cout << endl;
    cout << "------Heap------" << endl;
    cout << "1.Load from file" << endl;
    cout << "2.Add" << endl;
    cout << "3.Delete Root" << endl;
    cout << "4.Find by Value" << endl;
    cout << "5.Generate random numbers" << endl;
    cout << "6.Display" << endl;
    cout << "0.Main Menu" << endl;
    cout << "Choice: " << endl;
}

void Menu::menuHeap(Heap * heap) {
    int option;
    string fileName;
    int index, value;



    do{
        displayMenuHeap();
        cin >> option;
        cout << endl;
        switch (option){
            case 1:
                cout << " Enter file path: " << endl;
                cin >> fileName;
                cout << endl;
                heap->loadFromFile(fileName);
                heap->display("","",0);
                break;

            case 2:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                heap->addElement(value);
                heap->display("","",0);
                break;

            case 3:
                heap->deleteRoot();
                heap->display("","",0);
                break;

            case 4:
                cout << " Enter Value: " << endl;
                cin >> value;
                cout << endl;
                heap->getByValue(value);
                heap->display("","",0);
                break;

            case 5:
                cout << " Enter the Amount: " << endl;
                cin >> value;
                cout << endl;
                heap->generateToHeap(value);
                heap->display("","",0);
                break;

            case 6:
                heap->display("","",0);
                break;
        }

    } while (option != 0);
}

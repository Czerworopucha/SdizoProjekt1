#include <iostream>
#include <conio.h>
#include "RNG.h"
#include "Array.h"
#include "List.h"
#include "Heap.h"
#include "Menu.h"
#include "chrono"

using namespace  std;

int main() {
    Array tablica;
    List lista;
    Heap kopiec;
    RNG generator;
    Menu wybor;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int choice;
    do {
        cout << endl;
        cout << "==== MAIN MENU ====" << endl;
        cout << "1.Array" << endl;
        cout << "2.List" << endl;
        cout << "3.Heap" << endl;
        cout << "4.Generate a file with random numbers" << endl;
        cout << "0.Exit" << endl;
        cout << "Choice :" << endl;
        cin >> choice;


        switch (choice) {
            case 1:
                wybor.menuArray(&tablica);
                break;

            case 2:
                wybor.menuList(&lista);
                break;

            case 3:
                wybor.menuHeap(&kopiec);
                break;

            case 4:
                int amount;
                string fileName;
                cout << "Enter the amount: " << endl;
                cin >> amount;
                cout << endl;
                cout << "Enter file path: " << endl;
                cin >> fileName;
                cout << endl;
                generator.randomNumberGeneratorToFile(amount, fileName);
                break;
        }
    }while(choice != 0);


    /*
    for(int i = 20; i <= 200000; i = i*10) {
        for(int j = 0; j<10;j++) {
            kopiec.generateToHeap(i);
            auto start = std::chrono::high_resolution_clock::now();
            //----------------------
            kopiec.getByValue(1000);
            //----------------------
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
            cout << duration.count() << endl;
        }
        cout <<"------------------------------------" << endl;
    }
    system("PAUSE");
    */
    return 0;
}

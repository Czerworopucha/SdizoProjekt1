#ifndef SDIZO_PROJEKT_1_LISTELEMENT_H
#define SDIZO_PROJEKT_1_LISTELEMENT_H


class ListElement {
public:
    int value;
    ListElement *next;
    ListElement *previous;

    ListElement(int value, ListElement *next, ListElement *previous);
    ~ListElement();

};


#endif //SDIZO_PROJEKT_1_LISTELEMENT_H

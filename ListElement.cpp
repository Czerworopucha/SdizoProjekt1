#include "ListElement.h"

ListElement::ListElement(int value, ListElement *next, ListElement *previous) {
    ListElement::value = value;
    ListElement::next = next;
    ListElement::previous = previous;
}

ListElement::~ListElement() = default;

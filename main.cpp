#include <iostream>
#include "Linked_list_class.h"


int main()
{
    IntSLinkedList list;
    int values[] = {10, 15, 2, 6, 4, 7, 40, 8};
    int index[] = {0, 0, 1, 3, 2, 3, 5, 0};
    for (int idx = 0; idx < 8; idx++) {
        list.add(index[idx], values[idx]);
    }
    cout << list.toString();

    return 0;
}
#include <iostream>
// #include "Linked_list_class.h"
#include "Stack_class.h"

int main()
{
    // Test linked list:
    IntSLinkedList my_list;
    int values[] = {10, 15, 2, 6, 4, 7, 40, 8};
    int index[] = {0, 0, 1, 3, 2, 3, 5, 0};
    for (int idx = 0; idx < 8; idx++) {
        my_list.add(index[idx], values[idx]);
    }
    cout << "My linked list: " << my_list.toString() << endl << endl;

    // Test stack:
    IntStack my_stack;
    my_stack.push(1);
    my_stack.push(9);
    my_stack.push(50);
    my_stack.push(10);
    my_stack.pop();
    cout << "My stack: " << my_stack.toString() << endl << endl;

    return 0;
}
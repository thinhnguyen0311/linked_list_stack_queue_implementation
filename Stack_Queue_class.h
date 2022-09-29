#include "Linked_list_class.h"
#include <iostream>

using namespace std;

class IntStack {
private:
    IntSLinkedList *list;

public:
    IntStack(){
        list = new IntSLinkedList();
    }

    ~IntStack(){
        delete list;
    }

    void push(int element){
        list->add(0, element);
    }

    int pop(){
        return list->removeAt(0);
    }

    int top(){
        return list->get(0);
    }

    int size(){
        return list->size();
    }

    bool empty(){
        return list->empty();
    }

    int search(int element){
        return list->indexOf(element);
    }

    string toString(){
        return list->toString();
    }
};


class IntQueue
{
private:
    IntSLinkedList *list;
public:
    IntQueue(){
        list = new IntSLinkedList();
    }

    ~IntQueue(){
        delete list;
    }
    
    void enqueue(int element){
        list->add(element);
    }

    int dequeue(){
        return list->removeAt(0);
    }

    int front(){
        return list->get(0);
    }

    int rear(){
        return list->get(list->size() - 1);
    }

    int size(){
        return list->size();
    }

    bool empty(){
        return list->empty();
    }

    string toString(){
        return list->toString();
    }
};
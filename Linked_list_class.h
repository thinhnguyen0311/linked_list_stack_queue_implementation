#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class IntSLinkedList {
public:
    class Node {
    public:
        int data;
        Node *next;

    public:
        Node() : next(NULL){};
        Node(int data) : data(data), next(NULL){};
    };

private:
    Node *head;
    Node *tail;
    int count;

public:
    IntSLinkedList() : head(NULL), tail(NULL), count(0){};

    ~IntSLinkedList()
    {
        clear();
    }

    void add(int element)
    {
        Node *newNode = new Node(element);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }

    void add(int index, int element)
    {
        if (index < 0 || index > count)
            throw out_of_range("Index is out of range.");

        Node *newNode = new Node(element);

        if (index == 0) {
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
        }
        else if (index == count) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            Node *temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;

            temp = NULL;
            delete temp;
        }

        count++;
    }

    int removeAt(int index)
    {
        if (head == NULL || index < 0 || index > count - 1)
            throw out_of_range("Index is out of range.");

        Node *temp = head;
        int save;

        if (index == 0) {
            if (count == 1) {
                save = head->data;
                head = NULL;
                tail = NULL;

                delete temp;
            }
            else {
                save = head->data;
                head = head->next;

                delete temp;
            }
        }
        else if (index == count - 1) {
            save = tail->data;

            for (int i = 0; i < count - 2; i++) {
                temp = temp->next;
            }
            tail = temp;
            temp = temp->next;

            delete temp;
        }
        else {
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }

            save = temp->next->data;
            Node *temp2 = temp->next;

            temp->next = temp2->next;

            temp = NULL;
            delete temp;
            delete temp2;
        }

        count--;
        return save;
    }

    bool removeItem(int item)
    {
        Node *temp = head;
        for (int i = 0; i < count; i++) {
            if (temp->data == item) {
                removeAt(i);

                temp = NULL;
                delete temp;

                return true;
            }
            else {
                temp = temp->next;
            }
        }

        temp = NULL;
        delete temp;

        return false;
    }

    bool empty()
    {
        return head == NULL;
    }

    int size()
    {
        return count;
    }

    int get(int index)
    {
        if (head == NULL || index < 0 || index > count - 1)
            throw out_of_range("Index is out of range.");

        if (index == 0) {
            return head->data;
        }
        else if (index == count - 1) {
            return tail->data;
        }
        else {
            Node *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void set(int index, int element)
    {
        if (head == NULL || index < 0 || index > count - 1)
            throw out_of_range("Index is out of range.");

        if (index == 0) {
            head->data = element;
        }
        else if (index == count - 1) {
            tail->data = element;
        }
        else {
            Node *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->data = element;

            temp = NULL;
            delete temp;
        }
    }

    int indexOf(int item)
    {
        if (head == NULL) {
            throw out_of_range("Index is out of range.");
        }
        else {
            Node *temp = head;
            for (int i = 0; i < count - 1; i++) {
                if (temp->data == item)
                    return i;
                else
                    temp = temp->next;
            }
        }

        return -1;
    }

    bool contains(int item)
    {
        if (head == NULL) {
            throw out_of_range("Index is out of range.");
        }
        else {
            Node *temp = head;
            for (int i = 0; i < count - 1; i++) {
                if (temp->data == item)
                    return true;
                else
                    temp = temp->next;
            }
        }

        return false;
    }

    void clear()
    {
        if (head == NULL)
            return;
        else {
            while (head->next != NULL) {
                Node *temp = head;
                head = head->next;
                delete temp;
            }

            Node *temp = head;
            head = NULL;
            tail = NULL;
            count = 0;
            delete temp;
            return;
        }
    }

    string toString()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail) {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";

        return ss.str();
    }
};
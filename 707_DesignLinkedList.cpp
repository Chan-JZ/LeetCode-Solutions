#include <iostream>

using namespace std;

class MyLinkedList {
public:
    typedef struct Node {
        int val;
        Node *next;
        Node(int val) : val(val), next(nullptr){}
    } Node;

    Node *head;
    int size;

    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index > size-1) return -1;
        if (head == NULL) return -1;

        Node *ptr = head;
        while (index--) {
            ptr=ptr->next;
        }

        return ptr->val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if (head == NULL) {
            addAtHead(val);
            return;
        }
        Node *ptr = head;

        while (ptr->next != NULL) {
            ptr=ptr->next;
        }

        Node *newNode = new Node(val);
        ptr->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }

        int dIndex = index-1;
        Node *ptr = head;

        while(dIndex-- != 0) {
            ptr=ptr->next;
        }

        Node *newNode = new Node(val);
        Node* temp = ptr->next;
        ptr->next = newNode;
        newNode->next = temp;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index + 1 > size) return;
        if (index == 0) {
            Node *temp = head->next;
            delete head;
            head = temp;
        } else {
            Node *ptr = head;
            int dIndex = index - 1;
            while (dIndex-- != 0) {
                ptr=ptr->next;
            }

            Node *temp = ptr->next->next;
            delete ptr->next;
            ptr->next = temp;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
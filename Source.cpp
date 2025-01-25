#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularDoublyLinkedList {
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }
    void addAtBeginning(int val) {
        Node* temp = new Node(val);
        if (head == nullptr) {
            head = temp;
            head->next = head;
            head->prev = head;
        }
        else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            temp->next = head;
            temp->prev = current;
            head->prev = temp;
            current->next = temp;
            head = temp;
        }
    }

    void addToTail(int e) {
        Node* n = new Node(e);
        if (head == nullptr) {
            head = n;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
        n->next = head;
        head->prev = n;
    }

    bool search(int key) {
        if (head == nullptr) return false;
        Node* temp = head;
        do {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void display() {
        if (head == nullptr) {
            cout << "NULL" << '\n';
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << "<->";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << '\n';
    }

    ~CircularDoublyLinkedList() {
        if (head == nullptr) return;
        Node* temp = head;
        Node* nextNode;
        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }

    int deleteFromHead() {
        int e = -1;
        if (!isEmpty()) {
            e = head->data;
            if (head->next == head) {
                delete head;
                head = nullptr;
            }
            else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                Node* toDelete = head;
                temp->next = head->next;
                head->next->prev = temp;
                head = head->next;
                delete toDelete;
            }
        }
        return e;
    }

    void deleteNode(int e) {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->data == e) {
            deleteFromHead();
            return;
        }
        Node* temp = head;
        do {
            if (temp->next->data == e) {
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                nodeToDelete->next->prev = temp;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found" << endl;
    }

    void displayFromHead() {
        display();
    }

    int getElFromEnd(int n) const {
        if (head == nullptr) return -1;
        int length = 0;
        Node* temp = head;
        do {
            length++;
            temp = temp->next;
        } while (temp != head);
        if (n > length) return -1;
        temp = head;
        for (int i = 0; i < length - n; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
};

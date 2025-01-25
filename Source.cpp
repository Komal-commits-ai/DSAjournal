#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int e, Node* n = nullptr, Node* p = nullptr) {
        data = e;
        next = n;
        prev = p;
    }

    void display(Node* ptr) {
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

class LinkList {
    Node* head;
    Node* tail;

public:
    LinkList() {
        head = tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void addToHead(int ele) {
        Node* newNode = new Node(ele, head);
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void addToTail(int e) {
        Node* newNode = new Node(e, nullptr, tail);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayFromHead() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayFromTail() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    int deleteFromHead() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return -1;
        }
        int e = head->data;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        return e;
    }

    int deleteFromTail() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return -1;
        }
        int e = tail->data;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
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
        if (tail->data == e) {
            deleteFromTail();
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != e) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node not found" << endl;
            return;
        }
        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    ~LinkList() {
        while (!isEmpty()) {
            deleteFromHead();
        }
    }
};

int main() {
    LinkList list;
    list.addToHead(1);
    list.addToHead(2);
    list.addToTail(3);
    list.addToTail(4);
    list.displayFromHead();  // Should display: 2 1 3 4
    list.displayFromTail();  // Should display: 4 3 1 2
    list.deleteFromHead();
    list.displayFromHead();  // Should display: 1 3 4
    list.deleteFromTail();
    list.displayFromHead();  // Should display: 1 3
    list.deleteNode(3);
    list.displayFromHead();  // Should display: 1
    list.deleteNode(10);     // Node not found
    list.displayFromHead();  // Should display: 1
    return 0;
}

#include<iostream>
using namespace std;
template <typename T>
class Stack
{
    T* stack;
    int top;
    int capacity;
public:

    Stack()
    {
        stack = nullptr;
        top = -1;
        capacity = 0;
    }

    Stack(int c)
    {
        if (c < 0)
        {
            cout << "capacity should be greater than 1";
        }
        else
        {
            stack = new T[c];
            top = -1;
            capacity = c;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == (capacity - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(T item)
    {
        if (!isFull())
        {
            top++;
            stack[top] = item;
        }
        else
        {
            cout << "stack is full";
        }
    }

    T pop()
    {
        if (!isEmpty())
        {
            T v;
            v = stack[top];
            top--;
            return v;
        }
        else
        {
            cout << "stack is empty";
        }
    }

    T Top()
    {
        if (!isEmpty())
        {
            return stack[top];
        }
        else
        {
            cout << "Stack is empty";
        }
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = 0; i <= top; i++)
            {
                cout << stack[i] << ",  ";
            }
        }
    }

    ~Stack()
    {
        stack = nullptr;
        top = -1;
        capacity = 0;
    }
};
template <typename T>
class Pair {
    int n1;
    T n2;
public:
    Pair() : n1(0), n2(0) {} 
    Pair(int a, T b) : n1(a), n2(b) {} 
    void DwithPriority() { cout << '(' << n2 << ',' << n1 << "), "; }
    void DwithoutPriority() { cout << n2 << ","; }
    bool compareP(Pair a) { return a.n1 > n1; }
    void swap(Pair& a) { 
        int temp1 = a.n1;
        T temp2 = a.n2;
        a.n1 = n1;
        a.n2 = n2;
        n1 = temp1;
        n2 = temp2;
    }
    void setN(T n) { n2 = n; }
    T getN() { return n2; }
    void setP(int n) { n1 = n; }
    int getP() { return n1; }
};

template <typename T>
class PriorityQueue {
    Pair<T>* cqueue;
    int real;
    int front;
    int size;
public:
    PriorityQueue() : cqueue(nullptr), real(-1), front(-1), size(0) {}
    PriorityQueue(int s) {
        cqueue = new Pair<T>[s]; 
        real = -1;
        front = -1;
        size = s;
    }
    /*PriorityQueue(PriorityQueue<T> a)
    {
        cqueue= a.cqueue;
        real = a.real;
         front=a.front;
         size=a.size;
    }*/
    ~PriorityQueue() {
        delete[] cqueue; 
    }
    bool isEmpty() {
        return real == -1 && front == -1; 
    }
    bool isFull() {
        return front == (real + 1) % size; 
    }
    void insert(int element, int priority) {
        if (isFull()) {
            cout << "Queue is full";
            return;
        }
        real = (real + 1) % size;
        cqueue[real].setN(element);
        cqueue[real].setP(priority);
        if (front == -1) {
            front = 0;
        }
    }
    T getHighestPriorityElement()
    {
        if (!isEmpty()) 
        {
            int check = cqueue[front].getP();
            for (int i = 0; i <= real; i++)
            {
                if (check < cqueue[i].getP())
                {
                    check = cqueue[i].getP();
                }
            }
            int j = 0;
            for (int i = 0;i <= real; i++)
            {
                if (cqueue[i].getP() == check)
                {
                    j = i;
                }
            }
            return cqueue[j].getN();
        }
        else
        {
            cout << "Queue is empty";
            return 0;
        }
    }
    void removeHighestPriorityElement()
    {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }
        int check = cqueue[front].getP();
        for (int i = 0; i <= real; i++)
        {
            if (check < cqueue[i].getP())
            {
                check = cqueue[i].getP();
            }
        }
        int j = 0;
        for (int i = 0; i <= real; i++)
        {
            if (cqueue[i].getP() == check)
            {
                j = i;
            }
        }
        for (int i = j; i >0; i--)
        {
            cqueue[i].setP(cqueue[i - 1].getP());
            cqueue[i].setN(cqueue[i - 1].getN());
        }
        if (real == front) {
            real = front = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }
    
    void dwithpriority() {
        if (!isEmpty()) {
            if (front <= real) {
                for (int i = front; i <= real; i++) {
                    cqueue[i].DwithPriority();
                }
            }
            else {
                for (int i = front; i < size; i++) {
                    cqueue[i].DwithPriority();
                }
                for (int i = 0; i <= real; i++) {
                    cqueue[i].DwithPriority();
                }
            }
        }
    }
    void dwithoutpriority() {
        if (!isEmpty()) {
            if (front <= real) {
                for (int i = front; i <= real; i++) {
                    cqueue[i].DwithoutPriority();
                }
            }
            else {
                for (int i = front; i < size; i++) {
                    cqueue[i].DwithoutPriority();
                }
                for (int i = 0; i <= real; i++) {
                    cqueue[i].DwithoutPriority();
                }
            }
        }
    }
};

int main() {
    PriorityQueue<int> a(10); 
    a.insert(9, 2);
    a.insert(10, 1);
    a.insert(1, 5);
    a.insert(1, 10);
    a.insert(1, 10);
    a.insert(1, 10);
    a.insert(22, 12);
    a.insert(3, 11);
    a.removeHighestPriorityElement();
  
    cout << a.getHighestPriorityElement();
    return 0;
}
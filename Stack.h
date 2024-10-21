#ifndef STACK_H
#define STACK_H
template <typename T>
class Stack
{
	T* stack;
	int top;
	int capacity;
public:
	Stack();
	Stack(int c);
	bool isEmpty();
	bool isFull();
	void push(T item);
    int pop();
	T Top();
	void display();
	~Stack();
};

#endif
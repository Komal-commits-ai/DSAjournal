#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
template <typename T>
class Queue
{
	T * queue;
	int real;
	int front;
	int size;
public:
	Queue();
	Queue(int s);
	bool isEmpty();
	bool isFull();
	void enQueue(T n);
	T deQueue();
	T showFront();
	void display();
	T ShiftedQueue();

};
#endif

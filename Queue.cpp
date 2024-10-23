#include"Queue.h"
#include<iostream>
using namespace std;
template <typename T>
Queue<T>::Queue()
{
	queue = nullptr;
	real = -1;
	front = -1;
}


template <typename T>
Queue<T>::Queue(int s)
{
	queue = new T[s];
	real = -1;
	front = -1;
	size = s;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	if (real == front == -1&& real==front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool Queue<T>::isFull()
{
	if (real == size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void Queue<T>::enQueue(T n)
{
	if (isFull())
	{
		return;
	}
	else
	{
		real=real+1;
		queue[real] = n;
		if (front == -1)
		{
			front = 0;
		}
	}
}

template <typename T>
T Queue<T>::deQueue()
{
	if (isEmpty())
	{
		cout << "Stack is empty";
	}
	else
	{
		int element = queue[front];
		if (real == front)
		{
			real = front = -1;
		}
		else
		{
			front++;
		}
		return element;
	}
}

template <typename T>
T Queue<T>::showFront()
{
	if (!isEmpty())
	{
		return queue[front];
	}
	else
	{
		cout << "Stack is full";
	}
}

template <typename T>
void Queue<T>::display()
{
	if (!isEmpty())
	{
		for (int i = front; i <= real; i++)
		{
			cout << queue[i] << ",";
		}
	}
	else
	{
		return;
	}
}

template <typename T>
T Queue<T>::DeQueue()
{
	if (isEmpty())
	{
		cout << "Stack is empty";
	}
	else
	{
		int element = queue[front];
		if (real == front)
		{
			real = front = -1;
		}
		else
		{
			for (int i = front; i <=real; i++)
			{
				queue[i - 1] = queue[i];
			}
			real--;
		}
		return element;
	}
} 
int main()
{
	Queue<int> a(5);
	a.enQueue(3);
	a.enQueue(2);
	a.enQueue(1);
	a.enQueue(5);
	a.enQueue(7);
	a.display();
	a.DeQueue();
	a.display();
}
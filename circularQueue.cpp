#include<iostream>
using namespace std;
template <typename T>
class CircularQueue
{
	T* cqueue;
	int real;
	int front;
	int size;
public:
	CircularQueue()
	{
		cqueue = nullptr;
		real = -1;
		front = -1;
		size = 0;

	}

	CircularQueue(int s)
	{
		cqueue = new T[s];
		real = -1;
		front = -1;
		size = s;
	}

	bool isEmpty()
	{
		if (real == front == -1)
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
		if (front  == (real+1)%size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enQueue(T n)
	{
		if (isFull())
		{
			cout<<"Queue is full";
		}
		else
		{
			real = (real + 1)%size;
			cqueue[real] = n;
			if (front == -1)
			{
				front = 0;
			}
		}
	}
	
	T deQueue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty";
		}
		else
		{
			int element = cqueue[front];
			if (real == front)
			{
				real = front = -1;
			}
			else
			{
				front=(front+1)%size;
			}
			return element;
		}
	}

	T showFront()
	{
		if (!isEmpty())
		{
			return cqueue[front];
		}
		else
		{
			cout << "Stack is full";
		}
	}

	void display()
	{
		if (!isEmpty())
		{
			if (front<=real)
			{
				for (int i = front; i <= real; i++)
				{
					cout << cqueue[i] << ',';
				}
			}
			else
			{
				for (int i = front; i < size; i++)
				{
					cout << cqueue[i] << ",";
				}
				for (int i = 0; i <= real; i++)
				{
					if (i == real)
					{
						cout << cqueue[i];
					}
					else
					{
						cout << cqueue[i] << ",";
					}
				}
			}
		}
		else
		{
			return;
		}
	}
};
int main()
{
	CircularQueue<int> a(7);
	a.enQueue(1);
	a.enQueue(2);
	a.enQueue(3);
	a.enQueue(4);
	a.enQueue(5);
	a.enQueue(6);
	a.enQueue(7);
	a.deQueue();
	a.deQueue();
	a.deQueue();
	a.deQueue();
	a.enQueue(8);
	a.enQueue(9);
	a.enQueue(10);
	a.enQueue(11);
	a.deQueue();
	a.deQueue();
	a.deQueue();
	a.deQueue();
	a.display();
}




#include"Stack.h"
#include <iostream>
using namespace std;
template <typename T>
Stack<T>::Stack()
{
	stack = nullptr;
	top = -1;
	capacity = 0;
}
template <typename T>
Stack<T>::Stack(int c)
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
template <typename T>
bool Stack<T>:: isEmpty()
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
template <typename T>
bool Stack<T>::isFull()
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
template <typename T>
void Stack<T>:: push(T item)
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
template <typename T>
int Stack<T>:: pop()
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
template <typename T>
T Stack<T>::Top()
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
template <typename T>
void Stack<T>:: display()
	{
		if (!isEmpty())
		{
			for (int i = 0; i <= top; i++)
			{
				cout << stack[i] << ",  ";
			}
		}
	}
template <typename T>
 Stack<T>::~Stack()
	{
		stack = nullptr;
		top = -1;
		capacity = 0;
	}


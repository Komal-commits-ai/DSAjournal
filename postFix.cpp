#include"String.h"
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
			stack = new T[c + 1];
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

	int pop()
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

int precedence(char op) 
{
	if (op == '^')
		return 3;
	else if (op == '*' || op == '/')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	else
		return 0;
}

bool isOperator(char c) 
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isalnum(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}
String postFix(String str)
{
	int n = 0;
	int l = str.getLength();
	String postF(l*l);
	Stack<char> stk(l);
	for (int i = 0; i < l; i++)
	{
		if (isalnum(str[i]))
		{
			postF[n]=str[i]-'0';
			while (isalnum(str[i+1])&&i+1<l)
			{
				i++;
				postF[n] = postF[n] * 10;
				postF[n] = postF[n] + str[i] - '0';
			}
			n++;
			postF[n] = '.';
			n++;
		}
		else if (isOperator(str[i]))
		{
			if (!stk.isEmpty())
			{
				while (!stk.isEmpty()&&precedence(str[i]) <= precedence(stk.Top()) && stk.Top() != 40)
				{
					postF[n] = stk.pop();
					n++;
				}
			}
			stk.push(str[i]);
		}
		else if (str[i] == '(')
		{
			stk.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (stk.Top() != '(')
			{
				postF[n] = stk.pop();
				n++;
			}
			stk.pop();
		}
	}
	while (!stk.isEmpty())
	{
		postF[n] = stk.pop();
		n++;
	}
	postF[n] = '\0';
	return postF;
}
void display(String str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		cout << str[i];
	}
}

double evaluateBypostFix()
{
	String a;
	a.input();
	String b= postFix(a);
	int l = a.getLength();
	Stack<double> result(l);
	for (int i = 0; b[i]!='\0'; i++)
	{
		if (b[i+1]=='.')
		{
			result.push(b[i]);
			i++;
		}
		else if (isOperator(b[i]))
		{
			int n1 = result.pop();
			int  n2= result.pop();
			if (b[i] == '-')
			{
				result.push((n2 - n1));
			}
			else if (b[i] == '+')
			{
				result.push((n2 +n1));
			}
			else if (b[i] == '*')
			{
				result.push(n2 * n1);
			}
			else if (b[i] == '/')
			{
				result.push((n2 / n1));
			}
			else if (b[i] == '^')
			{
				int a = n2;
				for (int i = 0; i < n1-1; i++)
				{
					n2 = n2 * a;
				}
				result.push(n2);
			}
		}
	}
	double r = result.pop();
	return r;
}
int  main()
{
	int a = evaluateBypostFix();
	cout << a;
	
}

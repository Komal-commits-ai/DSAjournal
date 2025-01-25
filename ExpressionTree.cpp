#include<iostream>
#include"String.h"
using namespace std;

template <typename T>
class Queue
{
	T* queue;
	int size;
	int real;
	int front;
public:
	Queue()
	{
		queue = nullptr;
		real = -1;
		front = -1;
	}
    Queue(int s)
	{
		queue = new T[s];
		real = -1;
		front = -1;
		size = s;
	}


	bool isEmpty()
	{
		if (real == front == -1 && real == front)
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
		if (real == size - 1)
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
			return;
		}
		else
		{
			real = real + 1;
			queue[real] = n;
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
			cout << "Stack is empty";
		}
		else
		{
			T element = queue[front];
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
	T showFront()
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
	void display()
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
	T ShiftedQueue()
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
				for (int i = front; i <= real; i++)
				{
					queue[i - 1] = queue[i];
				}
				real--;
			}
			return element;
		}
	}
};
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

	Stack(int s)
	{
		if (s < 0)
		{
			cout << "capacity should be greater than 1";
		}
		else
		{
			stack = new T[s];
			top = -1;
			capacity = s;
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
String postFix(String str) {
	int n = 0;
	int l = str.getLength();
	String postF(l * l);
	Stack<char> stk(l);

	for (int i = 0; i < l; i++) {
		if (isalnum(str[i])) {
			postF[n++] = str[i];
		}
		else if (isOperator(str[i])) {
			while (!stk.isEmpty() && precedence(str[i]) <= precedence(stk.Top()) && stk.Top() != '(') {
				postF[n++] = stk.pop();
			}
			stk.push(str[i]);
		}
		else if (str[i] == '(') {
			stk.push(str[i]);
		}
		else if (str[i] == ')') {
			while (!stk.isEmpty() && stk.Top() != '(') {
				postF[n++] = stk.pop();
			}
			if (!stk.isEmpty()) stk.pop(); // Remove '(' from stack
		}
	}

	while (!stk.isEmpty()) {
		postF[n++] = stk.pop();
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
class node
{
public:
	char data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
};
Stack<node*> TreeInfinixExpression(String s)
{
	String post = postFix(s);
	Stack<node *> stk;
	for (int i = 0; i < post.getLength(); i++)
	{
		if (isalnum(post[i]))
		{
			node* a=new node(post[i]);
			stk.push(a);
		}
		else if (isOperator(post[i]))
		{
			node* t1 =stk.pop();
			node *t2 =stk.pop();
			node *a=new node(post[i]);
			stk.push(a);
			a->left = t2;
			a->right = t1;
		}
	}
	return stk;
}

node* TreePrePostExpression(String s)
{
	String post = postFix(s);
	Stack<node*> stk(post.getLength());
	for (int i = 0; i < post.getLength(); i++)
	{
		if (isalnum(post[i]))
		{
			node* a = new node(post[i]);
			stk.push(a);
		}
		else if (isOperator(post[i]))
		{
			node* t1 = stk.pop();
			node* t2 = stk.pop();
			node* a = new node(post[i]);
			stk.push(a);
			a->left = t2;
			a->right = t1;
		}
	}
	node *a = stk.pop();
	return a;
}
void inorderTraversal(node* root) {
	if (root == nullptr) return;
	inorderTraversal(root->left);
	cout << root->data << ' ';
	inorderTraversal(root->right);
}
void preorderTraversal(node* root) {
	if (root == nullptr) return;
	cout << root->data << ' ';
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
void postorderTraversal(node* root) {
	if (root == nullptr) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data << ' ';
}

void levelorderTraversal(node* root) {
	if (root == nullptr) return;
	Queue<node*> q(1000);
	q.enQueue(root);

	while (!q.isEmpty()) {
		node* current = q.showFront();
		q.deQueue();
		cout << current->data << ' ';

		if (current->left != nullptr) {
			q.enQueue(current->left);
		}
		if (current->right != nullptr) {
			q.enQueue(current->right);
		}
	}
}



int main()
{
	inorderTraversal(TreePrePostExpression("1+2-9*7")); cout << '\n';
	preorderTraversal(TreePrePostExpression("1+2-9*7")); cout << '\n';
	postorderTraversal(TreePrePostExpression("1+2-9*7")); cout << '\n';
	levelorderTraversal(TreePrePostExpression("1+2-9*7"));
}
#include<iostream>
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

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
};
class BST
{
public:
	node* root;
	BST()
	{
		root = nullptr;
	}
	void inorderTraversal(node* root) {
		if (root == nullptr) return;
		inorderTraversal(root->left);
		cout << root->data << ' ';
		inorderTraversal(root->right);
	}
	
	void search( int e)
	{
		node* temp = root;
		int flag = false;
		while (temp != nullptr || flag == false)
		{
			if (temp->data > e)
			{
				temp = temp->left;
			}
			else if (temp->data < e)
			{
				temp = temp->right;
			}
			else
			{
				flag = true;
			}
		}
		if (flag == true)
		{
			cout << "ITEM FOUND" << '\n';
		}
		else
		{
			cout << "ITEM NOT FOUND" << '\n';
		}
	}
	void insertion(int e) {
		if (root == nullptr) {
			root = new node(e);
			return;
		}

		node* temp = root;
		node* parent = nullptr;

		while (temp != nullptr) {
			parent = temp;
			if (e < temp->data) {
				temp = temp->left;
			}
			else if (e > temp->data) {
				temp = temp->right;
			}
			else {
				cout << "ITEM ALREADY EXIST" << '\n';
				return;
			}
		}

		if (e < parent->data) {
			parent->left = new node(e);
		}
		else {
			parent->right = new node(e);
		}
	}
	node* deleteNode(node* root, int key) {
		if (root == nullptr) {
			return root;
		}

		// Traverse the tree to find the node to be deleted
		if (key < root->data) {
			root->left = deleteNode(root->left, key);
		}
		else if (key > root->data) {
			root->right = deleteNode(root->right, key);
		}
		else {
			// Node to be deleted found

			// Case 1: Node with no child
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				return nullptr;
			}

			// Case 2: Node with one child
			if (root->left == nullptr) {
				node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				node* temp = root->left;
				delete root;
				return temp;
			}

			// Case 3: Node with two children
			// Get the in-order successor (smallest in the right subtree)
			node* temp = minValueNode(root->right);

			// Copy the in-order successor's data to this node
			root->data = temp->data;

			// Delete the in-order successor
			root->right = deleteNode(root->right, temp->data);
		}

		return root;
	}

	node* minValueNode(node* root) {
		node* current = root;
		while (current && current->left != nullptr) {
			current = current->left;
		}
		return current;
	}

	
};

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
	BST a;
	a.insertion(4);
	a.insertion(2);
	a.insertion(6);
	a.insertion(1);
	a.insertion(3);
	a.insertion(5);
	a.insertion(7);
	levelorderTraversal(a.root);

}

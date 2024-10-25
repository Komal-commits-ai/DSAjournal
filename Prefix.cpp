#include<iostream>
#include"String.h"
#include<algorithm> 
using namespace std;

template <typename T>
class Stack {
    T* stack;
    int top;
    int capacity;
public:
    Stack() {
        stack = nullptr;
        top = -1;
        capacity = 0;
    }
    Stack(int c) {
        if (c < 0) {
            cout << "capacity should be greater than 1";
        }
        else {
            stack = new T[c + 1];
            top = -1;
            capacity = c;
        }
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == (capacity - 1);
    }
    void push(T item) {
        if (!isFull()) {
            top++;
            stack[top] = item;
        }
        else {
            cout << "stack is full";
        }
    }
    T pop() {
        if (!isEmpty()) {
            T v = stack[top];
            top--;
            return v;
        }
    }
    T Top() {
        if (!isEmpty()) {
            return stack[top];
        }
    }
    void display() {
        if (!isEmpty()) {
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << ",  ";
            }
        }
    }
    ~Stack() {
        delete[] stack;
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isalnum(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}


string infixToPrefix(string str)
{
    reverse(str.begin(), str.end());
    int n = 0;
    int l = str.length();
    string prefix;
    Stack<char> stk(l);
    for (int i = 0; i < l; i++)
    {
        if (isalnum(str[i]))
        {
            prefix += str[i];
        }
        else if (str[i] == ')')
        {
            stk.push(str[i]);
        }
        else if (str[i] == '(')
        {
            while (!stk.isEmpty() && stk.Top() != ')')
            {
                prefix += stk.pop();
            }
            stk.pop();
        }
        else if (isOperator(str[i]))
        {
            while (!stk.isEmpty() && precedence(stk.Top()) > precedence(str[i])) {
                prefix += stk.pop();
            }
            stk.push(str[i]);
        }
    }
    while (!stk.isEmpty()) 
    {
        prefix += stk.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

double evaluateByPrefix() {
    string a;
    cout << "Enter an expression: ";
    cin >> a;
    string b = infixToPrefix(a);
    int l = b.length();
    Stack<double> result(l);
    reverse(b.begin(), b.end());
    for (int i = 0; i < l; i++) {
        if (isalnum(b[i])) {
            result.push(b[i] - '0');
        }
        else if (isOperator(b[i])) {
            double n1 = result.pop();
            double n2 = result.pop();
            switch (b[i]) {
            case '+': result.push(n1 + n2); break;
            case '-': result.push(n1 - n2); break;
            case '*': result.push(n1 * n2); break;
            case '/': result.push(n1 / n2); break;
            case '^': result.push(pow(n1, n2)); break;
            }
        }
    }
    return result.pop();
}

int main() 
{
   cout<< evaluateByPrefix();
}
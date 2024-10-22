#include<iostream>
#include"String.h"
using namespace std;

int DigitSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return (n % 10) + DigitSum(n / 10);
	}
}

int factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return factorial(n - 1) * n;
}

int fibonacco(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return fibonacco(n - 1) + fibonacco(n - 2);
}

void reverseStr(String s)
{
	if (s.isEmpty())
	{
		return;
	}
	else
	{
		s.reverse();
		cout << s[0];
		s.substr();
		s.reverse();
		reverseStr(s);
	}

}

int isX(String s)
{
	for (int i = s.getLength() - 1; i >= 0; i--)
	{
		if (s[i] != 'x')
		{
			for (int j = i; j >= 0; j--)
			{
				if (s[j] == 'x')
				{
					return j;
				}
			}
		}
	}
	return -1;
}

String xAtEnd(String s)
{
	if (isX(s) == -1)
	{
		return s;
	}
	s.remove(isX(s));
	return xAtEnd(s.concatenate('x'));
}
int main()
{
	cout << fibonacco(2);
}

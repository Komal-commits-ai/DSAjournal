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
int main()
{
	cout << fibonacco(2);
}
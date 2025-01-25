#include <iostream>
using namespace std;
class Hash
{
	int* list;
	int* index;
	int i;
	int size;
public:
	Hash()
	{
		list = nullptr;
		index = nullptr;
		i = 0;
		size = 0;;
	}
	Hash(int n)
	{
		list = new int[n];
		index = new int[n];
		i = 0;
		size = n;
	}
	void hash(int n)
	{
		for (int k = 0; k <= i; k++)
		{
			if (list[k] == n)
			{
				cout << index[k]<<'\n';
			}
		}
	}
	bool findindex(int n)
	{
		for (int k = 0; k < i; k++)
		{
			if (index[k] == n)
			{
				return true;
			}
		}
		return false;
	}
	void insert(int n)
	{
		if (size == i-1)
		{
			this->resize();
		}
		list[i] = n;
		int result = 0;
		while (n!= 0)
		{
			result = result + (n% 10);
			n= n/ 10;
		}
		int in = result % 10;
		int k = 1;
		int l = in;
		while (findindex(in) == 1)
		{
			int m = k * k;
			in = l + m;
			k++;
		}
		index[i] = in;
		i++;
	}
	void resize()
	{
		int* list1 = new int[size*size];
		int* index1 = new int[size*size];
		for (int k = 0; k <= i; k++)
		{
			list1[k] = list[k];
		}
		for (int k = 0; k <= i; k++)
		{
			index1[k] = index[k];
		}
		size = size * size;
		list = list1;
		index = index1;
		delete[]list1;
		delete[]index1;
	}
	void display()
	{
		for (int k = 0; k <= i-1; k++)
		{
			cout << list[k] << ":" << index[k] << '\n';
		}
	}
};
int main()
{
	Hash a(10);
	a.insert(12);
	a.insert(13);
	a.insert(15);
	a.insert(16);
	a.insert(17);
	a.insert(18);
	a.insert(19);
	a.insert(23);
	a.insert(21);
	a.display();
	a.hash(15);
}
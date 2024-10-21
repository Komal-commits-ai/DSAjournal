#include"String.h"
#include<iostream>
String::String()
{
	data = nullptr;
	size = 0;
	cout << "String()";
}
String::String(char c)
{
	size = 2;
	data = new char[2];
	data[0] = c;
	data[1] = '\0';
	cout << "  one arg";
}
;/*samples inputs:
* after using display
k print:k
f print:f*/

String::String(const char* c)
{
	if (c == nullptr || c[0] == '\0')
	{
		data = nullptr;
		size = 0;
		return;
	}
	else
	{
		int i = 0;
		while (c[i] != '\0')
		{
			i++;
		}
		size = i;
	}
	data = new char[size + 1];
	int i2 = 0;
	while (c[i2] != '\0')
	{
		data[i2] = c[i2];
		i2++;
	}
	data[i2] = '\0';
	cout << "String()parameterized";
}

String::String(const String& c) 
{
	if (c.size == 0)
	{
		return;
		size = 0;
		data = nullptr;
	}
	else
	{
		size = c.size;
		data = new char[size + 1];
		int i = 0;
		while (i < size)
		{
			data[i] = c.data[i];
			i++;
		}
		data[i] = '\0';
	}
	std::cout << "\ncopy ctor";
}
/*null rakhne ki zarorat kio nhi padi???*/
String::~String()
{
	if (!isEmpty())
	{
		delete[]data;
		data = nullptr;
		size = 0;
	}
	cout << "~A()";
}
bool String::isEmpty() const
{
	if (data == nullptr || data[0] == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*sample inputs:
"komal" print:0
"" print:1
simple declaration print:0
*/

int String::getLength() const
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		int i = 0;
		while (data[i] != '\0')
		{
			i++;
		}
		return i;
	}
}
/*sample inputs:
simple declaration :0
"komal":5
"k":1
"":0*/

void String::display() const
{
	if (isEmpty())
	{
		return;
	}
	else
	{
		int i = 0;
		std::cout << '\n';
		while (data[i] != '\0')
		{
			std::cout << data[i];
			i++;
		}
	}
}
/*sample inputs:
"" ,simple declaration :no output
"komal":komal
"zahid":zahid*/
int String::getSize() const
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		return size;
	}
}
/*sample inputs:
komal:5
"":0
nullptr:0*/
void String::resize(int newSize)
{
	if (newSize <= 0)
	{
		this->~String();
	}
	else
	{
		char* str = new char[newSize + 1];
		int i = 0;
		if (newSize < size)
		{
			while (i < newSize)
			{
				str[i] = data[i];
				i++;
			}
			str[i] = '\0';
		}
		else
		{
			while (i < size)
			{
				str[i] = data[i];
				i++;
			}
			str[i] = '\0';
		}
		delete[]data;
		size = newSize;
		data = str;
	}
}
/*sample inputs:
pakistan newSize=5  console:pakis
pakistan newSize=10  console:pakistan
pakistan newSize=-1   console:
*/
void String::input()
{
	std::cout << "\nenter your string:";
	size = 3;
	data = new char[size];
	std::cin.get(data[0]);
	int i = 0;
	while (data[i] != '\n')
	{
		i++;
		std::cin.get(data[i]);
		if (i == (size - 1))
		{
			resize(size * 2);
		}
	}
	data[i] = '\0';
}
const char& String::at(const int index) const
{
	if (index > 0 && index < size)
	{
		return data[index];
	}
	else
	{
		exit(0);
	}
}
/*sample inputs:
komal ind:4 :l
8:no output*/
int String::find(String substr, int start)const
{
	if (isEmpty() || (substr.data == nullptr) || (substr.data[0] == '\0') || start > size)
	{
		return -1;
	}
	else
	{
		for (int i = start; i < size; i++)
		{
			int check = 0;
			if (data[i] == substr.data[0])
			{
				int k = 0;
				for (int j = i; k < substr.size; j++)
				{
					if (data[j] == substr.data[k])
					{
						check++;
					}
					k++;
				}
				if (check == substr.size)
				{
					return i;
				}
			}
		}
		return -1;
	}
}

void String::insert(int index, String* substr)
{
	if (!isEmpty() && substr != nullptr && substr->data[0] != '\0' && index > 0 && index < size)
	{
		size = size + substr->size;
		char* newstr = new char[size + 1];
		int i = 0;
		while (i < index)
		{
			newstr[i] = data[i];
			i++;
		}
		for (int j = 0; j < substr->size; j++)
		{
			newstr[i] = substr->data[j];
			i++;
		}
		while (data[index] != '\0')
		{
			newstr[i] = data[index];
			index++;
			i++;
		}
		newstr[i] = '\0';
		delete[]substr;
		delete[]data;
		data = newstr;
	}
}
/*not working insert*/
void String::remove(const int index, const int count)
{
	size = size - count;
	char* str = new char[size + 1];
	int i = 0;
	while (i < index)
	{
		str[i] = data[i];
		i++;
	}
	int k = i + count;
	while (data[k] != '\0')
	{
		str[i] = data[k];
		k++;
		i++;
	}
	str[i] = '\0';
	delete[]data;
	data = str;
}
int String::replace(const String& old, const String& newsubstr)
{
	int count = 0;
	int check = find(old, 0);
	return count;
}
void cpyStr(char* d, char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
}
void String::copyString(String& s)
{
	int i = 0;
	while (s.data[i] != '\0')
	{
		data[i] = s.data[i];
		i++;
	}
	size = i;
	data[i] = '\0';

}
char String::getdata(int i) const
{
	return data[i];
}
void String::setData(int i,char c) 
{
	data[i] = c;
	std::cout << data[i];
}
void String::setData(char i) const
{

}
String String::concatenate(const String& s2)const
{
	if (this->isEmpty() && s2.isEmpty())
	{
		String s{};
		return s;
	}
	if (this->isEmpty())
	{
		return s2;
	}
	if (s2.isEmpty())
	{
		return *this;
	}
	String s;
	s.data = new char[getLength() + s2.getLength() + 1];
	int i = 0;
	while (data[i] != '\0')
	{
		s.data[i] = data[i];
		i++;
	}
	int j = 0;
	while (s2.data[j] != '\0')
	{
		s.data[i] = s2.data[j];
		j++;
		i++;
	}
	s.data[i] = '\0';
	s.size = i;
	return s;
}


void String::trimLeft()
{
	int i =0;
	while (data[i] == '\n' || data[i] == '\t' || data[i] == ' ')
	{
		i++;
	}
	if (i != 0)
	{
		int k = 0;
		while (i < size)
		{
			data[k] = data[i];
			i++;
			k++;
		}
		this->resize(k);
	}
}


char& String:: operator [](int i)
{
	return data[i];
}
ostream& operator<<(std::ostream& out, const String& str)
{
	str.display();
	return out;
}
istream& operator >>(istream& in, String& str)
{
	str.input();
	return in;
}
void String::operator =(const String& c)
{
	if (c.size == 0)
	{
		return;
		size = 0;
		data = nullptr;
	}
	else
	{
		size = c.size;
		data = new char[size + 1];
		int i = 0;
		while (i < size)
		{
			data[i] = c.data[i];
			i++;
		}
		data[i] = '\0';
	}
	cout << "Operator =";
}
 String:: operator String() const
{
	 cout << "type cast operator";
	 int a = 10;
	 return a;
}

void String:: trimRight()
{
	int i = size - 1;
	int check = 0;
	while (data[i] == '\n' || data[i] == '\t' || data[i] == ' ')
	{
		check++;
		i--;
	}
	if (check != 0)
	{
		size = size - check;
		this->resize(size);
	}
}

void String::trim()
{
	this->trimLeft();
	this->trimRight();
}

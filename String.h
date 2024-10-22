#ifndef STRING_H
#define STRING_H
#include<iostream>
using namespace std;
void cpyStr(char* d, char* s);
class String
{
	char* data;
	int size;
public:
	String();
	String(char c);
	String(const char* c);
	String(const String& c);
	~String();
	bool isEmpty() const;
	int getLength() const;
	void display() const;
	int getSize() const;
	void resize(int newSize);
	void input();
	const char& at(const int index)const;
	int find(String substr, int start = 0)const;
	void insert(int index, String* substr);
	void remove(int index, int count = 1);
	int replace(const String& old, const String& newsubstr);
	void copyString(String& s);
	void trimLeft();
	String concatenate(const String& s2)const;
	char getdata(int i)const;
	void setData(int i,char c);
	void setData(char i) const;
	char & operator [](int i);
	void operator =(const String& c);
	operator String()const;
	friend ostream& operator <<(ostream& out, const String& str); 
	friend istream& operator >>(istream& in, String& str);
	void trimRight();
	void trim();
        void reverse();
        void substr();
	/*void makeUpper();
	void makeLower();
	void reverse();
	void shrink();
	int compare(string& s2);*/
};
#endif








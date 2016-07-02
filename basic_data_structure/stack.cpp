#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Stack
{
	int size;
	int capacity;
	vector<T> element;
};

template<class T> void print(Stack<T> S)
{
	for(int i = S.element.size()-1; i >= 0; i--)
		cout << S.element[i]<<",";
	cout << endl;
};

template<class T> void init(Stack<T> &S, int size)
{
	for(int i = 0; i < size; i++)
	{
		S.element.push_back(T(i));
	}
	S.size = size;
	S.capacity = size * 2;
	return;
};

template<class T> void push(Stack<T> &S, T a)
{
	S.element.push_back(a);
	S.size++;
	return;
};

template<class T> T pop(Stack<T> &S)
{
	if (S.size < 0)
	{
		cout << "empty stack!!! No elements to pop out" << endl;
		return -1;
	}
	T result = S.element[S.size-1];
	S.size--;
	S.element.erase(S.element.end()-1);
	return result;
};

template<class T> T top(Stack<T> &S)
{
	if (S.size  < 0)
	{
		cout << "empty stack!!! No element on top" << endl;
		return -1;
	}
	return S.element[S.size-1];
};

template<class T> int len(Stack<T> &S)
{
	return S.size;
};

int main()
{
	Stack<int> s;
	init(s, 10);
	push(s, 11);
	cout << "after push the 11 element, the stack is as follows" << endl;
	print(s);
	cout << "pop the element" << pop<int>(s) << endl;
	cout << "after pop the element, the stack is as follows" << endl;
	print(s);
	return 0;
}

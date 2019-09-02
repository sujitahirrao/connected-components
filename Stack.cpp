#include "Stack.h"


using namespace std;


Stack::Stack()
{
	top = -1;
}


Stack::Stack(int size)
{
	top = -1;
	arr = new int[size];
}


Stack::~Stack()
{
	delete[] arr;
}


void Stack::push(int ele)
{
	if (top == (length - 1))
		throw "Can't push onto a full stack";
	else
	{
		top++;
		arr[top] = ele;
	}
	return;
}


int Stack::pop()
{
	if (top == -1)
		throw "Can't pop from an empty stack";
	
	int ele = arr[top];
	top--;
	length--;

	return ele;
}


bool Stack::isEmpty()
{
	return (top < 0);
}


void Stack::display()
{
	for (int i = 0; i <= top; i++)
		cout << arr[i] << " ";
	cout << endl;
}

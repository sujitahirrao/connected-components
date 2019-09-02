#pragma once
#include<iostream>


class Stack
{
private:
	
	int *arr;
	int top, length;

public:
	
	Stack();
	Stack(int);
	
	~Stack();
	
	void push(int);

	int pop();
	
	bool isEmpty();
	
	void display();
};

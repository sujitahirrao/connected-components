#pragma once

#include<iostream>


struct Node
{
	int ele;
	Node* next;
};


class Queue
{
public:
	Node *front, *rear;

	Queue();

	~Queue();

	Node* newNode(int);

	void enQueue(int);
	
	Node* deQueue();
};

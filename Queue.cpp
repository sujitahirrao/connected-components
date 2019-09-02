#include "Queue.h"


using namespace std;


Queue::Queue()
{
	front = rear = NULL;
}


Queue::~Queue()
{
	while (front != NULL)
	{
		Node *temp = front;
		front = front->next;
		delete temp;
	}
	rear = NULL;
}


Node* Queue::newNode(int ele)
{
	Node* temp = new Node();
	temp->ele = ele;
	temp->next = NULL;
	return temp;
}


void Queue::enQueue(int ele)
{
	Node* temp = newNode(ele);

	if (this->rear == NULL) {
		this->front = this->rear = temp;
		return;
	}

	this->rear->next = temp;
	this->rear = temp;
}


Node* Queue::deQueue()
{
	if (this->front == NULL)
		return NULL;

	Node* temp = this->front;
	this->front = this->front->next;

	if (this->front == NULL)
		this->rear = NULL;
	return temp;
}

#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack()
{
	top = -1;
}

void Stack::push(int data)
{
	if (!isFull())
		arr[++top] = data;
	else
		throw "Overflow.";
}

int Stack::pop()
{
	if (!isEmpty())
		return arr[top--];
	else
		throw "underflow";
}

int Stack::top()
{
	if (!isEmpty())
		return arr[top];
	else
		throw "underflow";
}

bool Stack::isFull()
{
	return top == size - 1;
}

bool Stack::isEmpty()
{
	return top == -1;
}
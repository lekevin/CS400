//202000921_stack.cpp


#include <iostream>

class MyStack {
	int arr[10] = { 0 };
	int _top;
public:
	MyStack() : _top{ 0 } {}

	bool isFull() { return _top >= 10; }
	bool isEmpty() { return _top == 0; }

	void push(int num) {
		if (isFull()) {
			std::cerr << "Stack is full. Cannot push more. \n";
			exit(1);
		}

		arr[_top] = num;
		_top++;
	}

	int pop() {
		if (isEmpty()) {
			std::cerr << "Stack is empty. Cannot pop more. \n";
			exit(1);
		}

		int temp = arr[_top - 1];
		_top--;
		return temp;
	}
	
	int top() {
		if (isEmpty()) {
			std::cerr << "Stack is empty. Cannot pop more. \n";
			exit(1);
		}
		return arr[_top - 1];
	}

	unsigned size() {
		return _top;
	}


};





int main()
{
	//convert a decimal number into binary

	int num = 500;
	MyStack mst;


	while (num != 0) {
		mst.push(num % 2);
		num /= 2;
	}

	while (!mst.isEmpty()) {
		std::cout << mst.pop() << " ";
	}
}

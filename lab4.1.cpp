#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {

private:
    vector<T> elements; //elements
public:
    Stack() {};
    ~Stack() {};
    void push(T const& uElement); //push element
    void pop();     //remove last element
    T top() const; //return last element

};

template <typename T>
void Stack<T>::push(T const& uElement) {
    elements.push_back(uElement); //append the element
}

template <typename T>
void Stack<T>::pop() {
    //Normally you would do a check if the vector is not empty. Avoiding for simplicity
    elements.pop_back(); //remove last element
}

template <typename T>
T Stack<T>::top() const {
    //Normally you would do a check if the vector is not empty. Avoiding for simplicity
    return elements.back();     //return copy of last element
}


int main()
{
    //create a stack of int type
    Stack<int> myIntStack;

    //append an integer to the container
    myIntStack.push(2);

    //create a stack of float type
    Stack<float> myFloatStack;

    //append a float to the container
    myFloatStack.push(4.2);

    //cout<<myIntStack.pop();
    //cout<<myIntStack.pop();
    int item = myIntStack.top(); //getting the item on stop of stack
    cout << item << endl;

    float a = myFloatStack.top(); //getting the item on stop of stack
    cout << a << endl;


    return 0;
}

//Here we, created 2 stacks on int and float and checked the item on top after pushing it.
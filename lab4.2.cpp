#include <iostream>
using namespace std;

template <typename T>
class stack{
public:
stack();
void push(T);
void pop(T &);
bool isEmpty(void);

private:
struct node{
node(){ next = NULL; }
T data;
node* next;
}*top;

};

template <typename T>
stack<T>::stack(){
top = NULL;
}

template <typename T>
void stack<T>::push(T x){
//(insert at head (top))
node* newNode = new node;
newNode->data = x;

if (top != NULL){
   newNode->next = top;
   top = newNode;
}
else{
   newNode->next = NULL;
   top = newNode;
}

}

template <typename T>
void stack<T>::pop(T &x){
if (isEmpty()){
cout << "Stack is Empty" << endl;
}
else{
x = top->data;
node* temp = top;
top = top->next;
delete temp;
temp = NULL;
}
}


template <typename T>
bool stack<T>::isEmpty(void){
return top == NULL;
}



int main(){
  
stack<char> obj;
int i;
  
for (i = 'A'; i<='E'; i++){
cout << "Pushing " << char(i) << endl;
obj.push(i);
}

cout << "Popping..." << endl;
char x;
for (i = 1; i<=5; i++){
obj.pop(x);
cout << x << endl;
}

for (i = 'A'; i<='E'; i++){
cout << "Pushing " << char(i) << endl;
obj.push(i);
}

cout << "Popping..." << endl;

for (i = 1; i<=5; i++){
obj.pop(x);
cout << x << endl;
}
return 0;
}